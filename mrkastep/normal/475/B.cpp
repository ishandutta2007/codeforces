#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define ll long long

int n,m;

bool read(){
    if(scanf("%d%d",&n,&m)!=2) return false;
    return true;
}

int st[30][30],g[30],v[30];

void deep(int x,int y){
    if(x<0||x>=m||y<0||y>=n||st[x][y]==1) return;
    st[x][y]=1;
    deep(x+g[y],y);
    deep(x,y+v[x]);
}

void solve(){
    int i,j,x,y;
    char s[30];
    gets(s);
    gets(s);
    For(i,n){
        if(s[i]=='<') g[i]=-1;
        else g[i]=1;
    }
    gets(s);
    For(i,m){
        if(s[i]=='^') v[i]=-1;
        else v[i]=1;
    }
    For(x,m) For(y,n){
        For(i,m)For(j,n) st[i][j]=0;
        deep(x,y);
        For(i,m)For(j,n) if(st[i][j]!=1){
            printf("NO");
            return;
        }
    }
    printf("YES");
}


int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int i;
    while(read()){
        solve();
    }
    return 0;

}