
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
    int n;
    cin >> n;
    const int A = 5e6 + 5;
    vi cnt(A);
    vector<ll> dp(A);
    rep(i, 0, n) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    rep(i, 1, A) {
        for(int j = 2 * i; j < A; j += i) {
            cnt[i] += cnt[j];
        }
    }
    for(int i = A - 1; i >= 1; i--) {
        dp[i] = 1ll * cnt[i] * i;
        for(int j = 2 * i; j < A; j += i) {
            dp[i] = max(dp[i], 1ll * (cnt[i] - cnt[j]) * i + dp[j]);
        }
    }
    cout << dp[1] << '\n';
}