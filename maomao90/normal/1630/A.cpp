// time-limit: 1000
// problem-url: https://codeforces.com/contest/1630/problem/A

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

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        if (k == 0) {
            REP (i, 0, n >> 1) {
                printf("%d %d\n", i, (n - 1) ^ i);
            }
            continue;
        }
        if (n == 4 && k == 3) {
            printf("-1\n");
            continue;
        }
        int l = 31 - __builtin_clz(n);
        if (n == k + 1) {
            printf("%d %d\n", n - 1, n - 2);
            printf("%d %d\n", 1, 3);
            printf("%d %d\n", (n - 1) ^ 3, 0);
            printf("%d %d\n", (n - 1) ^ 2, 2);
            REP (i, 4, n >> 1) {
                printf("%d %d\n", i, (n - 1) ^ i);
            }
        } else if (k >> l - 1 & 1) {
            printf("%d %d\n", k, n - 1);
            printf("%d %d\n", 0, (n - 1) ^ k);
            REP (i, 1, n >> 1) {
                if (i == ((n - 1) ^ k)) continue;
                printf("%d %d\n", i, (n - 1) ^ i);
            }
        } else {
            printf("%d %d\n", k, n - 1);
            REP (i, 1, n >> 1) {
                if (i == k) {
                    printf("%d %d\n", 0, (n - 1) ^ i);
                } else {
                    printf("%d %d\n", i, (n - 1) ^ i);
                }
            }
        }
    }
    return 0;
}