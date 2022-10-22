// time-limit: 2000
// problem-url: https://codeforces.com/contest/1654/problem/B

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
string s;
int used[30];

int main() {
    cin >> t;
    while (t--) {
        cin >> s;
        memset(used, 0, sizeof used);
        REP (i, 0, s.size()) {
            used[s[i] - 'a']++;
        }
        REP (i, 0, s.size()) {
            used[s[i] - 'a']--;
            if (used[s[i] - 'a'] == 0) {
                REP (j, i, s.size()) {
                    cout << s[j];
                }
                break;
            }
        }
        cout << '\n';
    }
    return 0;
}