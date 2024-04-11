
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
    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    sort(all(a));
    int idx = 0;
    vi ans(n, 0);
    for(int i = 1; i < n; i += 2) {
        ans[i] = a[idx];
        idx++;
    }
    for(int i = 0; i < n; i += 2) {
        ans[i] = a[idx];
        idx++;
    }
    cout << (n - 1)/2 << '\n';
    for(int x : ans) cout << x << ' ';
    cout << '\n';
}