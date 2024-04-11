// time-limit: 2000
// problem-url: https://codeforces.com/contest/1647/problem/D

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

#ifndef DEBUG
#define cerr if (0) cerr
#endif

#define INF 1000000005
#define LINF 1000000000000000005ll
#define MAXN 200005

int t;
int x, d;

bool prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> x >> d;
        int p = 0;
        while (x % d == 0) {
            x /= d; p++;
        }
        if (p <= 1) {
            cout << "NO\n";
            continue;
        }
        if (!prime(x)) {
            cout << "YES\n";
            continue;
        }
        if (prime(d)) {
            cout << "NO\n";
            continue;
        }
        if (p >= 4) {
            cout << "YES\n";
            continue;
        }
        if (p >= 3) {
            int sq = round(sqrt(d));
            bool can = 0;
            ll a = (ll) x * d;
            REP (z, 3, p + 1) {
                for (ll i = 1; i * i <= a; i++) {
                    if (a % i == 0) {
                        if (a != 0 && (ll) a / i % d != 0) {
                            can = 1;
                            break;
                        }
                    }
                }
                a *= d;
            }
            if (!can) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
continue;
        }
cout << "NO\n";
    }
    return 0;
}