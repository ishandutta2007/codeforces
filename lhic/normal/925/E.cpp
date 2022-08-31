#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using ll = int64_t;
using ld = long double;
using ull = uint64_t;
using namespace std;
using namespace __gnu_pbds;

const int INF = (1 << 25);
const int SEMIINF = (1 << 20);

const int MAXN = 100228;

namespace Mrg {
    static int mrg1[MAXN];
    static int mrg2[MAXN];
    int m1c;
    int m2c;
}

namespace Sqrt {
    int a[MAXN];

    void init() {
        a[0] = 0;
        for (int i = 1; i < MAXN; ++i) {
            a[i] = a[i - 1];
            while (a[i] * a[i] <= i) {
                ++a[i];
            }
        }
    }
};


int tilted = 0;

struct Block {
    int n;
    int mdf;
    int p;
    vector<int> elems;
    vector<int> sorted;
    vector<pair<int, int>> sp;


    Block(int n) : n(n), mdf(0), p(0), elems(n), sorted(n), sp(n + 2) {
    }

    auto getCmp() const {
        return [&](int x, int y) {
            return elems[x] < elems[y];
        };
    };

    void buildsp() {
        auto it = sp.begin();
        *it = { -MAXN, 0 };

        int vl = -MAXN, cn = 0;
        
        auto push = [&]() {
            if (cn) {
                *(++it) = { vl, cn };
            }
        };

        for (int x : sorted) {
            if (elems[x] != vl) {
                push();
                cn = 0;
                vl = elems[x];
            }

            ++cn;
        }

        push();
        *(++it) = { MAXN, 0 };
        p = 1;
        while (sp[p].first < 0) {
            ++p;
        }
    }

    void build() {
        iota(sorted.begin(), sorted.end(), 0);
        sort(sorted.begin(), sorted.end(), getCmp());
        buildsp();
    }

    void apply() {
        for (int& elem : elems) {
            elem += mdf;
        }

        mdf = 0;
    }

    template <int x>
    void modify(int cn) {
        apply();

        for (int i = 0; i < cn; ++i) {
            if constexpr (x != 1) {
                tilted += (elems[i] == 0);
            } else {
                tilted -= (elems[i] == -1);
            }

            elems[i] += x;
        }

        mrg([&](int id) {
            return id < cn;
        });
    }

    template <typename Pred>
    void mrg(Pred&& pred) {
        using namespace Mrg;
        m1c = m2c = 0;

        for (int id : sorted) {
            if (pred(id)) {
                mrg1[m1c++] = id;
            } else {
                mrg2[m2c++] = id;
            }
        }

        merge(mrg1, mrg1 + m1c, mrg2, mrg2 + m2c, sorted.begin(), getCmp());
        buildsp();
    }

    template <int value>
    void modifySingle(int index) {
        apply();
        if constexpr (value > 0) {
            tilted -= isTilted(index);
        }

        elems[index] += value;

        if constexpr (value < 0) {
            tilted += isTilted(index);
        }

        mrg([&](int id) {
            return id == index;
        });
    }

    template <int x>
    void modifyfull() {
        mdf += x;

        if constexpr(x == 1) {
            if (sp[p - 1].first + mdf == 0) {
                tilted -= sp[--p].second;
            }
        } else {
            if (sp[p].first + mdf == -1) {
                tilted += sp[p++].second;
            } 
        }
    }

    int& operator[](int index) {
        return elems[index];
    }

    bool isTilted(int index) {
        return elems[index] + mdf < 0;
    }
};

struct Path {
    vector<Block> blocks;
    int blockSize;
    int blockCount;

    Path() = default;

    explicit Path(int n): blockSize(Sqrt::a[n]), blockCount((n - 1) / blockSize + 1) {
        blocks.reserve(blockCount);
        int cn = n;

        for (int i = 0; i < blockCount; ++i) {
            int cs = min(blockSize, cn);
            cn -= cs;
            blocks.emplace_back(cs);
        }

        assert(cn == 0);
    }

    int& operator[](int index) {
        return blocks[index / blockSize][index % blockSize];
    }

    template <int x> 
    void modify(int cn) {
        int lastBlock = cn / blockSize;
        int cnt = cn % blockSize;
        if (cnt) {
            blocks[lastBlock].modify<x>(cnt);
        }

        for (int i = 0; i < lastBlock; ++i) {
            blocks[i].modifyfull<x>();
        }
    }

    bool isTilted(int index) {
        return blocks[index / blockSize].isTilted(index % blockSize);
    }

    void build() {
        for (auto& block : blocks) {
            block.build();
        }
    }

    template <int value>
    void modifySingle(int index) {
        blocks[index / blockSize].modifySingle<value>(index % blockSize);
    }
};

vector<int> e[MAXN];
int subtreeSize[MAXN];
int pathid[MAXN];
int pathind[MAXN];
int pathSize[MAXN];
Path paths[MAXN];
int parent[MAXN];

void dfsSize(int v) {
    subtreeSize[v] = 1;
    for (int u : e[v]) {
        dfsSize(u);
        subtreeSize[v] += subtreeSize[u];
    }
}

void dfsHld(int v, int pid, int pind) {
    pathid[v] = pid;
    pathind[v] = pind;
    pathSize[pid] = pind + 1;
    if (e[v].empty()) {
        return;
    }

    int mx = e[v][0];
    for (int u : e[v]) {
        if (subtreeSize[u] > subtreeSize[mx]) {
            mx = u;
        }
    }

    dfsHld(mx, pid, pind + 1);
    for (int u : e[v]) {
        if (u != mx) {
            dfsHld(u, u, 0);
        }
    }
}

decltype(auto) pth(int v) {
    return paths[pathid[v]];
}

template <int x> 
void modify(int v) {
    pth(v).modifySingle<x * -SEMIINF>(pathind[v]);
    while (v) {
        pth(v).modify<x>(pathind[v] + 1);
        v = parent[pathid[v]];
    }
}

int main() {
#ifdef BZ
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);
    Sqrt::init();
    
    int n, q;
    cin >> n >> q;
     
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        parent[i] = p;
        e[parent[i]].push_back(i);
    }

    dfsSize(1);
    dfsHld(1, 1, 0);

    for (int i = 1; i <= n; ++i) {
        if (pathSize[i]) {
            paths[i] = Path(pathSize[i]);
        }
    }

    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        pth(i)[pathind[i]] = t;
    }

    for (int i = 1; i <= n; ++i) {
        if (pathSize[i]) {
            paths[i].build();
        }
    }

    while (q--) {
        int v;
        cin >> v;
        if (v > 0) {
            modify<-1>(v);
        } else {
            modify<1>(-v);
        }

        cout << tilted << " ";
    }

    cout << "\n";
}