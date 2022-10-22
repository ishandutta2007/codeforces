// time-limit: 2000
// problem-url: https://codeforces.com/contest/1466/problem/G

// Hallelujah, praise the one who set me free
// Hallelujah, death has lost its grip on me
// You have broken every chain, There's salvation in your name
// Jesus Christ, my living hope
#include <bits/stdc++.h> 
using namespace std;

template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
typedef long double ld;
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<iii> viii;

#ifndef DEBUG
#define cerr if (0) cerr
#endif

#define INF 1000000005
#define LINF 1000000000000000005ll
#define MAXN 100005
#define MOD 1000000007

int n, q;
string s0, t;
ll pw[MAXN], ipw[MAXN];
ll psm[30][MAXN];
int g[30];

vi kmp(string s) {
    vi pi(s.size(), 0);
    REP (i, 1, s.size()) {
        int j = pi[i - 1];
        while (j > 0 && s[j] != s[i]) {
            j = pi[j - 1];
        }
        pi[i] = j + (s[i] == s[j]);
    }
    return pi;
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    pw[0] = 1;
    REP (i, 1, MAXN) {
        pw[i] = pw[i - 1] * 2 % MOD;
    }
    ipw[0] = 1;
    ipw[1] = MOD - MOD / 2;
    REP (i, 2, MAXN) {
        ipw[i] = ipw[1] * ipw[i - 1] % MOD;
    }
    cin >> n >> q;
    cin >> s0 >> t;
    REP (c, 0, 26) {
        REP (i, 1, n + 1) {
            psm[c][i] = psm[c][i - 1];
            if (c + 'a' == t[i - 1]) {
                psm[c][i] += ipw[i];
                if (psm[c][i] >= MOD) {
                    psm[c][i] -= MOD;
                }
            }
        }
    }
    while (q--) {
        int k; string w;
        cin >> k >> w;
        int lvl = 0;
        string s = s0;
        while (s.size() < w.size()) {
            s = s + t[lvl++] + s;
        }
        if (lvl > k) {
            cout << 0 << '\n';
            continue;
        }
        cerr << lvl << ' ' << s << '\n';
        string tmp = w + '$' + s;
        vi prefpi = kmp(tmp);
        tmp = s + '$' + w;
        vi sufpi = kmp(tmp);
        auto getpos = [&] (vi pi, int m) {
            vi res(m + 1, 0);
            res[0] = 1;
            int u = pi.back();
            while (u > 0) {
                res[u] = 1;
                u = pi[u - 1];
            }
            return res;
        };
        vi prefpos = getpos(prefpi, w.size()),
           sufpos = getpos(sufpi, w.size());
        int f = 0;
        REP (i, w.size() + 1, tmp.size()) {
            f += prefpi[i] == w.size();
        }
        ll ans = f * pw[k - lvl] % MOD;
        REP (i, 0, w.size()) {
            if (prefpos[i] && sufpos[w.size() - i - 1]) {
                cerr << ' ' << i << '\n';
                int c = w[i] - 'a';
                ll sm = psm[c][k] - psm[c][lvl];
                if (sm < 0) {
                    sm += MOD;
                }
                ans += pw[k] * sm % MOD;
                if (ans >= MOD) {
                    ans -= MOD;
                }
            }
        }
        /*
        REP (i, 0, 26) {
            char c = i + 'a';
            string tmp = w + '$' + s + c + s;
            vi pi = kmp(tmp);
            g[i] = 0;
            REP (j, w.size() + s.size() + 1, w.size() + s.size() + w.size() + 1) {
                if (pi[j] == w.size()) {
                    g[i]++;
                }
            }
            if (g[i] != 0) {
                cerr << ' ' << i << ' ' << g[i] << ' ' << tmp << '\n';
            }
            ll sm = psm[i][k] - psm[i][lvl];
            if (sm < 0) {
                sm += MOD;
            }
            ans += g[i] * pw[k] % MOD * sm % MOD;
            if (ans >= MOD) {
                ans -= MOD;
            }
        }
        */
        cout << ans << '\n';
    }
    return 0;
}