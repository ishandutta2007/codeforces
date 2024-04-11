
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
        vector<ll> a(n);
        vector<ll> p;
        ll sum = 0;
        rep(i, 0, n) {
            cin >> a[i];
            sum += a[i];
            p.push_back(sum);
        }
        auto check = [&](ll div) {
            int cnt = 0;
            for(ll x : p) {
                if(x % div == 0) {
                    cnt++;
                }
            }
            return div * cnt == sum;
        };
        int ans = INT_MAX;
        for(int i = 1; i <= n; i++) {
            if(sum % i == 0) {
                if(check(sum / i)) {
                    ans = min(ans, n - i);
                }
            }
        }
        cout << ans << '\n';
    }
}