#include <stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

vector <int> E[200030];

typedef long long ll;
ll D[200020], U[200020], R[200020];
int rem[200020], chk[200020];
int par[200020];
int N;
const ll MOD = 1e9 + 7;

ll pw(ll x,ll y){
    ll ret = 1;
    while(y){
        if(y & 1)ret = (ret * x) % MOD;
        x = (x * x) % MOD;
        y >>= 1;
    }
    return ret;
}

ll inv(ll x){return pw(x, MOD - 2);}
ll div_(ll x,ll y){return (x * inv(y)) % MOD;}

void dfs1(int x){
    D[x] = 1;
    for(int i=0;i<(int)E[x].size();i++){
        int u = E[x][i];
        dfs1(u);
        D[x] = (D[x] * (D[u] + 1)) % MOD;
    }
    if((D[x] + 1) % MOD == 0 && x != 1){
        chk[par[x]]++;
        if(chk[par[x]] == 1)rem[par[x]] = x;
    }
}

void dfs2(int x){
    for(int i=0;i<(int)E[x].size();i++){
        int u = E[x][i];
        if(chk[x] > 1)U[u] = 1;
        else if(chk[x] == 1){
            if(u == rem[x])U[u] = (U[x] * R[x] + 1) % MOD;
            else U[u] = 1;
        }
        else{
            U[u] = (U[x] * (div_(D[x], (D[u] + 1) % MOD)) + 1) % MOD;
        }
        dfs2(u);
    }
}

int main(){
    scanf("%d",&N);
    for(int i=2;i<=N;i++){
        scanf("%d",par+i);
        E[par[i]].push_back(i);
    }
    dfs1(1);
    for(int i=1;i<=N;i++){
        if(chk[i] == 1){
            ll T = 1;
            for(int j=0;j<(int)E[i].size();j++){
                int u = E[i][j];
                if(u != rem[i])T = (T * (D[u] + 1)) % MOD;
            }
            R[i] = T;
        }
    }
    U[1] = 1;
    dfs2(1);
    for(int i=1;i<=N;i++){
        printf("%lld ", (D[i] * U[i]) % MOD);
    }
    return 0;
}