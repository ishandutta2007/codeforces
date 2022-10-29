#include <cstdio>
#include <iostream>
#include <vector>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
using namespace std;

vector<pair<int,bool> > graph[100005];
vector<int> sol;

int dfs(int v, int f){
    int r=0,i,s,k;
    bool b;
    for(i=0;i<graph[v].size();++i){
        s=graph[v][i].fst;
        b=graph[v][i].snd;
        if(s!=f){
            r+=max(k=dfs(s,v),b?1:0);
            if(b&&!k)sol.pb(s);
        }
    }
    return r;
}

int main(){
    int n,i,a,b,c;
    bool t;
    scanf("%d",&n);
    for(i=1;i<n;++i){
        scanf("%d %d %d",&a,&b,&c);
        t=c==2;
        graph[a].pb(mp(b,t));
        graph[b].pb(mp(a,t));
    }
    dfs(1,0);
    printf("%d\n",sol.size());
    if(sol.size()){
        printf("%d",sol[0]);
        for(i=1;i<sol.size();++i){
            printf(" %d",sol[i]);
        }
        putchar('\n');
    }
    return 0;
}