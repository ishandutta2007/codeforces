#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
typedef long long lld;

int N;
int P[MAXN], F[MAXN];
lld D[MAXN][2];
vector <int> con[MAXN];

void dfs(int n)
{
    if (con[n].empty()){
        D[n][1] = F[n]; D[n][0] = 0;
        return;
    }
    D[n][0] = 0; D[n][1] = -2e9;
    for (int t: con[n]){
        dfs(t);
        lld tmp[2] = {D[n][0], D[n][1]};
        for (int i=0;i<2;i++){
            for (int j=0;j<2;j++){
                int k = (i+j)%2;
                D[n][k] = max(D[n][k], tmp[i]+D[t][j]);
            }
        }
    }
    D[n][1] = max(D[n][1], D[n][0]+F[n]);
}

int main()
{
    scanf("%d", &N);
    for (int i=1;i<=N;i++){
        scanf("%d%d", P+i, F+i);
        if (i > 1) con[P[i]].push_back(i);
    }
    dfs(1);
    printf("%lld\n", max(D[1][0], D[1][1]));
}