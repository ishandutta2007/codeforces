
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
    int n, m;
    cin >> n;
    vi a(n + 1);
    vi vis(n + 1, 0);
    rep(i, 1, n + 1) cin >> a[i];
    cin >> m;
    rep(i, 0, m) {
        int b;
        cin >> b;
        vis[b]++;
    }
    ll A = 0, B = 0;
    rep(i, 1, n + 1) {
        if(vis[a[i]] > 0) {
            A += 1LL * i * vis[a[i]];
            B += 1LL * (n - i + 1) * vis[a[i]];
        }
    }
    cout << A << ' ' << B << '\n';
}