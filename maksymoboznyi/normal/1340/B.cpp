#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

const string dx[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

const int N = 2e3 + 3;

int n, k, mx[N], mn[N], dp[N][N];
int g[N][N];
string a[N];

int go(string a, string b) {
    int val = 0;
    for (int i = 0; i < a.size(); i++)
        if (a[i] == '1') {
            if (b[i] == '0')
                return -1;
        } else if (b[i] == '1')
            val++;
    return val;
}

void ans(int i, int kol) {
    int val = dp[i][kol];
    if (i == n + 1)
        return;
    for (int c = 9; c >= 0; c--)
        if (g[i][c] == val){
            cout << c;
            ans(i + 1, kol - val);
            return;
        }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[n + 1][0] = 0;
    for (int i = 1; i <= k; i++)
        dp[n + 1][i] = -1;
    for (int i = 1; i <= n; i++)
        for (int c = 0; c <= 9; c++)
            g[i][c] = go(a[i], dx[c]);
    for (int i = n; i > 0; i--)
        for (int kol = 0; kol <= k; kol++)
        {
            dp[i][kol] = -1;
            for (int c = 9; c >= 0; c--) {
                int val = g[i][c];
                if (val != -1 && kol >= val && dp[i + 1][kol - val] != -1) {
                    dp[i][kol] = val;
                    break;
                }
            }
        }
    if (dp[1][k] == -1) {
        cout << -1;
        return 0;
    }
    ans(1, k);
    return 0;
}