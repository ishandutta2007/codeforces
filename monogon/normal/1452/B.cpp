
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int n;
        cin >> n;
        vi a(n, 0);
        int mx = -1e9;
        ll sum = 0;
        rep(i, 0, n) {
            cin >> a[i];
            sum += a[i];
            mx = max(mx, a[i]);
        }
        ll ans = max(0LL, 1LL * mx * (n - 1) - sum);
        sum = max(sum, 1LL * mx * (n - 1));
        ll x = ((-sum) % (n - 1) + (n - 1)) % (n - 1);
        ans += x;
        cout << ans << '\n';
    }
}