#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()

int n, m;
int S[200020];
vector <int> v[200020];
vector <Pi> Ed[200020], Gd[200020];
int E[200020][2];
char ans[200020];
int chk[200020];
int que[200020];
int vis[200020];
int ed_chk[200020];

bool dfs(int x){
    vis[x] = 1;
    bool flag = 0;
    for(auto i : Gd[x]){
        if(ed_chk[abs(i.Fi)])continue;
        ed_chk[abs(i.Fi)] = 1;
        if(vis[i.Se]){
            if(i.Fi < 0)ans[-i.Fi] = '1';
            else ans[i.Fi] = '0';
            flag = 1;
        }
        if(!vis[i.Se]){
            if(dfs(i.Se)){
                if(i.Fi < 0)ans[-i.Fi] = '1';
                else ans[i.Fi] = '0';
                flag = 1;
            }
            else{
                if(i.Fi < 0)ans[-i.Fi] = '0';
                else ans[i.Fi] = '1';
            }
        }
    }
    return flag;
}

int main(){
    memset(E, -1, sizeof E);
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++){
        scanf("%d",S+i);
        for(int j=0;j<S[i];j++){
            int x; scanf("%d",&x);
            v[i].pb(x);
            if(x > 0){
                if(E[x][0] == -1)E[x][0] = i;
                else ans[x] = '1', chk[i] = chk[E[x][0]] = 1, E[x][0] = -2;
            }
            if(x < 0){
                if(E[-x][1] == -1)E[-x][1] = i;
                else ans[-x] = '0', chk[i] = chk[E[-x][1]] = 1, E[-x][0] = -2;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(E[i][0] == -2)continue;
        if(E[i][0] == -1 && E[i][1] != -1){
            ans[i] = '0';
            chk[E[i][1]] = 1;
        }
        if(E[i][0] != -1 && E[i][1] == -1){
            ans[i] = '1';
            chk[E[i][0]] = 1;
        }
        if(E[i][0] != -1 && E[i][1] != -1){
            Ed[E[i][0]].pb(Pi(-i, E[i][1]));
            Ed[E[i][1]].pb(Pi(i, E[i][0]));
        }
        if(E[i][0] == -1 && E[i][1] == -1)ans[i] = '1';
    }
    int *fr = que, *re = que;
    for(int i=1;i<=m;i++)if(chk[i])*fr++ = i;
    while(re < fr){
        int t = *re++;
        for(auto i : Ed[t]){
            if(!chk[i.Se]){
                chk[i.Se] = 1;
                if(i.Fi < 0){
                    ans[-i.Fi] = '0';
                }
                else{
                    ans[i.Fi] = '1';
                }
                *fr++ = i.Se;
            }
            else{
                if(ans[abs(i.Fi)] == 0)ans[abs(i.Fi)] = '1';
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(auto j : Ed[i]){
            if(!chk[i] && !chk[j.Se])Gd[i].pb(j);
        }
    }
    bool flag = 1;
    for(int i=1;i<=m;i++)if(!chk[i] && !vis[i])flag &= dfs(i);
    if(!flag)puts("NO");
    else{
        printf("YES\n");
        //for(int i=1;i<=n;i++)printf("%d ", ans[i]);
        printf("%s", ans+1);
    }
    return 0;
}