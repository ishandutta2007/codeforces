#include <stdio.h>
#include <algorithm>
#include <vector>
#define For(i,n) for(i=0;i<(n);i++)

int c[101][2];

bool srt(int x,int y){
    return c[x][0]<c[y][0];
}

void solve(int n,int s){
    int ind[101],x,y,m,i;
    For(i,n){
        scanf("%d%d",&x,&y);
        c[i][1]=y;
        if(y!=0) c[i][0]=x+1;
        else c[i][0]=x;
        ind[i]=i;
    }
    ind[n]=n;
    c[n][0]=0;
    std::sort(ind,ind+n,srt);
    m=-1;
    i=0;
    while((c[ind[i]][0]<s+1)&&i<n){
        if((100-c[ind[i]][1])%100>m) m=(100-c[ind[i]][1])%100;
        i++;
    }
    printf("%d",m);
}

int main() {
#pragma comment(linker, "/STACK:67108864")
#ifndef ONLINE_JUDGE
freopen("input.txt", "rt", stdin);
freopen("output.txt", "wt", stdout);
#endif
    int n,s;
    while(scanf("%d%d",&n,&s)!=EOF){
    solve(n,s);
    }
    return 0;
}