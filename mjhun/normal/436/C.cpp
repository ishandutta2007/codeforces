#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

struct edg {
    int x,y,c;
};

bool comp(edg e1, edg e2){
    return e1.c<e2.c;
}

int m,n,k,w;
char b[1024][16][16];
vector<edg> e;
vector<int> graph[1024];

int uf[1024];

void uf_init(){
    int i;
    for(i=0;i<=k;++i){
        uf[i]=i;
    }
}

int uf_find(int a){
    if(a!=uf[a])
        uf[a]=uf_find(uf[a]);
    return uf[a];
}

void uf_union(int a, int b){
    uf[a]=b;
}

int dif(int h, int l){
    int i,j,r=0;
    for(i=0;i<m;++i){
        for(j=0;j<n;++j){
            if(b[h][i][j]!=b[l][i][j])r++;
        }
    }
    return r;
}

bool vis[1024];

void dfs(int v, int r){
    if(vis[v])return;
    vis[v]=true;
    if(v!=0){
        printf("%d %d\n",v,r);
    }
    int i;
    for(i=0;i<graph[v].size();++i){
        dfs(graph[v][i],v);
    }
}

int main(){
    int i,j,h,l;
    cin>>m>>n>>k>>w;
    for(h=1;h<=k;++h){
        for(i=0;i<m;++i){
            for(j=0;j<n;++j){
                cin>>b[h][i][j];
            }
        }
    }
    for(h=1;h<=k;++h){
        edg a;
        a.x=0;a.y=h;a.c=m*n;
        e.push_back(a);
        for(l=h+1;l<=k;++l){
            edg a;
            a.x=h;a.y=l;a.c=dif(h,l)*w;
            e.push_back(a);
        }
    }
    sort(e.begin(),e.end(),comp);
    uf_init();
    i=0;j=0;int r=0;
    while(i<k){
        int x1,x2,f1,f2;
        x1=e[j].x;x2=e[j].y;
        f1=uf_find(x1);f2=uf_find(x2);
        if(f1!=f2){
            r+=e[j].c;
            graph[x1].push_back(x2);
            graph[x2].push_back(x1);
            uf_union(f1,f2);
            i++;
        }
        j++;
    }
    printf("%d\n",r);
    dfs(0,0);
    return 0;
}