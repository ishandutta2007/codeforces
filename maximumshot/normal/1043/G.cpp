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

struct RangeTree {
    int n = 0; // [0, n)
    vector<int> t;

    RangeTree() = default;

    RangeTree(int nn): n(nn) {
        t.resize(4 * n, inf);
    }

    void upd(int v, int x) {
        t[v] = min(t[v], x);
    }

    void push(int v) {
        upd(v << 1, t[v]);
        upd(v << 1 | 1, t[v]);
    }

    void update(int v, int tl, int tr, int l, int r, int x) {
        if (l <= tl && tr <= r) {
            upd(v, x);
        } else {
            int tm = (tl + tr) >> 1;
            push(v);
            if (l <= tm)
                update(v << 1, tl, tm, l, r, x);
            if (r > tm)
                update(v << 1 | 1, tm + 1, tr, l, r, x);
        }
    }

    void update(int l, int r, int x) {
        update(1, 0, n - 1, l, r, x);
    }

    int get(int v, int tl, int tr, int pos) {
        if (tl == tr)
            return t[v];
        else {
            int tm = (tl + tr) >> 1;
            push(v);
            return pos <= tm ?
                get(v << 1, tl, tm, pos) :
                get(v << 1 | 1, tm + 1, tr, pos);
        }
    }

    int get(int pos) {
        return get(1, 0, n - 1, pos);
    }
};

struct RMQ {
    vector<int> a; // [0, n)
    int n, LOG;
    vector<int> _log;
    vector<vector<pii>> rmq;

    RMQ() = default;

    RMQ(const vector<int>& aa) {
        a = aa;
        n = (int) a.size();
        LOG = 0;
        while ((1 << LOG) <= n) LOG++;
        _log.resize(n + 1);
        for (int i = 2; i <= n; i++) {
            _log[i] = _log[i - 1] + 1;
            if ((1 << _log[i]) > i) _log[i]--;
        }
        rmq.resize(LOG, vector<pii>(n));
        for (int i = 0; i < n; i++) {
            rmq[0][i] = {a[i], i};
        }
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                rmq[j][i] = min(rmq[j - 1][i], rmq[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    pii get_min(int l, int r) const {
        if (l > r)
            return make_pair(inf, -1);
        int lg = _log[r - l + 1];
        return min(rmq[lg][l], rmq[lg][r - (1 << lg) + 1]);
    }
};

const int LOG = 21;
struct SuffixArray {
    vector< int > p, c[LOG];
    SuffixArray() = default;
    SuffixArray(string s) {
        s.push_back(0);
        int n = (int)s.size();
        vector<int> pn, cn, cnt;
        p.resize(n);
        for(int i = 0;i < LOG;i++) c[i].resize(n);
        pn.resize(n), cn.resize(n), cnt.assign(300, 0);
        for (int i = 0; i < n; i++) cnt[s[i]]++;
        for (int i = 1; i < (int) cnt.size(); i++) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--) p[--cnt[s[i]]] = i;
        for (int i = 1; i < n; i++) {
            c[0][p[i]] = c[0][p[i - 1]];
            if(s[p[i]] != s[p[i - 1]]) c[0][p[i]]++;}
        for (int lg = 0, k = 1; k < n; k <<= 1, lg++) {
            for (int i = 0; i < n; i++)
                if((pn[i] = p[i] - k) < 0) pn[i] += n;
            cnt.assign(n, 0);
            for (int i = 0; i < n; i++) cnt[c[lg][pn[i]]]++;
            for (int i = 1; i < (int) cnt.size(); i++) cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; i--) p[--cnt[c[lg][pn[i]]]] = pn[i];
            for (int l1, r1, l2, r2, i = 1; i < n; i++) {
                cn[p[i]] = cn[p[i - 1]];
                l1 = p[i - 1], r1 = (l1 + k) % n;
                l2 = p[i], r2 = (l2 + k) % n;
                if(c[lg][l1] != c[lg][l2] || c[lg][r1] != c[lg][r2]) cn[p[i]]++;}
            c[lg + 1] = cn;
        }p.erase(p.begin(), p.begin() + 1);}
    int get_lcp(int i, int j) {
        int res = 0; for (int lg = LOG - 1; lg >= 0; lg--) {
            if (i + (1 << lg) > (int) p.size() || j + (1 << lg) > (int) p.size()) continue;
            if (c[lg][i] == c[lg][j])
                i += (1 << lg), j += (1 << lg), res += (1 << lg);}return res;}};

struct Tandem {
    int l, r, k; // [l, l + 2 * k), [l + 1, l + 1 + 2 * k), ..., [r, r + 2 * k)
};

vector<int> get_z(const string& s) {
    int n = (int) s.size(); vector<int> z(n);
    for (int l = 0, r = -1, i = 1; i < n; i++) {
        z[i] = i <= r ? min(r - i, z[i - l]) : 0;
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] > r) l = i, r = i + z[i];} return z;}

const int SIZE = (2e5 + 5) * 30; // (n)*log(n)
const int MAXL = (2e5 + 5) * 4; // (n)*4, 4 = big const
Tandem tds[SIZE], hlp[MAXL];
int tsz;
void rec(const string& s, int L, int R) {
    if (R - L + 1 <= 1) return;
    int M = (L + R) / 2;
    rec(s, L, M); rec(s, M + 1, R);
    int nu = M - L + 1, nv = R - M;
    string vu = s.substr(M + 1, nv) + "#" + s.substr(L, nu);
    string urvr = vu; reverse(urvr.begin(), urvr.end());
    vector<int> z1 = get_z(urvr), z2 = get_z(vu);
    for (int x = L; x <= R; x++) {
        if (x <= M) {
            int k = M + 1 - x, k1 = L < x ? z1[nu - x + L] : 0;
            int k2 = z2[nv + 1 + x - L], lsh = max(0, k - k2), rsh = min(k1, k - 1);
            if (lsh <= rsh) tds[tsz++] = {x - rsh, x - lsh, k};
        } else {
            int k = x - M, k1 = x < R ? z2[x - M] : 0;
            int k2 = z1[nu + nv - x + M + 1], lsh = max(1, k - k1), rsh = min(k2, k - 1);
            if (lsh <= rsh) tds[tsz++] = {x - rsh + 1 - k, x - lsh + 1 - k, k};}}}
void compress() { // O(n*log(n)*log(n)) can be replace with count sort (O(n*log(n))) BE careful with ML !!!
    // O(n*log(n)) --> O(n)
    sort(tds, tds + tsz, [](const Tandem& t1, const Tandem& t2) {
        return t1.k < t2.k || (t1.k == t2.k && t1.l < t2.l);});
    int hlp_sz = 0; for (int i = 0; i < tsz; i++) {
        int j = i; while (j + 1 < tsz && tds[i].k == tds[j + 1].k && tds[j].r + 1 == tds[j + 1].l) j++;
        hlp[hlp_sz++] = {tds[i].l, tds[j].r, tds[j].k}; i = j;}
    memcpy(tds, hlp, sizeof(Tandem) * hlp_sz); tsz = hlp_sz;}
void main_lorentz(const string &s) {
    // n = 10^6  time = 1.8 sec MEM = nlog(n) * 12 bytes
    int n = (int) s.size(); tsz = 0; rec(s, 0, n - 1); compress();}

RMQ rmq;
vector<int> pos;

inline int get_lcp(int i, int j) {
    int lx = pos[i], rx = pos[j];
    if (lx > rx) swap(lx, rx);
    return rmq.get_min(lx, rx - 1).first;
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> poses[26];
    for (int i = 0; i < n; i++) {
        int x = s[i] - 'a';
        poses[x].push_back(i);
    }

    main_lorentz(s);

    SuffixArray sa(s);
    vector<int> p = sa.p, _lcp(n - 1);

    pos.assign(n, 0);

    for (int i = 0; i < n; i++)
        pos[p[i]] = i;
    for (int i = 0; i + 1 < n; i++)
        _lcp[i] = sa.get_lcp(p[i], p[i + 1]);

    rmq = RMQ(_lcp);

    int q;
    cin >> q;

    vector<vector<int>> ds(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 2 * i; j <= n; j += i)
            ds[j].push_back(i);
    }

    RangeTree for_l(n), for_r(n);

    for (int i = 0; i < tsz; i++) {
        for_l.update(tds[i].l, tds[i].r, 2 * tds[i].k);
        for_r.update(
            tds[i].l + 2 * tds[i].k - 1,
            tds[i].r + 2 * tds[i].k - 1,
            2 * tds[i].k
        );
    }

    int B = 0;
    while (B * B <= n) B++;

    vector<int> best_start(n);
    for (int l = 0; l < n; l++)
        best_start[l] = l + for_l.get(l) - 1;

    RMQ rmq_start(best_start);

    for (int iter = 0; iter < q; iter++) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        if (r - l + 1 <= 26) {
            vector<int> used(26);
            int ok = 1;
            for (int i = l; i <= r; i++) {
                if (used[s[i] - 'a']) {
                    ok = 0;
                    break;
                } else used[s[i] - 'a'] = 1;
            }
            if (ok) {
                cout << "-1\n";
                continue;
            }
        }

        { // check 1
            int ok = 0;
            for (int period : ds[r - l + 1]) {
                int tmp = get_lcp(l, l + period);
                if (get_lcp(l, l + period) >= r - l + 1 - period) {
                    ok = 1;
                    break;
                }
            }
            if (ok) {
                cout << "1\n";
                continue;
            }
        }

        { // check 2
            if (for_l.get(l) <= r - l + 1) { // aab
                cout << "2\n";
                continue;
            }
            if (for_r.get(r) <= r - l + 1) { // baa
                cout << "2\n";
                continue;
            }
            // aba
            int ok = 0;
            for (int b = 1; b <= B && 2 * b <= r - l + 1; b++) {
                if (get_lcp(l, r - b + 1) >= b) {
                    ok = 1;
                    break;
                }
            }
            if (ok) {
                cout << "2\n";
                continue;
            }
            int pl = max(0, pos[l] - B);
            int pr = min(n - 1, pos[l] + B);
            for (int pi = pl; pi <= pr; pi++) {
                int j = p[pi];
                if (j <= l || j > r)
                    continue;
                int b = r - j + 1;
                if (2 * b > r - l + 1)
                    continue;
                if (get_lcp(l, r - b + 1) >= b) {
                    ok = 1;
                    break;
                }
            }
            if (ok) {
                cout << "2\n";
                continue;
            }
        }

        { // check 3
            const auto& cl = poses[s[l] - 'a'];
            auto it = upper_bound(cl.begin(), cl.end(), l);
            if (it != cl.end() && *it <= r) {
                cout << "3\n";
                continue;
            }
            const auto& cr = poses[s[r] - 'a'];
            it = lower_bound(cr.begin(), cr.end(), r);
            if (it != cr.begin()) {
                it--;
                if (*it >= l) {
                    cout << "3\n";
                    continue;
                }
            }
            if (rmq_start.get_min(l, r).first <= r) {
                cout << "3\n";
                continue;
            }
        }

        cout << "4\n";
    }

    return 0;
}