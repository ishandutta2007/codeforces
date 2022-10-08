#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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

int f(int x) {
    if(x % 4 == 1) return 1;
    else if(x % 4 == 3) return 0;
    return x ^ (x % 4 == 2);
}

const int N = 5e4 + 5, Q = 5e3 + 5, K = 220;
int a[N], b[N], c[N];
int dp[2][N], qu[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    rep(i, 1, n + 1) {
        cin >> a[i];
        b[i] = f(a[i] - 1);
        c[i] = f(a[i]);
    }
    vector<array<int, 3>> ve;
    rep(i, 0, m) {
        int l, r;
        cin >> l >> r;
        ve.push_back({r - l + 1, l, i});
    }
    sort(all(ve));
    int idx = 0;
    rep(len, 1, n + 1) {
        for(int i = 1; i + len <= n + 1; i++) {
            if(len == 1) dp[1][i] = (b[i] ^ c[i]);
            else {
                dp[1][i] = max(dp[0][i], dp[0][i + 1]);
                if(a[i] <= a[i + len - 1]) {
                    dp[1][i] = max(dp[1][i], b[i] ^ c[i + len - 1]);
                }else {
                    dp[1][i] = max(dp[1][i], c[i] ^ b[i + len - 1]);
                }
            }
            while(idx < m && ve[idx][0] == len && ve[idx][1] == i) {
                qu[ve[idx][2]] = dp[1][i];
                idx++;
            }
        }
        swap(dp[0], dp[1]);
    }
    rep(i, 0, m) {
        cout << qu[i] << '\n';
    }
}