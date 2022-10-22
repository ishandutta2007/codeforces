#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

bool check(string a, string b) {
    int n = (int) a.size();
    int l = 0, r = 0;
    while (l < n && a[l] == b[l]) l++;
    while (r < n && a[n - 1 - r] == b[n - 1 - r]) r++;
    if (l + r >= n) return true;
    int ql = l, qr = n - r - 1;
    int oka = 1, okb = 1;
    for (int i = ql; i < qr; i++) {
        if (a[i] < a[i + 1]) oka = 0;
        if (b[i] < b[i + 1]) okb = 0;
    }
    return oka || okb;
}

ll solveNNS(vector<string> a) {
    int n = (int) a.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int cost = 2;
            if (check(a[i], a[j]))
                cost = 1;
            res += cost;
        }
    }
    return res;
}

const int A = 26;
struct Trie {
    struct Node {
        vector<int> nxt = vector<int>(A, -1);
        int par = -1;
        int tin = 0;
        int tout = 0;
    };
    vector<Node> t = {Node()};
    int timer = 0;

    int add_string(const string& s) {
        int v = 0;
        for (char c : s) {
            c -= 'a';
            if (t[v].nxt[c] == -1) {
                t[v].nxt[c] = (int) t.size();
                t.emplace_back();
                t.back().par = v;
            }
            v = t[v].nxt[c];
        }
        return v;
    }

    int get(const string& s) {
        int v = 0;
        for (char c : s) {
            c -= 'a';
            v = t[v].nxt[c];
        }
        return v;
    }

    void dfs(int v) {
        t[v].tin = timer++;
        for (int c = 0; c < A; c++) {
            int to = t[v].nxt[c];
            if (to == -1)
                continue;
            dfs(to);
        }
        t[v].tout = timer++;
    }

    void build() {
        dfs(0);
    }
};

struct pt {
    int x = 0;
    int y = 0;
};

struct Node {
    Node* l = nullptr;
    Node* r = nullptr;
    int s = 0;

    Node(int value) {
        s = value;
    }

    Node(Node* l_, Node* r_): l(l_), r(r_) {
        s = (l ? l->s : 0) + (r ? r->s : 0);
    }
};

Node* add(Node* v, int tl, int tr, int pos) {
    if (tl == tr) {
        return new Node((v ? v->s : 0) + 1);
    } else {
        int tm = (tl + tr) >> 1;
        if (pos <= tm)
            return new Node(add(v ? v->l : nullptr, tl, tm, pos), v ? v->r : nullptr);
        else
            return new Node(v ? v->l : nullptr, add(v ? v->r : nullptr, tm + 1, tr, pos));
    }
}

int get(Node* v, int tl, int tr, int l, int r) {
    if (l > r || !v) return 0;
    if (l <= tl && tr <= r) {
        return v->s;
    } else {
        int tm = (tl + tr) >> 1, res = 0;
        if (l <= tm) res += get(v->l, tl, tm, l, r);
        if (r > tm) res += get(v->r, tm + 1, tr, l, r);
        return res;
    }
}

ll solveNSS(vector<string> a) {
    sort(a.begin(), a.end());
    for (int i = 0; i + 1 < (int) a.size(); i++)
        assert(a[i] != a[i + 1]);
    if (a.empty()) return 0;
    int n = (int) a.size();
    int k = (int) a[0].size();

    ll res = 1ll * n * (n - 1);
    ll cnt = 0;

    Trie pref, suff;
    vector<string> b = a;
    for (int i = 0; i < n; i++) {
        pref.add_string(a[i]);
        reverse(b[i].begin(), b[i].end());
        suff.add_string(b[i]);
    }

    pref.build();
    suff.build();

    vector<pt> ps(n);
    for (int i = 0; i < n; i++) {
        int u = pref.get(a[i]);
        int v = suff.get(b[i]);
        ps[i].x = pref.t[u].tin;
        ps[i].y = suff.t[v].tin;
        if (i > 0) assert(ps[i - 1].x <= ps[i].x);
    }

    vector<tuple<int, int, int, int, int>> recs;

    int mx = 2 * (int) suff.t.size() + 5;

    vector<Node*> roots(n);
    for (int i = 0; i < n; i++) {
        Node* r = i > 0 ? roots[i - 1] : nullptr;
        roots[i] = add(r, 0, mx, ps[i].y);
    }

    for (int i = 0; i < n; i++) {
        int pv = 0, sv = suff.get(b[i]);
//        cout << i << " : \n";
        int last_lx = 0;
        int last_rx = 0;
        for (int r = -1, l = 0; l + 1 < k; pv = pref.t[pv].nxt[a[i][l] - 'a'], l++) {
            while (r < l) {
                sv = suff.t[sv].par;
                r++;
            }
            while (r + 1 < k && a[i][r] >= a[i][r + 1]) {
                sv = suff.t[sv].par;
                r++;
            }
            {
                int npv = pref.t[pv].nxt[a[i][l] - 'a'];
                int lx = pref.t[pv].tin;
                int rx = pref.t[npv].tin;

                assert(last_lx <= lx); last_lx = lx;
                assert(last_rx <= rx); last_rx = rx;

                int ly = suff.t[sv].tin;
                int ry = suff.t[sv].tout;
                int from = 0, to;

                {
                    int bl = 0, br = i + 1, bm;
                    while (br - bl > 1) {
                        bm = (bl + br) >> 1;
                        if (ps[bm].x <= lx) bl = bm;
                        else br = bm;
                    }
                    from = bl + 1;
                    while (from > 0 && ps[from - 1].x > lx) from--;
                }

                {
                    int bl = -1, br = i, bm;
                    while (br - bl > 1) {
                        bm = (bl + br) >> 1;
                        if (ps[bm].x >= rx) br = bm;
                        else bl = bm;
                    }
                    to = max(0, br - 1);
                    while (to < i && ps[to].x < rx) to++;
                }

                if (from < to)
                    cnt += get(roots[to - 1], 0, mx, ly + 1, ry - 1) -
                           get(from > 0 ? roots[from - 1] : nullptr, 0, mx, ly + 1, ry - 1);
//                for (int j = from; j < to; j++) {
//                    if (ly < ps[j].y && ps[j].y < ry)
//                        cnt++;
//                }
            }
        }
    }

//    cout << "cnt = " << cnt << "\n";

    res -= cnt;
    return res;
}

const int SQRT = (int) sqrt(2e5);

ll fast(int n, vector<string> a) {
    vector<string> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
        sort(b[i].begin(), b[i].end());
    }
    vector<int> perm(n);
    for (int i = 0; i < n; i++)
        perm[i] = i;
    sort(perm.begin(), perm.end(), [&](int i, int j) {
        return b[i] < b[j];
    });
    ll add = 0, res = 0;
    for (int it = 0; it < n; it++) {
        int jit = it;
        vector<string> group;
        while (jit < n && b[perm[it]] == b[perm[jit]]) {
            group.push_back(a[perm[jit]]);
            jit++;
        }
        jit--;
        add += 1ll * (int) group.size() * (n - (int) group.size());
//        res += n < SQRT ? solveNNS(group) : solveNSS(group);
        res += solveNSS(group);
        it = jit;
    }
    assert(add % 2 == 0);
    res += 1337ll * add / 2;
    return res;
}

ll slow(int n, vector<string> a) {
    sort(a.begin(), a.end());
    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {

            {
                string aa = a[i], bb = a[j];
                sort(aa.begin(), aa.end());
                sort(bb.begin(), bb.end());
                if (aa != bb) {
                    res += 1337;
                    continue;
                }
            }

            int l = 0, r = 0;
            int sz = (int) a[i].size();
            while (l < sz && a[i][l] == a[j][l]) l++;
            while (r < sz && a[i][sz - 1 - r] == a[j][sz - 1 - r]) r++;
            assert(l + r < sz);
            int ql = l, qr = sz - r - 1;
            int ok = 1;
            for (int q = ql; q < qr; q++) {
                if (a[i][q] < a[i][q + 1]) ok = 0;
            }
            if (ok) res++;
            else res += 2;
        }
    }
    return res;
}

void work() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (char& c : a[i])
            c = 25 - (c - 'a') + 'a';
    }
    ll res = fast(n, a);
    cout << res << "\n";
}

string gen_string(mt19937& rnd, int len, const int MAXC) {
    string res(len, '?');
    for (char& c : res)
        c = rnd() % MAXC + 'a';
    return res;
}

void test() {
    mt19937 rnd(42);
    const int MAXN = 10;
    const int MAXL = 5;
    const int MAXC = 3;
    while (1) {
        int n = rnd() % MAXN + 1;
        int m = rnd() % MAXL + 1;
        vector<string> a(n);
        for (int i = 0; i < n; i++) {
            if (i == 0 || rnd() % 2)
                a[i] = gen_string(rnd, m, MAXC);
            else {
                a[i] = a[rnd() % i];
                shuffle(a[i].begin(), a[i].end(), rnd);
            }
        }
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        n = (int) a.size();
        shuffle(a.begin(), a.end(), rnd);
        ll fs = fast(n, a);
        ll sl = slow(n, a);
        if (fs == sl) {
            cout << "OK(" << fs << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = " << sl << "\n";
            cout << "fnd = " << fs << "\n";
            cout << n << "\n";
            for (int i = 0; i < n; i++)
                cout << a[i] << "\n";
            break;
        }
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();

    return 0;
}