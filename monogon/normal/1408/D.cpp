
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
    cin >> n >> m;
    vector<pii> p(n), q(m);
    rep(i, 0, n) {
        int a, b;
        cin >> a >> b;
        p[i] = {a, b};
    }
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        q[i] = {a, b};
    }
    vector<pii> ve;
    rep(i, 0, n) {
        int a, b, c, d;
        tie(a, b) = p[i];
        rep(j, 0, m) {
            tie(c, d) = q[j];
            ve.emplace_back(c - a, d - b);
        }
    }
    sort(all(ve));
    int y = 0, ans = INT_MAX;
    for(int x = 1e6 + 5; x >= 0; x--) {
        while(ve.back().first == x) {
            y = max(y, ve.back().second + 1);
            ve.pop_back();
        }
        ans = min(ans, x + y);
    }
    cout << ans << '\n';
}