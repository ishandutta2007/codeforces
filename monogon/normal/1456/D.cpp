
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

const int N = 5005;
ll t[N], x[N], ti[N];
bool reach[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    rep(i, 1, n + 1) {
        cin >> t[i] >> x[i];
        ti[i] = 2e9;
    }
    rep(i, 0, n) {
        if(ti[i] <= t[i]) {
            ti[i + 1] = min(ti[i + 1], max(t[i], ti[i] + abs(x[i] - x[i + 1])));
            rep(j, i + 2, n + 1) {
                if(abs(x[i] - x[j]) <= t[j] - ti[i] && max(t[i], ti[i] + abs(x[i] - x[j])) + abs(x[j] - x[i + 1]) <= t[i + 1]) {
                    reach[i + 1][j] = true;
                }
            }
        }
        rep(j, i + 1, n + 1) {
            if(reach[i][j]) {
                if(j == i + 1) {
                    // update ti[i + 1]
                    // iterate over all clones to make next
                    if(j + 1 <= n) {
                        ti[j + 1] = min(ti[j + 1], max(t[j], t[i] + abs(x[i] - x[j + 1])));
                        rep(k, j + 2, n + 1) {
                            if(abs(x[i] - x[k]) <= t[k] - t[i] && max(t[j], t[i] + abs(x[i] - x[k])) + abs(x[k] - x[j + 1]) <= t[j + 1]) {
                                reach[j + 1][k] = true;
                            }
                        }
                    }
                }else {
                    // we must move from i to i + 1
                    if(abs(x[i + 1] - x[i]) <= t[i + 1] - t[i]) {
                        reach[i + 1][j] = true;
                    }
                }
            }
        }
    }
    cout << (ti[n] <= t[n] || reach[n - 1][n] ? "YES" : "NO") << '\n';
}