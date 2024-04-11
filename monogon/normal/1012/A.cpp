
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

const int N = 1e5 + 5;
int n;
ll a[2 * N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, 2 * n) {
        cin >> a[i];
    }
    sort(a, a + 2 * n);
    ll ans = (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
    rep(i, 0, n) {
        ans = min(ans, (a[i + n - 1] - a[i]) * (a[2 * n - 1] - a[0]));
    }
    cout << ans << '\n';
}