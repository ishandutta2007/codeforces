
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

const int N = 505;
int n;
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
    }
    ll ans = 0;
    rep(i, 0, n) {
        ans = max(ans, a[i]);
        rep(j, i + 1, n) {
            ans = max(ans, a[i] | a[j]);
            rep(k, j + 1, n) {
                ans = max(ans, a[i] | a[j] | a[k]);
            }
        }
    }
    cout << ans << '\n';
}