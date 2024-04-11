
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
        vector<ll> a(n), b(n);
        rep(i, 0, n) {
            cin >> a[i];
        }
        rep(i, 0, n) {
            cin >> b[i];
        }
        ll A = *min_element(all(a)), B = *min_element(all(b));
        ll ans = 0;
        rep(i, 0, n) {
            ans += max(a[i] - A, b[i] - B);
        }
        cout << ans << '\n';
    }
}