#include <cstdio>
#include <cstring>
#include <iostream>
#define INF (1<<30)
using namespace std;

int dp[1024][2];
int b[1024][2];
int m,n,x,y;

int p(char c){
    if(c=='#')return 1;
    return 0;
}

int f(int k, int c){
    if(dp[k][c]>=0)return dp[k][c];
    if(k==n){
        dp[k][c]=0;
        return 0;
    }
    if(k+x>n)return INF;

    int i,s;
    s=0;
    for(i=k;i<k+x;++i)s+=b[i][c];
    dp[k][c]=s+f(k+x,1-c);
    for(i=k+x;i<k+y&&i<n;++i){
        s+=b[i][c];
        dp[k][c]=min(dp[k][c],s+f(i+1,1-c));
    }
    return dp[k][c];
}

int main(){
    int i,j;char c;
    cin>>m>>n>>x>>y;
    for(i=0;i<m;++i){
        for(j=0;j<n;++j){
            cin>>c;
            b[j][p(c)]++;
        }
    }
    memset(dp,-1,sizeof(dp));
    printf("%d\n",min(f(0,0),f(0,1)));
    return 0;
}