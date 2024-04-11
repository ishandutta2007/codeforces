
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
    int te;
    cin >> te;
    while(te--) {
        int n;
        cin >> n;
        vi a(n);
        vi d(n, 0);
        rep(i, 0, n) cin >> a[i];
        auto solve = [&](auto solve, int l, int r, int dep) {
            if(l > r) return;
            int i = max_element(a.begin() + l, a.begin() + r + 1) - a.begin();
            d[i] = dep;
            solve(solve, l, i - 1, dep + 1);
            solve(solve, i + 1, r, dep + 1);
        };
        solve(solve, 0, n - 1, 0);
        rep(i, 0, n) cout << d[i] << ' ';
        cout << '\n';
    }
}