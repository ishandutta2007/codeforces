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

int N, M, L;
char ch[30];
char IN[210];
int T[410];

struct unf{
    int p[410];
    void init(){for(int i=1;i<410;i++)p[i] = i;}
    int find(int x){return p[x] == x ? x : p[x] = find(p[x]);}
    int uni(int x,int y){
        x = find(x), y = find(y);
        p[x] = y;
        return x == y;
    }
}uf;

bool edge[402][402],TF[410];
int n,check[410],gc;
int gro[410];
vector <int> v,mem[410];
int Gedge[410][410];
vector <int> Redge[410];
char ans[410];

void DFS1(int x)
{
    check[x]=1;
    int i;
    for(i=0;i<N+N;i++){
        if(check[i] || !edge[x][i])continue;
        DFS1(i);
    }
    v.push_back(x);
}

void DFS2(int x)
{
    gro[x]=gc;mem[gc].push_back(x);
    check[x]=2;
    int i;
    for(i=0;i<N+N;i++){
        if(check[i]==2 || !edge[i][x])continue;
        DFS2(i);
    }
}

void SCC()
{
    int i;
    for(i=0;i<N+N;i++){
        if(check[i])continue;
        DFS1(i);
    }
    while(!v.empty()){
        int x=v.back();
        v.pop_back();
        if(check[x]==2)continue;
        gc++;DFS2(x);
    }
}

int que[410];
int TT[410];
bool chk_valid(){
    int *fr = que, *re = que;
    for(int i=1;i<=gc;i++)TT[i] = T[i];
    for(int i=1;i<=gc;i++)if(TT[i] == 2)*fr++ = i;
    while(re <= fr){
        int t = *re++;
        for(int i=1;i<=gc;i++)if(Gedge[t][i]){
            if(TT[i] == 1)return false;
            else if(TT[i] == 0){
                TT[i] = 2;
                for(auto u : Redge[i]){
                    if(TT[u] == 2)return false;
                    TT[u] = 1;
                }
                *fr++ = i;
            }
        }
    }
    return true;
}

bool fix(int x,int a,int b,char c){
    if(c == 'C'){
        if(b != 1 && a != 2){
            T[gro[x+x+1]] = 2;
            T[gro[x+x]] = 1;
            return true;
        }
        return false;
    }
    else{
        if(a != 1 && b != 2){
            T[gro[x+x]] = 2;
            T[gro[x+x+1]] = 1;
            return true;
        }
        return false;
    }
}

bool dfs(int x,int state){  //0 : [0, x-1] is prefix
    if(x == N)return true;
    int a = T[gro[x+x]], b = T[gro[x+x+1]];
    if(state == 0){
        if(fix(x, a, b, ch[IN[x] - 'a'])){
            if(chk_valid() && dfs(x+1, 0)){
                ans[x] = IN[x];
                return 1;
            }
            else{
                T[gro[x+x]] = a;
                T[gro[x+x+1]] = b;
            }
        }
        int nxt[2] = {-1, -1};
        for(int j=IN[x] - 'a' + 1;j<L;j++){
            int c = ch[j] == 'V' ? 0 : 1;
            if(nxt[c] == -1){
                nxt[c] = j;
                if(fix(x, a, b, ch[j])){
                    if(chk_valid() && dfs(x+1, 1)){
                        ans[x] = j + 'a';
                        return 1;
                    }
                    else{
                        T[gro[x+x]] = a;
                        T[gro[x+x+1]] = b;
                    }
                }
            }
        }
        return 0;
    }
    else{
        int nxt[2] = {-1, -1};
        for(int j=0;j<L;j++){
            int c = ch[j] == 'V' ? 0 : 1;
            if(nxt[c] == -1){
                nxt[c] = j;
                if(fix(x, a, b, ch[j])){
                    if(chk_valid() && dfs(x+1, 1)){
                        ans[x] = j + 'a';
                        return 1;
                    }
                    else{
                        T[gro[x+x]] = a;
                        T[gro[x+x+1]] = b;
                    }
                }
            }
        }
        return 0;
    }
}

int main(){
    scanf("%s",ch);
    L = (int)strlen(ch);
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++){
        char a[2], b[2];
        int x, y;
        scanf("%d%s%d%s", &x, a, &y, b); --x, --y; x*=2, y*=2;
        if(a[0] == 'C')x++;
        if(b[0] == 'C')y++;
        edge[x][y] = 1;
        edge[y^1][x^1] = 1;
    }
    SCC();
    for(int i=0;i<N;i++){
        if(gro[2*i]==gro[2*i+1]){printf("-1");return 0;}
    }
    for(int i=0;i<N+N;i++){
        for(int j=0;j<N+N;j++){
            if(edge[i][j])Gedge[gro[i]][gro[j]] = 1;
        }
        Redge[gro[i]].pb(gro[i^1]); Redge[gro[i^1]].pb(gro[i]);
    }
    scanf("%s", IN);
    if(dfs(0, 0))printf("%s", ans);
    else printf("-1");
    return 0;
}