
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
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(all(a));
    vi cnt(n + 2, 0);
    rep(i, 0, q) {
        int l, r;
        cin >> l >> r;
        cnt[l]++;
        cnt[r + 1]--;
    }
    rep(i, 1, n + 2) cnt[i] += cnt[i - 1];
    sort(cnt.begin() + 1, cnt.begin() + n + 1);
    ll ans = 0;
    rep(i, 1, n + 1) {
        ans += a[i - 1] * cnt[i];
    }
    cout << ans << '\n';
}