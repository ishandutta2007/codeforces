#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int mod = 998244353;

inline int _sum(int a, int b) {
    return a + b < mod ? a + b : a + b - mod;
}

inline int _mul(int a, int b) {
    return (1ll * a * b) % mod;
}

inline int _sub(int a, int b) {
    return a >= b ? a - b : a - b + mod;
}

inline void _inc(int &x, int y) {
    if ((x += y) >= mod) {
        x -= mod;
    }
}

inline void _dec(int &x, int y) {
    if ((x -= y) < 0) {
        x += mod;
    }
}

inline int _binpow(int x, int pw) {
    int res = 1;
    int tmp = x;
    while (pw > 0) {
        if (pw & 1) {
            res = _mul(res, tmp);
        }
        tmp = _mul(tmp, tmp);
        pw >>= 1;
    }
    return res;
}

inline int _div(int a, int b) {
    return _mul(a, _binpow(b, mod - 2));
}

const int P = 1e6 + 3;
const int RP = _binpow(P, mod - 2);

const int N = 1e5 + 5;
const int K = 320;

int pw_p[N];
int pw_rp[N];

void precalc() {
    pw_p[0] = 1;
    pw_rp[0] = 1;
    for (int i = 1; i < N; i++) {
        pw_p[i] = _mul(pw_p[i - 1], P);
        pw_rp[i] = _mul(pw_rp[i - 1], RP);
    }
}

struct Stack {
    vector<int> hashes = {0};
    int active = 0;

    Stack() = default;

    void push(int x) {
        x = (x % mod + mod) % mod;
        hashes.push_back(_sum(x, _mul(hashes.back(), P)));
    }

    int get_hash(int cnt_pop) {
        assert(cnt_pop <= active);
        // h[active] - h[active - pop] * (P ** pop)
        return _sub(hashes[active], _mul(hashes[active - cnt_pop], pw_p[cnt_pop]));
    }

    int get_size() const {
        return (int) hashes.size() - 1;
    }

    bool is_empty() const {
        return get_size() == 0;
    }
};

struct LRStacks {
    Stack l_stack{};
    Stack r_stack{};
};

struct Query {
    int t, x, y;

    void read() {
        cin >> t >> x >> y;
    }
};

int n, k, q;
int s[N];
Query queries[N];
int fast_res[N];

pair<LRStacks, bool> get_stack(int l, int r) {
    l = max(l, 0);
    r = min(r, n - 1);
    assert(l <= r);
    deque<int> dl, dr;
    for (int i = l; i <= r; i++) {
        if (s[i] > 0) {
            dr.push_back(s[i]);
        } else {
            if (dr.empty())
                dl.push_front(-s[i]);
            else {
                if (dr.back() != -s[i])
                    return make_pair(LRStacks(), false);
                else
                    dr.pop_back();
            }
        }
    }
    LRStacks lr{};
    for (int x : dl) lr.l_stack.push(x);
    for (int x : dr) lr.r_stack.push(x);
    return make_pair(lr, true);
}

void read() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    cin >> q;
    for (int i = 0; i < q; i++) {
        queries[i].read();
        fast_res[i] = 1;
        if (queries[i].t == 1)
            queries[i].x--;
        else
            queries[i].x--, queries[i].y--;
    }
}

void fast() {
    vector<pair<LRStacks, bool>> blocks((n - 1) / K + 1);
    for (int i = 0; i < n; i += K) {
        int j = min(n - 1, i + K - 1);
        blocks[i / K] = get_stack(i, j);
    }
    for (int it = 0; it < q; it++) {
        if (queries[it].t == 1) {
            int i = queries[it].x;
            int t = queries[it].y;
            s[i] = t;
            blocks[i / K] = get_stack((i / K) * K, min(n - 1, (i / K) * K + K - 1));
            continue;
        }

        int l = queries[it].x;
        int r = queries[it].y;

        int lb = l / K;
        int rb = r / K;

        if (lb == rb) {
            LRStacks st;
            bool resp;
            tie(st, resp) = get_stack(l, r);
            if (resp && st.l_stack.is_empty() && st.r_stack.is_empty()) {}
            else fast_res[it] = 0;
            continue;
        }

        bool resp;
        LRStacks cur, tmp;

        tie(cur, resp) = get_stack(l, lb * K + K - 1);
        if (!resp || !cur.l_stack.is_empty()) {
            fast_res[it] = 0;
            continue;
        }

        cur.r_stack.active = cur.r_stack.get_size();
        vector<LRStacks*> st;

        if (cur.r_stack.active > 0)
            st.push_back(&cur);

        pair<LRStacks, bool> hlp{};
        for (int jb = lb + 1; jb <= rb; jb++) {
            if (jb == rb)
                hlp = get_stack(rb * K, r);
            auto &pr = jb < rb ? blocks[jb] : hlp;

            if (!pr.second) {
                fast_res[it] = 0;
                break;
            }

            pr.first.r_stack.active = pr.first.r_stack.get_size();
            pr.first.l_stack.active = pr.first.l_stack.get_size();

            auto &cl = pr.first.l_stack;

            while (cl.active > 0) {
                if (st.empty()) {
                    fast_res[it] = 0;
                    break;
                }
                auto &op = *st.back();
                int mn = min(op.r_stack.active, cl.active);
                if (op.r_stack.get_hash(mn) != cl.get_hash(mn)) {
                    fast_res[it] = 0;
                    break;
                }
                op.r_stack.active -= mn;
                cl.active -= mn;
                if (op.r_stack.active == 0)
                    st.pop_back();
            }

            if (!fast_res[it])
                break;

            if (pr.first.r_stack.active > 0)
                st.push_back(&pr.first);
        }

        if (!st.empty())
            fast_res[it] = 0;
    }
}

void work() {
    read();
    fast();
    for (int i = 0; i < q; i++) {
        if (queries[i].t == 2)
            cout << (fast_res[i] ? "Yes" : "No") << "\n";
    }
}

int main() {

    precalc();

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}