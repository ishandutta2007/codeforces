#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
using namespace std;


vector<int> graph[10005];
vector<int> igraph[10005];
vector<int> graph2[10005];
int comp[10005];
int val[10005];//(de las componentes)
int n,m;
int a[128];
int b[128];

vector<pair<int,int> > f;

bool vis[10005];
stack<int> t;

void dfst(int v){
    if(vis[v])return;
    vis[v]=true;
    int i;
    for(i=0;i<graph[v].size();++i){
        dfst(graph[v][i]);
    }
    t.push(v);
}

void dfsi(int v, int c){
    if(comp[v]==c)return;
    comp[v]=c;
    int i;
    for(i=0;i<igraph[v].size();++i){
        dfsi(igraph[v][i],c);
    }
}

void kosaraju(){ // (sobre graph)
    int i;
    memset(vis,false,sizeof(vis));
    for(i=0;i<2*m;++i){
        dfst(i);
    }
    int nc=0;
    memset(comp,-1,sizeof(comp));
    while(!t.empty()){
        int x=t.top();
        t.pop();
        if(comp[x]>=0)continue;
        dfsi(x,nc++);
    }
}

int neg(int x){
    if(x<m)return x+m;
    else return x-m;
}

bool cyc(int x, int y){
    if(a[x]<=a[y]){
        return a[x]<a[y]&&a[y]<b[x]&&b[x]<b[y];
    }
    else {
        return a[y]<a[x]&&a[x]<b[y]&&b[y]<b[x];
    }
}

void dfs2(int x, int c){//sobre componentes (graph2)
    if(val[x]!=-1)return;
    val[x]=c;
    int i;
    for(i=0;i<graph2[x].size();++i){
        dfs2(graph2[x][i],1-c);
    }
}

int main(){
    int i,j;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;++i){
        scanf("%d %d",a+i,b+i);
        if(b[i]<a[i]){
            int t=b[i];
            b[i]=a[i];
            a[i]=t;
        }
    }
    for(i=0;i<m;++i){
        for(j=i+1;j<m;++j){
            if(cyc(i,j)){
                f.pb(mp(i,j));
                f.pb(mp(neg(i),neg(j)));
            }
        }
    }

    for(i=0;i<f.size();++i){
        graph[neg(f[i].fst)].pb(f[i].snd);
        graph[neg(f[i].snd)].pb(f[i].fst);
        igraph[f[i].snd].pb(neg(f[i].fst));
        igraph[f[i].fst].pb(neg(f[i].snd));
    }
    kosaraju();
    bool r=true;
    for(i=0;r&&i<m;++i){
        r=comp[i]!=comp[neg(i)];
    }
    if(r){
        for(i=0;i<m;++i){
            graph2[comp[i]].pb(comp[neg(i)]);
            graph2[comp[neg(i)]].pb(comp[i]);
        }
        memset(val,-1,sizeof(val));
        for(i=0;i<2*m;++i){
            if(val[i]==-1){
                dfs2(i,0);
            }
        }
        for(i=0;i<m;++i){
            if(val[comp[i]]){
                putchar('i');
            }
            else{
                putchar('o');
            }
        }
        putchar('\n');
    }

    else{
        puts("Impossible");
    }
    return 0;
}