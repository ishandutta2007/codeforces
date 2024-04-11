
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
    ll s;
    int n;
    cin >> s >> n;
    vector<ll> p10(10, 1);
    rep(i, 1, 10) p10[i] = 10ll * p10[i - 1];
    vector<ll> ans(n, 0);
    int idx = 0, fre = n;
    for(int k = 9; k >= 0 && s > 0; k--) {
        if(p10[k] <= s && s - p10[k] >= fre - 1) {
            ans[idx] += p10[k];
            s -= p10[k];
            fre = max(0, fre - 1);
            idx = (idx + 1) % n;
            k++;
        }
    }
    assert(s == 0);
    rep(i, 0, n) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}