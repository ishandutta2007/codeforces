#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

struct Query {
    int t = 0;
    int i = 0;
    int x = 0;
};

vector<int> slow(int n, vector<int> b, int q, vector<Query> queries) {
    vector<int> res;
    for (auto query : queries) {
        if (query.t == 1) {
            b[query.i] = query.x;
        } else {
            set<int> Q;
            for (int x = 1; x <= n; x++)
                Q.insert(x);
            int last = -1;
            for (int i = n; i >= query.i; i--) {
                int lt = i - 1 - b[i];
                auto it = Q.begin();
                advance(it, lt);
                last = *it;
                Q.erase(it);
            }
            res.push_back(last);
        }
    }
    return res;
}

struct Ord {
    int n = 0;
    set<int> q;

    Ord() = default;

    Ord(int nn) {
        n = nn;
    }

    void insert(int x) {
        q.insert(x);
    }

    int query(int x) {
        int pos = 0;
        for (auto y : q) {
            if (y == x)
                return pos + 1;
            pos++;
        }
        return -1;
    }
};

struct Processor {
    int n = 0; // [0, n)
    vector<int> a;

    Processor() = default;

    Processor(int nn) {
        n = nn;
        a.assign(n + 1, 0);
    }

    void increase(int i, int x) {
        i++;
        for (int cur = i; cur <= n; cur += cur & -cur)
            a[cur] += x;
    }

    int descent(int lb) {
        int pos = 0;
        for (int pw = 1 << 19; pw > 0; pw >>= 1) {
            if (pos + pw <= n && a[pos + pw] < lb) {
                lb -= a[pos + pw];
                pos += pw;
            }
        }
        return pos;
    }
};

vector<int> fast(int n, vector<int> b, int q, vector<Query> queries) {
    b.erase(b.begin());
    for (int i = 0; i < n; i++) {
        b[i] = i - b[i];
    }
    //    int k = 0; while (k * k <= n) k++; k++;
    int k = 2 + sqrt(0.2 * n);
    Processor proc(n);
    vector<vector<int>> vals((n - 1) / k + 1);
    auto build_block = [&](int j) {
        int l = j * k;
        int r = min(n, l + k);
        if (vals[j].empty())
            vals[j].resize(r - l);
        for (int i = l; i < r; i++) {
            int sep = proc.descent(b[i]);
            proc.increase(sep, +1);
            vals[j][i - l] = sep;
        }
        sort(vals[j].begin(), vals[j].end());
        for (auto x : vals[j])
            proc.increase(x, -1);
    };
    {
        vector<int> Q;
        for (int x = 1; x < n; x++)
            proc.increase(x, +1);
        for (int j = 0; j < (int) vals.size(); j++) {
            build_block(j);
        }
    }
    vector<int> res;
    for (auto query : queries) {
        query.i--;
        if (query.t == 1) {
            query.x = query.i - query.x;
            b[query.i] = query.x;
        }
        int bid = query.i / k;
        if (query.t == 1) {
            build_block(bid);
        } else {
            int cur = b[query.i];
            for (int i = query.i + 1; i / k == bid && i < n; i++) {
                if (cur >= b[i])
                    cur++;
            }
            for (int j = bid + 1; j < (int) vals.size(); j++) {
                // val[x] = int(x > 0) + #{elem in vals[j]: elem <= x}
                // val[x] >= cur
                // x -> min
                cur += int(upper_bound(vals[j].begin(), vals[j].end(), cur) - vals[j].begin());
            }
            res.push_back(cur + 1);
        }
    }
    return res;
}

void test() {
    mt19937 rnd(42);
    const int MAXN = 100;
    const int MAXQ = 100;
    while (1) {
        int n = rnd() % MAXN + 1;
        vector<int> b(n + 1);
        for (int i = 1; i <= n; i++)
            b[i] = rnd() % i;
        int q = rnd() % MAXQ + 1;
        vector<Query> queries(q);
        for (auto& query : queries) {
            query.t = rnd() % 2 + 1;
            query.i = rnd() % n + 1;
            if (query.t == 1)
                query.x = rnd() % query.i;
        }
        cout << n << "\n";
        for (int i = 1; i <= n; i++)
            cout << b[i] << " ";
        cout << "\n";
        cout << q << "\n";
        for (auto query : queries) {
            cout << query.t << " " << query.i << " ";
            if (query.t == 1)
                cout << query.x << " ";
            cout << "\n";
        }
        cout.flush();
        vector<int> fs = fast(n, b, q, queries);
        vector<int> sl = slow(n, b, q, queries);
        if (fs == sl) {
            cout << "OK( "; for (auto x : fs) cout << x << " "; cout << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = "; for (auto x : sl) cout << x << " "; cout << "\n";
            cout << "fnd = "; for (auto x : fs) cout << x << " "; cout << "\n";
            break;
        }
    }
}

void work() {
    int n;
    cin >> n;
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    int q;
    cin >> q;
    vector<Query> queries(q);
    for (auto& query : queries) {
        cin >> query.t >> query.i;
        if (query.t == 1)
            cin >> query.x;
    }
    vector<int> res = fast(n, b, q, queries);
    for (auto x : res)
        cout << x << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    work();
//    test();

    return 0;
}