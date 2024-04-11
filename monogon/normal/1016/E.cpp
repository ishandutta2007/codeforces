
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 2e5 + 5;
int n, q;
ll l[N], r[N], len[N], x, y, sy, a, b;

inline double inter(ll x, ll y, ll a, ll sy) {
    return a - (1.0 * (x - a) * sy) / (y - sy);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> sy >> a >> b >> n;
    rep(i, 1, n + 1) {
        cin >> l[i] >> r[i];
        len[i] = (r[i] - l[i]) + len[i - 1];
    }
    cin >> q;
    cout << fixed << setprecision(8);
    while(q--) {
        cin >> x >> y;
        double d1 = inter(x, y, a, sy);
        double d2 = inter(x, y, b, sy);
        int i = lower_bound(r + 1, r + n + 1, d1) - r;
        int j = lower_bound(r + 1, r + n + 1, d2) - r;
        double ans = len[j - 1] - len[i - 1];
        if(i <= n && d1 > l[i]) {
            ans -= d1 - l[i];
        }
        if(j <= n && d2 > l[j]) {
            ans += d2 - l[j];
        }
        cout << ans * (b - a) / (d2 - d1) << '\n';
    }
}