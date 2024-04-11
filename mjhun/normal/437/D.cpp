#include <algorithm>
#include <cstdio>
using namespace std;

struct edge {
    int x,y,c;
};

bool comp(edge e1, edge e2){
    return e1.c>e2.c;
}

edge e[100005];

int n,m;
int uf[100005];
int ln[100005];

void ufinit(){
    int i;
    for(i=0;i<n;++i){
        uf[i]=i;
        ln[i]=1;
    }
}

int uffind(int v){
    if(uf[v]==v)return v;
    uf[v]=uffind(uf[v]);
    return uf[v];
}

void ufunion(int v, int w){
    uf[v]=w;
    ln[v]=ln[w]=(ln[v]+ln[w]);
}

double r=0;
int cv[100005];

int main(){
    int i;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;++i){
        scanf("%d",cv+i);
    }
    for(i=0;i<m;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        x--;y--;
        e[i].x=x;
        e[i].y=y;
        e[i].c=min(cv[x],cv[y]);
    }
    sort(e,e+m,comp);
    ufinit();
    int k=0;i=0;
    while(k<n-1){
        int fx=uffind(e[i].x),fy=uffind(e[i].y);
        if(fx!=fy){
            k++;
            r+=(double)2*ln[fx]*ln[fy]*e[i].c/((double)n*(n-1));
            ufunion(fx,fy);
        }
        i++;
    }
    printf("%.6lf\n",r);
    return 0;
}