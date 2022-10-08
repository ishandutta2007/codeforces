
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
    string a, b;
    cin >> a >> b;
    int n = a.length(), m = b.length();
    int ans = 0;
    rep(i, 0, n) rep(j, 0, m) {
        int k = 0;
        while(i + k < n && j + k < m && a[i + k] == b[j + k]) k++;
        ans = max(ans, k);
    }
    cout << n + m - 2 * ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}