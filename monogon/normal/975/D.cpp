
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
int n;
ll a, b, x[N], vx[N], vy[N];
map<ll, vi> ma;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b;
    rep(i, 0, n) {
        cin >> x[i] >> vx[i] >> vy[i];
        ll dot = a * vx[i] - vy[i];
        ma[dot].push_back(i);
    }
    ll ans = 0;
    for(auto &p : ma) {
        vi ve = p.second;
        ans += 1LL * sz(ve) * (sz(ve) - 1);
        map<ll, int> speed;
        for(int i : ve) {
            speed[vx[i] + a * vy[i]]++;
        }
        for(auto &p2 : speed) {
            ll cnt = p2.second;
            ans -= cnt * (cnt - 1);
        }
    }
    cout << ans << '\n';
}