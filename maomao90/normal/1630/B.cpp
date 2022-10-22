// time-limit: 2000
// problem-url: https://codeforces.com/contest/1630/problem/B

// Fight the good fight of the faith. Take hold of the 
// eternal life to which you were called when you made 
// your good confession in the presence of many witnesses
// 1 Timonthy 6:12
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
int n, k;
int a[MAXN], o[MAXN];
int ans, ansl, ansr;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        REP (i, 0, n + 1) {
            o[i] = 0;
        }
        REP (i, 1, n + 1) {
            scanf("%d", &a[i]);
            o[a[i]]++;
        }
        REP (i, 1, n + 1) {
            o[i] += o[i - 1];
        }
        int r = 1;
        ans = INF;
        REP (l, 1, n + 1) {
            while (r <= n && 2 * (o[r] - o[l - 1]) - n < k) {
                r++;
            }
            if (r <= n && mnto(ans, r - l + 1)) {
                ansl = l;
                ansr = r;
            }
        }
        printf("%d %d\n", ansl, ansr);
        int cnt = 0;
        vi v;
        v.pb(0);
        REP (i, 1, n + 1) {
            if (v.size() == k) {
                break;
            }
            if (ansl <= a[i] && a[i] <= ansr) {
                cnt++;
            } else {
                cnt--;
            }
            if (cnt == 1) {
                v.pb(i);
                cnt = 0;
            }
        }
        REP (i, 1, v.size()) {
            printf("%d %d\n", v[i - 1] + 1, v[i]);
        }
        printf("%d %d\n", v.back() + 1, n);
    }
    return 0;
}