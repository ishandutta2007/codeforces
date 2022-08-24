#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)1e5 + 100;
int n, m, k;
const int INF = (int)(1e9);
vector < pair < int, int > > dist[maxN];
vector < pair < int, int > > info[maxN];
vector < int > routes[maxN];
vector < int > bck[maxN];
struct cmp{
    bool operator () (pair < pair < int, int >, pair < int, int > > a,pair < pair < int, int >, pair < int, int > > b) {
        if (a.first != b.first) {
            return make_pair(a.first.first, -a.first.second) < make_pair(b.first.first, -b.first.second);
        }
        else {
            return a.second < b.second;
        }
    }
};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    srand(time(0));
    int n;
    ll t;
    ll s, d;
    cin >> n >> t;
    int best = -1;
    ll opt = (ll)1e18;
    for (int i = 1; i <= n; i++) {
        cin >> s >> d;
        // s + k * d >= t
        ll k = max(0LL, (t - s + d - 1) / d);
        ll v = s + k * d;
        if (v < opt) {
            opt = v;
            best = i;
        }
    }
    cout << best;
    return 0;
}