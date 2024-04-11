#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

const int N_ = 100010;

struct unf{
    int p[N_];
    void init(){for(int i=0;i<N_;i++)p[i] = i;}
    int Find(int x){return p[x] == x ? x : p[x] = Find(p[x]);}
    void Union(int x,int y){
        x = Find(x), y = Find(y);
        p[x] = y;
    }
}uf;
int S[N_], D[N_], co = 1;
int Q[N_][3];
vector <int> son[N_];
int par[N_];

void dfs(int x){
    S[x] = co;
    for(int i=0;i<son[x].size();i++){
        dfs(son[x][i]);
    }
    D[x] = co++;
}

bool check_anc(int x,int y){
    return S[x] <= D[y] && D[y] <= D[x];
}

int P[N_][2], cnt2;

int main()
{
    int n, q;
    scanf("%d%d",&n,&q);
    int i;
    for(i=0;i<q;i++){
        scanf("%d%d",Q[i],Q[i]+1);
        if(Q[i][0] != 2)scanf("%d",Q[i]+2);
    }
    for(i=0;i<q;i++){
        if(Q[i][0] == 1){
            son[Q[i][2]].push_back(Q[i][1]);
            par[Q[i][1]] = Q[i][2];
        }
    }
    for(i=1;i<=n;i++){
        if(!par[i])dfs(i);
    }
    uf.init();
    for(i=0;i<q;i++){
        if(Q[i][0] == 1){
            uf.Union(Q[i][1], Q[i][2]);
        }
        if(Q[i][0] == 2){
            P[++cnt2][0] = Q[i][1];
            P[cnt2][1] = uf.Find(Q[i][1]);
        }
        if(Q[i][0] == 3){
            if(check_anc(Q[i][1], P[Q[i][2]][0]) && check_anc(P[Q[i][2]][1], Q[i][1]))printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}