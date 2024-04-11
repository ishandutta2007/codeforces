#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>

#define For(i,n) for(i=0;i<(n);i++)
#define itn int

int rank[111111],p[111111],e[111111],g[111111],n1,m1,k1;

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

int num(int a,int b,int c){
    return a*n1*m1+b*m1+c;
}

void solve(int k){
    int i,m,a[12][12][12],n,r,x,y,ans=0,j,c,t;
    char l;
    scanf("%d%d",&n,&m);
    n1=n;
    m1=m;
    k1=k;
    r=n*m*k;
    For(i,12){
        For(j,12){
            For(c,12){
                a[i][j][c]=0;
            }
        }
    }
    For(i,k){
        getchar();
        For(j,n){
            getchar();
            For(c,m){
                x=getchar();
                ms(num(i,j,c));
                if(x=='.') a[k-i-1][j][c]=1;
            }
        }
    }
    For(i,k){
        For(j,n){
            For(c,m){
                if(i-1>=0&&a[i-1][j][c]==1&&a[i][j][c]==1) us(num(i,j,c),num(i-1,j,c));
                if(j-1>=0&&a[i][j-1][c]==1&&a[i][j][c]==1) us(num(i,j,c),num(i,j-1,c));
                if(c-1>=0&&a[i][j][c-1]==1&&a[i][j][c]==1) us(num(i,j,c),num(i,j,c-1));
                if(i+1<k&&a[i+1][j][c]==1&&a[i][j][c]==1) us(num(i,j,c),num(i+1,j,c));
                if(j+1<n&&a[i][j+1][c]==1&&a[i][j][c]==1) us(num(i,j,c),num(i,j+1,c));
                if(i+1<m&&a[i][j][c+1]==1&&a[i][j][c]==1) us(num(i,j,c),num(i,j,c+1));

            }
        }
    }
    scanf("%d%d",&x,&y);
    t=fs(num(k-1,x-1,y-1));
    For(i,r) if(fs(i)==t) ans++;
    printf("%d",ans);

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