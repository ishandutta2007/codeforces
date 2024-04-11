// time-limit: 1000
// problem-url: https://codeforces.com/contest/946/problem/E

// But let justice roll on like a river,
// righteousness like a never-failing stream!
// Amos 5:24
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
char s[MAXN];
int a[MAXN], b[MAXN], sm[MAXN];
bool use[10];
string ans;

inline int sze() {
    int res = 0;
    REP (i, 0, 10) {
        res += use[i];
    }
    return res;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf(" %s", s);
        n = strlen(s);
        REP (i, 0, n) {
            b[i] = -1;
        }
        REP (i, 0, n) {
            a[i] = s[i] - '0';
            sm[i] = a[i];
            if (i) {
                sm[i] += sm[i - 1];
            }
        }
        memset(use, 0, sizeof use);
        REP (i, 0, n) {
            bool can = 0;
            use[a[i]] ^= 1;
            if (sze() < n - i + 1) {
                int e = n - sze() - 1;
                bool all = (sm[e] - sm[i]) == 0;
                if (all) {
                    int j = -1;
                    REP (k, e + 1, n) {
                        j++;
                        while (!use[j]) {
                            j++;
                        }
                        if (j < a[k]) {
                            can = 1;
                            break;
                        } else if (j > a[k]) {
                            break;
                        }
                    }
                } else {
                    can = 1;
                }
            }
            if (can) {
                b[i] = a[i];
                continue;
            }
            use[a[i]] ^= 1;
            if (sze() == n - i) {
                RREP (j, a[i] - 1, 0) {
                    if (use[j]) {
                        b[i] = j;
                        use[j] = 0;
                        break;
                    }
                }
            } else {
                b[i] = a[i] - 1;
                use[b[i]] ^= 1;
            }
            i++;
            while (sze() < n - i) {
                b[i] = 9;
                use[b[i]] ^= 1;
                i++;
            }
            int k = 10;
            REP (j, i, n) {
                k--;
                while (!use[k]) {
                    k--;
                }
                b[j] = k;
            }
            break;
        }
        REP (i, b[0] == 0, n - (b[0] == 0)) {
            printf("%d", b[i]);
        }
        printf("\n");
    }
    return 0;
}