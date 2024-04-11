// time-limit: 2000
// problem-url: https://codeforces.com/contest/1628/problem/A

// No temptation has overtaken you except what is common to mankind. And God 
// is faithful; he will not let you be tempted beyond what you can bear.
// But when you are tempted, he will also provide a way out so that you can 
// endure it.
// 1 Corinthians 10:13
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
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define MT make_tuple
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#ifdef DEBUG
#define debug(args...) printf(args)
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MAXN 200005

int t;
int n;
int a[MAXN];
int occ[MAXN], mex;
int nocc[MAXN], nmex;
vi ans;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        ans.clear();
        mex = 0;
        nmex = 0;
        REP (i, 0, n + 1) {
            occ[i] = 0;
            nocc[i] = 0;
        }
        REP (i, 0, n) {
            scanf("%d", &a[i]);
            occ[a[i]]++;
        }
        REP (i, 0, n + 1) {
            if (occ[i] == 0) {
                mex = i;
                break;
            }
        }
        int omex = mex;
        vi v;
        REP (i, 0, n) {
            v.pb(i);
            nocc[a[i]]++;
            while (nocc[nmex] > 0) {
                nmex++;
            }
            if (--occ[a[i]] == 0) {
                mnto(mex, a[i]);
            }
            debug("%d %d\n", i, nmex);
            debug("%d\n", omex);
            if (nmex == omex) {
                debug(" %d %d\n", i, mex);
                ans.pb(nmex);
                for (int j : v) {
                    nocc[a[j]] = 0;
                }
                nmex = 0;
                v.clear();
                omex = mex;
            }
        }
        printf("%d\n", (int) ans.size());
        for (int i : ans) {
            printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}