#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100100;
const int MOD = 1e9 + 7;

int n, p[MAXN], dp[MAXN][2], dp2[MAXN][2][2][3]; //dp2: node, #colored, last, reversable
vector<int> adj[MAXN];

void add(int& a, int b) { a = (a+b)%MOD; }

void go(int cur) {
    int sze = adj[cur].size();
    for (int i=0; i<=sze; i++)
        for (int j=0; j<2; j++)
            for (int k=0; k<2; k++)
                for (int l=0; l<3; l++)
                    dp2[i][j][k][l] = 0;
    dp2[0][1][1][2] = 1;
    for (int i=0; i<sze; i++) {
        int nxt = adj[cur][i];
        for (int j=0; j<2; j++)
            for (int k=0; k<2; k++)
                for (int l=0; l<3; l++) {
                    int num = dp2[i][j][k][l];
                    add(dp2[i+1][j][k][l], num);
                    for (int k1=0; k1<2; k1++) {
                        int num2 = ll(num)*dp[nxt][k1]%MOD;
                        if (l == 2) {
                            add(dp2[i+1][j^k1][j][0], num2);
                        } else if (l == 0) {
                            if ((j^k1) != k) add(dp2[i+1][j^k1][j][1], num2);
                            else add(dp2[i+1][j^k1][j][0], num2);
                        } else {
                            add(dp2[i+1][j^k1][j][1], num2);
                        }
                    }
                }
    }
}

void dfs(int cur) {
    int sze = adj[cur].size();
    for (int i=0; i<sze; i++) dfs(adj[cur][i]);

    go(cur);
    for (int j=0; j<2; j++)
        for (int k=0; k<2; k++)
            for (int l=0; l<3; l++)
                add(dp[cur][j], dp2[sze][j][k][l]);
    reverse(adj[cur].begin(), adj[cur].end());
    go(cur);
    for (int j=0; j<2; j++)
        for (int k=0; k<2; k++)
            add(dp[cur][j], dp2[sze][j][k][1]);
    for (int i=0; i<2; i++)
        add(dp[cur][i], dp2[sze][i][0][0]);
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=1; i<n; i++) {
        cin >> p[i];
        p[i]--;
        adj[p[i]].push_back(i);
    }

    for (int i=0; i<n; i++)
        sort(adj[i].begin(), adj[i].end());

    dfs(0);

    cout << (dp[0][0]+dp[0][1])%MOD << '\n';
    return 0;
}