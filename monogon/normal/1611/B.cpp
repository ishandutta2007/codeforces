
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

void solve() {
    ll a, b;
    cin >> a >> b;
    ll num31 = max(0ll, min({(a - b) / 2, a / 3, b}));
    a -= 3 * num31;
    b -= num31;
    ll num13 = max(0ll, min({(b - a) / 2, a, b / 3}));
    a -= num13;
    b -= 3 * num13;
    ll ans = min(a / 2, b / 2);
    ans += num31 + num13;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}