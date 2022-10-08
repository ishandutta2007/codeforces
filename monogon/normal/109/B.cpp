
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

ll pl, pr, vl, vr;
int k;

ll inter(ll a, ll b, ll c, ll d) {
    return max(0LL, min(b, d) - max(a, c) + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> pl >> pr >> vl >> vr >> k;
    long double ans = 0;
    vector<ll> lucky;
    rep(len, 0, 11) {
        rep(x, 0, (1 << len)) {
            ll y = 0;
            rep(i, 0, len) {
                if((x >> i) & 1) {
                    y = y * 10 + 4;
                }else {
                    y = y * 10 + 7;
                }
            }
            lucky.push_back(y);
        }
    }
    sort(all(lucky));
    int n = sz(lucky);
    rep(i, 1, n - k) {
        int j = i + k;
        ans += 1.0 * inter(pl, pr, lucky[i - 1] + 1, lucky[i]) * inter(vl, vr, lucky[j - 1], lucky[j] - 1);
        ans += 1.0 * inter(vl, vr, lucky[i - 1] + 1, lucky[i]) * inter(pl, pr, lucky[j - 1], lucky[j] - 1);
        if(k == 1 && pl <= lucky[i] && lucky[i] <= pr && vl <= lucky[i] && lucky[i] <= vr) ans--;
        // if(k == 1) ans -= 1.0 * inter(lucky[i], lucky[i], pl, pr) * inter(lucky[i], lucky[i], vl, vr);
    }
    ans /= 1.0 * (pr - pl + 1) * (vr - vl + 1);
    cout << fixed << setprecision(11) << ans << '\n';
}