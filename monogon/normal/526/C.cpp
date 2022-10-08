
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

// a red candies, b blue candies
// maximize hr * r + hb * b
// restriction: wr * r + wb * b <= c

ll c, hr, hb, wr, wb;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> hr >> hb >> wr >> wb;
    ll ans = 0;
    for(ll i = 0; i < 1e6; i++) {
        if(wr * i <= c) {
            ll j = (c - wr * i) / wb;
            ans = max(ans, hr * i + hb * j);
        }
        if(wb * i <= c) {
            ll j = (c - wb * i) / wr;
            ans = max(ans, hr * j + hb * i);
        }
    }
    cout << ans << '\n';
}