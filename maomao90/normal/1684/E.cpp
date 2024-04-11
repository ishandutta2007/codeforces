// time-limit: 2000
// problem-url: https://codeforces.com/contest/1684/problem/E

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

const int INF = 1000000005;
const ll LINF = 1000000000000000005ll;
const int MAXN = 200005;

int t;
int n, k;
int a[MAXN];
map<int, int> mp;

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n >> k;
        mp.clear();
        REP (i, 0, n) {
            cin >> a[i];
            mp[a[i]]++;
        }
        int resid = k, nresid = 0;
        int sm = n;
        int mex = 0;
        int diff = mp.size();
        for (int i = 0; ; i++) {
            if (sm <= 0) {
                mex = i;
                break;
            }
            sm -= mp[i];
            if (mp[i]) continue;
            if (--resid < 0 || --sm < 0) {
                mex = i;
                break;
            }
            nresid++;
        }
        cerr << ' ' << mex << '\n';
        priority_queue<int, vi, greater<int>> pq;
        for (auto [a, b] : mp) {
            if (a >= mex && b > 0) {
                pq.push(b);
            }
        }
        resid = nresid;
        while (!pq.empty()) {
            if (resid == 0) {
                break;
            }
            int x = pq.top(); pq.pop();
            int mn = min(x, resid);
            cerr << "  " << x << ' ' << mn << '\n';
            resid -= mn;
            diff += mn;
            if (mn == x) {
                diff--;
            } else {
                pq.push(x - mn);
            }
            if (resid == 0) {
                break;
            }
        }
        cerr << ' ' << diff << '\n';
        while (resid) {
            diff++;
            resid--;
        }
        resid += k - nresid;
        while (!pq.empty()) {
            if (resid == 0) {
                break;
            }
            int x = pq.top(); pq.pop();
            int mn = min(x, resid);
            resid -= mn;
            if (mn == x) {
                diff--;
            }
            if (resid == 0) {
                break;
            }
        }
        cerr << diff << ' ' << mex << '\n';
        cout << diff - mex << '\n';
    }
    return 0;
}