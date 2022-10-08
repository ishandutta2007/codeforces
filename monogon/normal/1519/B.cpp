
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

const int N = 105;
ll dpmin[N][N], dpmax[N][N];

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    if(k >= dpmin[n][m] && k <= dpmax[n][m]) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    rep(i, 1, N) rep(j, 1, N) {
        if(i == 1 && j == 1) dpmin[i][j] = dpmax[i][j] = 0;
        else {
            dpmin[i][j] = LLONG_MAX;
            dpmax[i][j] = LLONG_MIN;
            if(i > 1) {
                dpmin[i][j] = min(dpmin[i][j], j + dpmin[i - 1][j]);
                dpmax[i][j] = max(dpmax[i][j], j + dpmax[i - 1][j]);
            }
            if(j > 1) {
                dpmin[i][j] = min(dpmin[i][j], i + dpmin[i][j - 1]);
                dpmax[i][j] = max(dpmax[i][j], i + dpmax[i][j - 1]);
            }
        }
    }

    int te;
    cin >> te;
    while(te--) solve();
}