#include <bits/stdc++.h>
using namespace std;
#define N 30010
#define M 610
int s[N];
int dp[N][M];
int n,d,x;
inline int read()
{
    char ch=getchar();int s=0;
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
    return s;
}
inline bool check(int x,int c)
{
    int delta=d+c-300;
    if (delta<=0) return false;
    if (delta+x>30000) return false; 
    return true ;
}
int dfs(int x,int c)
{
    int &ret=dp[x][c];
    if (ret==-1){
        ret=0;
        if (check(x,c)) ret=max(ret,dfs(x+d+c-300,c));
        if (check(x,c-1)) ret=max(ret,dfs(x+d+c-1-300,c-1));
        if (check(x,c+1)) ret=max(ret,dfs(x+d+c+1-300,c+1));
        ret+=s[x];
    } 
    return ret;
} 
int main(){
    n=read(),d=read();
    memset(dp,-1,sizeof(dp)); 
    for(int i=1;i<=n;i++){
        x=read();
        s[x]++;
    }
    printf("%d",dfs(d,300));
    return 0;
}