
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

ll x, y, c[6];
int dx[6] = {1, 0, -1, -1, 0, 1};
int dy[6] = {1, 1, 0, -1, -1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        cin >> x >> y;
        rep(i, 0, 6) cin >> c[i];
        ll ans = LLONG_MAX;
        rep(i, 0, 6) rep(j, 0, 6) {
            int d = dx[i] * dy[j] - dx[j] * dy[i];
            if(d == 0) continue;
            ll a = x * dy[j] - y * dx[j];
            ll b = -x * dy[i] + y * dx[i];
            a /= d;
            b /= d;
            assert(a * dx[i] + b * dx[j] == x);
            assert(a * dy[i] + b * dy[j] == y);
            if(a >= 0 && b >= 0) {
                ans = min(ans, a * c[i] + b * c[j]);
            }
        }
        cout << ans << '\n';
    }
}