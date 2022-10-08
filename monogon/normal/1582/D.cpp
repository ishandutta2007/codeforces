
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
    vector<ll> a(n);
    vector<ll> ans(n);
    ll s = 0;
    rep(i, 0, n) {
        cin >> a[i];
        if((s > 0) ^ (a[i] > 0)) {
            ans[i] = 1;
            s += a[i];
        }else {
            ans[i] = -1;
            s -= a[i];
        }
    }
    if(s != 0) {
        int i = 0;
        while(i < n && (s == ans[i] * a[i] || (ans[i] * a[i] > 0) != (s > 0))) i++;
        if(i == n) {
            ans[1] *= 2;
        }else {
            rep(j, 0, n) {
                if(j != i)
                ans[j] *= -ans[i] * a[i];
            }
            ans[i] *= (s - ans[i] * a[i]);
        }
    }
    ll sum = 0;
    rep(i, 0, n) {
        cout << ans[i] << ' ';
        sum += ans[i] * a[i];
        assert(abs(ans[i]) <= 1e4);
    }
    assert(sum == 0);
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}