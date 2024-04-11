
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

int t, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        ll ans = (1LL << n);
        for(int i = 1; i < n / 2; i++) {
            ans += (1LL << i);
        }
        for(int i = n / 2; i < n; i++) {
            ans -= (1LL << i);
        }
        cout << ans << '\n';
    }
}