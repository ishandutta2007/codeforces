#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
typedef long long lld;
typedef pair <int, int> pii;

#define MAXN 100005

const int MOD = 1e9 + 7;
int N;
int P[MAXN];
int D[MAXN][2];
vector <int> con[MAXN];

int dy(int n, int s)
{
    int &ret = D[n][s];
    if (ret >= 0) return ret;
    ret = 0;
    lld dp[2][2] = {0, }; dp[1][0] = 1;
    for (int t: con[n]){
        lld nxt[2][2] = {0, };
        for (int i=0;i<2;i++){
            for (int j=0;j<2;j++){
                nxt[i][j] = (nxt[i][j] + dp[i][j]) % MOD;
                for (int k=0;k<2;k++)
                    nxt[(i+k)&1][j | k] = (nxt[(i+k)&1][j | k] + dp[i][j] * dy(t, k)) % MOD;
            }
        }
        memcpy(dp, nxt, sizeof(dp));
    }
    lld dp2[2] = {0, };
    dp2[0] = 1;
    for (int t: con[n]){
        lld nxt[2] = {0, };
        for (int i=0;i<2;i++){
            nxt[i] = (nxt[i] + dp2[i]) % MOD;
            nxt[!i] = (nxt[!i] + dp2[i] * dy(t, 1)) % MOD;
        }
        memcpy(dp2, nxt, sizeof(dp2));
    }
    ret = (dp[s][0] + dp[s][1] * 2) % MOD;
    if (s == 0)
        ret = (ret - dp2[1] + MOD) % MOD;
    return ret;
}

int main()
{
    scanf("%d", &N);
    for (int i=2;i<=N;i++) scanf("%d", P+i), con[P[i]].pb(i);
    for (int i=1;i<=N;i++){
        sort(all(con[i]));
        D[i][0] = D[i][1] = -1;
    }
    printf("%d\n", (dy(1, 0) + dy(1, 1))%MOD);
}