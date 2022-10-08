
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
        int n, k;
        cin >> n >> k;
        vector<ll> a(n * k);
        rep(i, 0, n * k) cin >> a[i];
        sort(a.rbegin(), a.rend());
        int amt = n / 2;
        ll ans = 0;
        rep(i, 1, k + 1) {
            ans += a[(amt + 1) * i - 1];
        }
        cout << ans << '\n';
    }
}