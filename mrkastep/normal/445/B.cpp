#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>

#define For(i,n) for(i=0;i<(n);i++)
#define itn int

int rank[111111],p[111111],e[111111],g[111111];

void ms(int v){
    rank[v]=1;
    p[v]=v;
    e[v]=0;
    g[v]=1;
}

int fs(int v){
    if(p[v]==v) return v;
    return p[v]=fs(p[v]);
}

void us(int a,int b){
    a=fs(a);
    b=fs(b);
    if(a==b){
        e[a]++;
        return;
    }
    else{
        if(rank[a]==rank[b]){
            p[b]=a;
            rank[a]++;
            e[a]+=e[b]+1;
            g[a]+=g[b];
            return;
        }
        if(rank[a]>rank[b]){
            p[b]=a;
            g[a]+=g[b];
            e[a]+=e[b]+1;
            return;
        }
        g[b]+=g[a];
        e[b]+=e[a]+1;
        p[a]=b;
        return;
    }
}

void solve(int n){
    int i,t,x,m;
    std::map<int,int> l;
    long long int ans;
    For(i,n) ms(i);
    scanf("%d",&m);
    For(i,m){
        scanf("%d%d",&x,&t);
        us(x-1,t-1);
    }
    t=0;
    For(i,n){
        if(e[fs(i)]!=0&&l[fs(i)]==0){
            l[fs(i)]++;
            t+=g[fs(i)]-1;
        }
    }
    ans=1;
    For(i,t) ans*=2;
    printf("%I64d",ans);

}

int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef     ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k,l;
    while(scanf("%d",&n)!=EOF){
        solve(n);
    }
    return 0;
}