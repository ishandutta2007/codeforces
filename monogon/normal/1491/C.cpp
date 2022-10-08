
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

void solve() {
    int n;
    cin >> n;
    vector<ll> s(n + 1);
    rep(i, 1, n + 1) cin >> s[i];
    vector<ll> cnt(n + 2, 0);
    rep(i, 1, n + 1) {
        cnt[n + 1] += max(0LL, i + s[i] - n);
        for(ll j = 2; j <= min((ll) n - i, s[i]); j++) {
            cnt[i + j]++;
        }
        cnt[i + 1] += max(0LL, cnt[i] - s[i] + 1);
    }
    cout << cnt[n + 1] - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}