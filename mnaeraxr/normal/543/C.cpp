#include <bits/stdc++.h>

using namespace std;

//#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int64> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 1000000 + 10;

string L[30];
int V[30][30];
int dp[1 << 20];

int M[30][26];
int S[30][25], MX[30][26];


int n, m;

int solve(int mask){
    if (mask == 0) return 0;
    int &ans = dp[mask];
    if (ans >= 0) return ans;

    int l = __lg(mask);
    ans = oo;

    for (int i = 0; i < m; ++i){
        int c = L[l][i] - 'a';
        int cur = min(solve(mask ^ (1 << l)) + V[l][i], solve(mask ^ (mask & M[i][c])) + S[i][c] - MX[i][c]);
        ans = min(ans, cur);
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i){
        cin >> L[i];

    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> V[i][j];

    for (int i = 0; i < n; ++i){

        for (int j = 0; j < m; ++j){
            int l = L[i][j] - 'a';
            M[j][l] |= 1 << i;
            S[j][l] += V[i][j];
            MX[j][l] = max(MX[j][l], V[i][j]);
        }
    }

    memset(dp, -1, sizeof dp);

    cout << solve((1 << n) - 1) << endl;

    return 0;
}