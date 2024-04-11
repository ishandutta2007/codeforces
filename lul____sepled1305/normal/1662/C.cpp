#include <bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define st first
#define nd second
using namespace std;
typedef long long ll;
const int N=205,mod=998244353;
int a[N][N],b[N][N],s[N][N],t[N][N],n,m,k;
void mul(int a[][N],int b[][N]){
    rep(i,2*n)rep(j,2*n)t[i][j]=0;
    rep(i,2*n)rep(k,2*n)if(a[i][k])rep(j,2*n)
        t[i][j]=(t[i][j]+(ll)a[i][k]*b[k][j])%mod;
    rep(i,2*n)rep(j,2*n)a[i][j]=t[i][j];
}
int main() {
    scanf("%d%d%d",&n,&m,&k);
    //n=100,m=n*(n-1)/2;k=1e4;
    rep(i,n)a[i+n][i]=1;
    rep(i,m){
        int x,y;
        //x=i%n+1,y=x%n+1;
        scanf("%d%d",&x,&y);
        a[x][y]=a[y][x]=1;
        a[x][x+n]=(a[x][x+n]+mod-1)%mod;
        a[y][y+n]=(a[y][y+n]+mod-1)%mod;
    }
    rep(i,2*n)s[i][i]=1;
    int sto=min(k,2);
    k-=sto;
    rep(i,2*n)rep(j,2*n)b[i][j]=a[i][j];
    rep(i,n)a[i][i+n]=(a[i][i+n]+1)%mod;
    for(;k;k>>=1,mul(a,a))
        if(k&1)mul(s,a);
    rep(i,sto)mul(s,b);
    int ans=0;
    rep(i,n)ans=(ans+s[i][i])%mod;
    printf("%d\n",ans);
    return 0;
}
/*
2 1 4
1 2
 */