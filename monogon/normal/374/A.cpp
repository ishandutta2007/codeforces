
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
    int n, m, i, j, a, b;
    cin >> n >> m >> i >> j >> a >> b;
    vector<pii> ve = {{1, 1}, {n, 1}, {1, m}, {n, m}};
    int ans = INT_MAX;
    for(auto &pa : ve) {
        int x, y;
        tie(x, y) = pa;
        if((i - x) % a == 0 && (j - y) % b == 0 && abs((i - x) / a) % 2 == abs((j - y) / b) % 2) {
            if((j == y || i - a >= 1 || i + a <= n) && (i == x || j - b >= 1 || j + b <= m)) {
                ans = min(ans, max(abs(i - x) / a, abs(j - y) / b));
            }
        }
    }
    if(ans == INT_MAX) {
        cout << "Poor Inna and pony!\n";
    }else {
        cout << ans << '\n';
    }
}