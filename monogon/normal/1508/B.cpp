
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
    int n; ll k;
    cin >> n >> k;
    k--;
    vector<bool> mask(n, 0);
    rep(i, 0, min(n, 60)) mask[i] = (k >> i) & 1;
    if(n <= 60 && (k >> (n - 1)) > 0) {
        cout << "-1\n";
        return;
    }
    vi ans(n);
    rep(i, 0, n) ans[i] = i + 1;
    int idx = 0;
    while(idx < n) {
        int j = idx;
        while(mask[j]) j++;
        reverse(ans.begin() + n - j - 1, ans.begin() + n - idx);
        idx = j + 1;
    }

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
    while(te--) {
        solve();
    }
}