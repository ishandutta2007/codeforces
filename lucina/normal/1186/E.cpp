#include<bits/stdc++.h>
using namespace std;
#define popcnt __builtin_popcountll
int n,m,q,x1,y1,x2,y2;
int sum[2010][2010];
int x[2010][2010];
char s[1010][1010];
long long get(int x,int y){
    long long res=0;
    int a=x/n,b=y/m,c=(x%n),d=(y%m);
    int ret=((popcnt(a)&1)+(popcnt(b)&1))&1;
    res+=1LL*a*b*sum[n][m];
    res+=1LL*b*sum[c][m]+1LL*a*sum[n][d];
    res+=(ret)?c*d-sum[c][d]:sum[c][d];
    return res;
}

int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }
    for(int i=1;i<=2*n;i++){
        for(int j=1;j<=2*m;j++){
            x[i][j]=s[(i>n)?i-n:i][(j>m)?j-m:j]-'0';
            if(i>n&&j<=m)x[i][j]^=1;
            else if(i<=n&&j>m)x[i][j]^=1;
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+x[i][j];
        }
    }
    n*=2;m*=2;
    while(q--){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%lld\n",get(x2,y2)-get(x1-1,y2)-get(x2,y1-1)+get(x1-1,y1-1));
    }
}