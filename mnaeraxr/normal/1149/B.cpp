#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

const int maxn = 251;
const int maxs = 100001;
const int alpha = 26;

int dp[maxn][maxn][maxn];
string s;

int nxt[alpha][maxs];
int words[3][maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    cin >> s;

    for (int i = 0; i < 26; ++i){
        nxt[i][n] = n;

        for (int j = n - 1; j >= 0; --j){
            if ((s[j] - 'a') == i){
                nxt[i][j] = j;
            } else {
                nxt[i][j] = nxt[i][j + 1];
            }
        }
    }

    memset(dp, oo, sizeof dp);

    dp[0][0][0] = -1;

    vector<int> l(3);

    for (int i = 0; i < m; ++i){
        string op; cin >> op;

        if (op == "+"){
            int u; char c;
            cin >> u >> c;

            u--;
            int x = c - 'a';

            // cout << op << " " << u << " " << x << endl;
            // cout.flush();

            words[u][l[u]++] = x;
            int p = l[u];


            if (u == 0){
                for (int i = 0; i <= l[1]; ++i)
                    for (int j = 0; j <= l[2]; ++j){
                        int a = p, b = i, c = j;


                        dp[a][b][c] = min({
                            (a == 0 || dp[a - 1][b][c] >= n) ? n : nxt[words[0][a - 1]][dp[a - 1][b][c] + 1],
                            (b == 0 || dp[a][b - 1][c] >= n) ? n : nxt[words[1][b - 1]][dp[a][b - 1][c] + 1],
                            (c == 0 || dp[a][b][c - 1] >= n) ? n : nxt[words[2][c - 1]][dp[a][b][c - 1] + 1],
                        });
                    }
            }

            if (u == 1){
                for (int i = 0; i <= l[0]; ++i)
                    for (int j = 0; j <= l[2]; ++j){
                        int a = i, b = p, c = j;

                        dp[a][b][c] = min({
                            (a == 0 || dp[a - 1][b][c] >= n) ? n : nxt[words[0][a - 1]][dp[a - 1][b][c] + 1],
                            (b == 0 || dp[a][b - 1][c] >= n) ? n : nxt[words[1][b - 1]][dp[a][b - 1][c] + 1],
                            (c == 0 || dp[a][b][c - 1] >= n) ? n : nxt[words[2][c - 1]][dp[a][b][c - 1] + 1],
                        });

                        // cout << "here" << endl;
                        // cout << a << " " << b << " " << c << " " << dp[a][b][c] << endl;
                        // if (a > 0) {
                        //     cout << words[0][a - 1] << " " << dp[a - 1][b][c] << endl;
                        //     cout << nxt[0][5] << endl;
                        // }
                        // cout << ((a == 0 || dp[a - 1][b][c] >= n) ? n : nxt[words[0][a - 1]][dp[a - 1][b][c] + 1]) << endl;
                        // cout << ((b == 0 || dp[a][b - 1][c] >= n) ? n : nxt[words[1][b - 1]][dp[a][b - 1][c] + 1]) << endl;
                        // cout << ((c == 0 || dp[a][b][c - 1] >= n) ? n : nxt[words[2][c - 1]][dp[a][b][c - 1] + 1]) << endl;
                        // cout << dp[0][2][0] << endl;
                        // if (a == 1 && b == 2)
                        //     cout << 1 << " " << 1 << " " << dp[1][1][0] << " " << nxt[2][dp[1][1][0]] << endl;
                        // cout << "end" << endl;

                    }
            }

            if (u == 2){
                for (int i = 0; i <= l[0]; ++i)
                    for (int j = 0; j <= l[1]; ++j){
                        int a = i, b = j, c = p;

                        dp[a][b][c] = min({
                            (a == 0 || dp[a - 1][b][c] >= n) ? n : nxt[words[0][a - 1]][dp[a - 1][b][c] + 1],
                            (b == 0 || dp[a][b - 1][c] >= n) ? n : nxt[words[1][b - 1]][dp[a][b - 1][c] + 1],
                            (c == 0 || dp[a][b][c - 1] >= n) ? n : nxt[words[2][c - 1]][dp[a][b][c - 1] + 1],
                        });
                    }
            }

        } else {
            int u; cin >> u;
            u--;

            if (u == 0){
                for (int i = 0; i <= l[1]; ++i)
                    for (int j = 0; j <= l[2]; ++j)
                        dp[l[u]][i][j] = oo;
            }
            if (u == 1){
                for (int i = 0; i <= l[0]; ++i)
                    for (int j = 0; j <= l[2]; ++j)
                        dp[i][l[u]][j] = oo;
            }
            if (u == 2){
                for (int i = 0; i <= l[0]; ++i)
                    for (int j = 0; j <= l[1]; ++j)
                        dp[i][j][l[u]] = oo;
            }

            l[u]--;
        }

        // cout << l[0] << " " << l[1] << " " << l[2] << endl;
        // cout << dp[l[0]][l[1]][l[2]] << endl;

        if (dp[l[0]][l[1]][l[2]] < n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

        // cout << endl;


        // if (i == 0)
        //     exit(0);
    }

    return 0;
}