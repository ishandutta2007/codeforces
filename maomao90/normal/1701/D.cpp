// time-limit: 4000
// problem-url: https://codeforces.com/contest/1701/problem/D

// Hallelujah, praise the one who set me free
// Hallelujah, death has lost its grip on me
// You have broken every chain, There's salvation in your name
// Jesus Christ, my living hope
#include <bits/stdc++.h> 
using namespace std;

#define REP(i, s, e) for (int i = (s); i < (e); i++)
#define RREP(i, s, e) for (int i = (s); i >= (e); i--)
template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
typedef long long ll;
typedef long double ld;
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define SZ(_a) (int) _a.size()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<iii> viii;

#ifndef DEBUG
#define cerr if (0) cerr
#endif

const int INF = 1000000005;
const ll LINF = 1000000000000000005ll;
const int MAXN = 500005;

int t;
int n;
int b[MAXN];
int a[MAXN];
ii rng[MAXN];

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n;
        REP (i, 1, n + 1) {
            cin >> b[i];
        }
        REP (i, 1, n + 1) {
            // i / mn[i] = b[i]
            // i / mx[i] = b[i]
            if (b[i] == 0) {
                int mn = i + 1;
                int mx = n;
                rng[i] = {mn, mx};
            } else {
                int mx = i / b[i];
                int mn = i / (b[i] + 1) + 1;
                rng[i] = {mn, mx};
            }
            cerr << i << ": " << rng[i].FI << ' ' << rng[i].SE << '\n';
        }
        vi p(n, 0);
        iota(ALL(p), 1);
        sort(ALL(p), [&] (int l, int r) {
                return rng[l] < rng[r];
                });
        reverse(ALL(p));
        priority_queue<ii, vii, greater<ii>> pq;
        REP (i, 1, n + 1) {
            while (!p.empty() && rng[p.back()].FI == i) {
                pq.push({rng[p.back()].SE, p.back()}); p.pop_back();
            }
            assert(!pq.empty() && pq.top().FI >= i);
            a[pq.top().SE] = i; pq.pop();
        }
        REP (i, 1, n + 1) {
            assert(rng[i].FI <= a[i] && a[i] <= rng[i].SE);
        }
        REP (i, 1, n + 1) {
            cout << a[i] << ' ';
        }
        cout << ' ';
    }
    return 0;
}