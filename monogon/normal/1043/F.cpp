
#pragma GCC optimize ("Ofast")
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

const int N = 3e5 + 5, M = 1e9 + 7;
int n, a[N], cnt[N];
ll choose[N][8], dp[8][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    rep(j, 1, N) {
        for(int k = 2 * j; k < N; k += j) {
            cnt[j] += cnt[k];
        }
    }
    rep(i, 0, N) rep(j, 0, 8) {
        if(j == 0) choose[i][j] = 1;
        else if(i == 0) choose[i][j] = 0;
        else choose[i][j] = (choose[i - 1][j] + choose[i - 1][j - 1]) % M;
    }
    rep(i, 1, 8) {
        for(int j = N - 1; j >= 1; j--) {
            dp[i][j] = choose[cnt[j]][i];
            for(int k = 2 * j; k < N; k += j) {
                dp[i][j] = (dp[i][j] - dp[i][k]) % M;
            }
        }
        if(dp[i][1] != 0) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << "-1\n";
}