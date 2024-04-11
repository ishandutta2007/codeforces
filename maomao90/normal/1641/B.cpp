// time-limit: 1000
// problem-url: https://codeforces.com/contest/1641/problem/B

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
#define MAXN 250005

int t;
int n;
int a[MAXN];

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n;
        deque<int> dq;
        map<int, int> cnt;
        REP (i, 0, n) {
            cin >> a[i];
            dq.pb(a[i]);
            cnt[a[i]]++;
        }
        bool pos = 1;
        for (auto [i, j] : cnt) {
            if (j % 2 == 1) {
                pos = 0;
                break;
            }
        }
        if (!pos) {
            cout << -1 << '\n';
            continue;
        }
        int len = 0;
        vii add; vi split;
        while (!dq.empty()) {
            int id = -1;
            REP (i, 1, dq.size()) {
                if (dq[i] == dq[0]) {
                    id = i;
                    break;
                }
            }
            assert(id != -1);
            split.pb(id * 2);
            vi tmp;
            REP (i, 1, id) {
                tmp.pb(dq[i]);
                add.pb(MP(len + id + 1, dq[i]));
                len++;
            }
            REP (i, 0, id + 1) {
                dq.pop_front();
                len++;
            }
            for (int i : tmp) {
                dq.push_front(i);
            }
        }
        cout << add.size() << '\n';
        for (auto [i, j] : add) {
            cout << i << ' ' << j << '\n';
        }
        cout << split.size() << '\n';
        for (int i : split) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}