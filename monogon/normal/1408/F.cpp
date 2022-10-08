
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

int n;
vector<pii> ve;

void solve(int l, int r) {
    if(l == r) return;
    int m = (l + r) / 2;
    solve(l, m);
    solve(m + 1, r);
    rep(i, 0, m - l + 1) {
        ve.emplace_back(l + i, m + i + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    if(n <= 2) {
        cout << 0 << '\n';
        return 0;
    }
    if(n == 3) {
        cout << 1 << '\n' << 1 << ' ' << 2 << '\n';
        return 0;
    }
    int k = 0;
    while((1 << (k + 1)) <= n) k++;
    solve(1, 1 << k);
    solve(n - (1 << k) + 1, n);
    cout << sz(ve) << '\n';
    for(auto &pa : ve) {
        int u, v;
        tie(u, v) = pa;
        cout << u << ' ' << v << '\n';
    }
}