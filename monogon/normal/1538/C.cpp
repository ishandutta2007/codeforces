
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
    int n; ll l, r;
    cin >> n >> l >> r;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(all(a));
    auto get = [&](int r) {
        int j = n - 1;
        ll cnt = 0;
        rep(i, 0, n) {
            while(j >= 0 && a[i] + a[j] > r) j--;
            if(j <= i) break;
            cnt += j - i;
        }
        return cnt;
    };
    cout << get(r) - get(l - 1) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}