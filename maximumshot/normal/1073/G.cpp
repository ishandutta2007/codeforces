#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

const int LOG = 21;
struct SuffixArray {
    string s;
    int n;
    vec< int > p;
    vec< int > c[LOG], ccc;

    SuffixArray():
        n(0)
    { }

    SuffixArray(string ss):
        s(ss)
    {
        s.push_back(0);
        n = (int)s.size();

        vec< int > pn, cn;
        vec< int > cnt;

        p.resize(n);
        for(int i = 0;i < LOG;i++) c[i].resize(n);
        pn.resize(n);
        cn.resize(n);

        cnt.assign(300, 0);

        for(int i = 0;i < n;i++) cnt[s[i]]++;
        for(int i = 1;i < (int)cnt.size();i++) cnt[i] += cnt[i - 1];
        for(int i = n - 1;i >= 0;i--) p[--cnt[s[i]]] = i;

        for(int i = 1;i < n;i++) {
            c[0][p[i]] = c[0][p[i - 1]];
            if(s[p[i]] != s[p[i - 1]]) c[0][p[i]]++;
        }
        ccc = c[0];
        for(int lg = 0, k = 1;k < n;k <<= 1, lg++) {
            for(int i = 0;i < n;i++) {
                if((pn[i] = p[i] - k) < 0) pn[i] += n;
            }
            cnt.assign(n, 0);
            for(int i = 0;i < n;i++) cnt[c[lg][pn[i]]]++;
            for(int i = 1;i < (int)cnt.size();i++) cnt[i] += cnt[i - 1];
            for(int i = n - 1;i >= 0;i--) p[--cnt[c[lg][pn[i]]]] = pn[i];
            for(int l1, r1, l2, r2, i = 1;i < n;i++) {
                cn[p[i]] = cn[p[i - 1]];
                l1 = p[i - 1];
                l2 = p[i];
                if((r1 = l1 + k) >= n) r1 -= n;
                if((r2 = l2 + k) >= n) r2 -= n;
                if(c[lg][l1] != c[lg][l2] || c[lg][r1] != c[lg][r2]) cn[p[i]]++;
            }
            ccc = c[lg + 1] = cn;
        }

        p.erase(p.begin(), p.begin() + 1);
        n--;

//        cout << "sz = " << (int)p.size() << "\n";

//        for(int i : p) {
//            cout << i << "\n";
//            cout << s.substr(i) << "\n";
//        }

//        cout << "sz = " << (int)c.size() << "\n";

//        for(int i : c) {
//            cout << i << "\n";
//        }
    }

    int get_lcp(int i, int j) {
        int res = 0;
        for(int lg = LOG - 1;lg >= 0;lg--) {
            if(i + (1 << lg) > n || j + (1 << lg) > n) continue;
            if(c[lg][i] == c[lg][j]) {
                i += (1 << lg);
                j += (1 << lg);
                res += (1 << lg);
            }
        }
        return res;
    }
};

struct SparseTable {
    int n; // [0 .. n)
    vec< int > a;
    vec< int > rmq[LOG], _log;

    SparseTable(const vec< int > &aa): a(aa)
    {
        n = (int)aa.size();
        for(int i = 0;i < LOG;i++) {
            rmq[i].resize(n, inf);
        }

        _log.resize(n + 1);

        for(int i = 2;i <= n;i++) {
            _log[i] = _log[i - 1] + 1;
            if((1 << _log[i]) > i) _log[i]--;
        }

        rmq[0] = aa;
        for(int j = 1;j < LOG;j++) {
            for(int i = 0;i + (1 << j) - 1 < n;i++) {
                rmq[j][i] = min(
                    rmq[j - 1][i],
                    rmq[j - 1][i + (1 << (j - 1))]
                );
            }
        }
    }

    int get(int l, int r) {
        if(l > r) swap(l, r);
        r--;
        int lg = _log[r - l + 1];
        return min(
            rmq[lg][l],
            rmq[lg][r - (1 << lg) + 1]
        );
    }
};

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);

    int n, q;
    string s;

    cin >> n >> q >> s;

    vec< int > lcp, pos;

    {
        SuffixArray sa(s);
        lcp.resize(n - 1);
        pos.resize(n);
        for(int i = 0;i < n - 1;i++) {
            lcp[i] = sa.get_lcp(sa.p[i], sa.p[i + 1]);
        }
        for(int i = 0;i < n;i++) {
            pos[ sa.p[i] ] = i;
        }
    }

    SparseTable st(lcp);

    for(int k, l, iter = 0;iter < q;iter++) {
        cin >> k >> l;

        vec< int > a(k), b(l);

        for(int &x : a) cin >> x, x--;
        for(int &x : b) cin >> x, x--;

        ll res = 0;

        unordered_set< int > gg;

        for(int x : a) gg.insert(x);
        for(int x : b) {
            if(gg.count(x)) {
                res += n - x;
            }
        }

        for(int &x : a) x = pos[x];
        for(int &x : b) x = pos[x];

        sort(ALL(a));
        sort(ALL(b));

//        for(int xx : a) {
//            for(int yy : b) {
//                if(xx == yy) {
//                    res += n - xx;
//                    continue;
//                }
//                int x = pos[xx];
//                int y = pos[yy];
//                if(x > y) swap(x, y);
//                res += st.get(x, y - 1);
//            }
//        }

//        cout << res << "\n";

        for(int it = 0;it < 2;it++, swap(a, b), swap(k, l)) {
            map< int, int > qq;

            ll cur = 0;

//            cout << "\n-------\n";
            for(int j = l - 1, i = k - 1;i >= 0;i--) {
                if(i + 1 < k) {
                    int x = st.get(a[i], a[i + 1]);
                    while(!qq.empty() && (--qq.end())->first > x) {
                        int vl = (--qq.end())->first;
                        int cn = (--qq.end())->second;
                        cur -= 1ll * vl * cn;
                        qq.erase(--qq.end());
                        qq[x] += cn;
                        cur += 1ll * x * cn;
                    }
                }
                while(j >= 0 && b[j] > a[i]) {
                    int vl = st.get(a[i], b[j]);
                    cur += vl;
                    qq[vl]++;
                    j--;
                }
                res += cur;
//                cout << i << " : " << cur << "\n";
            }
        }

        cout << res << "\n";
    }

    return 0;
}