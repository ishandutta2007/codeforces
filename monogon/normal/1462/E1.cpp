
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

// const int M = 1e9 + 7;

// ll modpow(ll a, ll b) {
//     ll ans = 1;
//     while(b > 0) {
//         if(b & 1) {
//             ans = (ans * a) % M;
//         }
//         b /= 2;
//         a = (a * a) % M;
//     }
//     return ans;
// }
// ll modinv(ll a) {
//     return modpow(a, M - 2);
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int n, m, k;
        cin >> n;// >> m >> k;
        k = 2; m = 3;
        vector<ll> choose(n + 1, 0);
        rep(i, 0, n + 1) {
            if(i < m - 1) {
                choose[i] = 0;
            }else if(i == m - 1) {
                choose[i] = 1;
            }else {
                choose[i] = (choose[i - 1] * i) / (i - m + 1);
            }
        }
        // rep(i, 0, n + 1) {
        //     cout << choose[i] << ' ';
        // }
        // cout << endl;
        vi a(n);
        rep(i, 0, n) cin >> a[i];
        sort(all(a));
        int j = 0;
        ll ans = 0;
        rep(i, 0, n) {
            while(j < n && a[i] + k >= a[j]) j++;
            ans += choose[j - i - 1];
        }
        cout << ans << '\n';
    }
}