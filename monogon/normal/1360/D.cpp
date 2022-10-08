
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

int t;
ll n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        ll ans = n;
        if(n <= k) {
            ans = 1;
        }
        for(int i = 2; i * i <= n && i <= k; i++) {
            if(n % i == 0) {
                ans = min(ans, n / i);
                if(n / i <= k) {
                    ans = min(ans, 1LL * i);
                }
            }
        }
        cout << ans << '\n';
    }
}