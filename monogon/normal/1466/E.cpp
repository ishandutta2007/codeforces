
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

const int M = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<ll> x(n);
    vector<ll> sum0(60), sum1(60), pow2(61);
    pow2[0] = 1;
    rep(i, 1, 61) {
        pow2[i] = (2 * pow2[i - 1]) % M;
    }
    rep(i, 0, n) {
        cin >> x[i];
        rep(l, 0, 60) {
            if(x[i] >> l & 1) {
                sum1[l]++;
            }else {
                sum0[l]++;
            }
        }
    }
    ll ans = 0;
    ll hmm = ((pow2[60] - 1) * n) % M;
    rep(i, 0, n) {
        ll a = 0, b = 0;
        rep(l, 0, 60) {
            if(x[i] >> l & 1) {
                a = (a + pow2[l] * sum1[l]) % M;
            }else {
                b = (b + pow2[l] * sum0[l]) % M;
            }
        }
        b = (hmm - b) % M;
        ans = (ans + a * b) % M;
    }
    ans = (ans % M + M) % M;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        solve();
    }
}