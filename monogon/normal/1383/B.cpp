
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

// 0 = lose, 1 = win, 2 = draw
// i = num 0's, j = num 1's

// const int N = 100;
// int dp[N][N][2][2];

// a = player 1
// b = player 2

// int solve(int i, int j, int a, int b) {
//     if(dp[i][j][a][b] != -1) return dp[i][j][a][b];
//     if(j == 0) {
//         // no 1's
//         if(a < b) dp[i][j][a][b] = 0;
//         else if(a > b) dp[i][j][a][b] = 1;
//         else dp[i][j][a][b] = 2;
//     }else if(i == 0) {
//         // no 0's
//         int x = solve(i, j - 1, b, 1 - a);
//         if(x == 0) dp[i][j][a][b] = 1;
//         else if(x == 1) dp[i][j][a][b] = 0;
//         else dp[i][j][a][b] = 2;
//     }else {
//         int x = solve(i - 1, j, b, a);
//         int y = solve(i, j - 1, b, 1 - a);
//         if(x == 0 || y == 0) dp[i][j][a][b] = 1;
//         else if(x == 2 || y == 2) dp[i][j][a][b] = 2;
//         else dp[i][j][a][b] = 0;
//     }
//     return dp[i][j][a][b];
// }

const int N = 1e5 + 5, LG = 30;
int a[N];
int cnt[LG];
int dp[LG];

int tab[2][4] = {{2, 1, 2, 0}, {2, 1, 2, 1}};
string str[3] = {"LOSE", "WIN", "DRAW"};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // rep(i, 0, N) rep(j, 0, N) rep(a, 0, 2) rep(b, 0, 2) dp[i][j][a][b] = -1;
    // rep(i, 0, 10) rep(j, 0, 10) {
    //     solve(i, j, 0, 0);
    //     cout << dp[i][j][0][0] << ' ';
    //     if(j == 9) cout << '\n';
    // }
    int te;
    cin >> te;
    while(te--) {
        int n;
        cin >> n;
        fill(cnt, cnt + LG, 0);
        rep(i, 0, n) {
            cin >> a[i];
            rep(l, 0, LG) {
                if((a[i] >> l) & 1) cnt[l]++;
            }
        }
        rep(l, 0, LG) {
            int one = cnt[l], zero = n - one;
            int x = tab[zero % 2][one % 4];
            if(x == 0) {
                dp[l] = 0;
            }else if(x == 1) {
                dp[l] = 1;
            }else if(x == 2) {
                if(l == 0) dp[l] = 2;
                else dp[l] = dp[l - 1];
            }
        }
        cout << str[dp[LG - 1]] << '\n';
    }
}