#include<cstdio>
const int MAXN=1e5+5,MAXK=2005,Mod=1e9+7;
int n,m,k;
int fac[MAXN<<1],facinv[MAXN<<1],inv[MAXN<<1];
int Pow(int a,int b){
    int res=1;
    while(b){
        if(b&1) res=1ll*res*a%Mod;
        b>>=1;
        a=1ll*a*a%Mod;
    }
    return res;
}
int Form(int n,int m){
    if(m==n||m==0) return 1;
    int t=1ll*fac[n]*facinv[m]%Mod;
    return 1ll*t*facinv[n-m]%Mod;
}
int x[MAXK],y[MAXK];
int f[MAXK],vis[MAXK];
int Dfs(int u){
    if(vis[u]) return f[u];
    vis[u]=1;
    f[u]=Form(x[u]+y[u]-2,x[u]-1);
    for(int i=1;i<=k;i++)
        if(i!=u&&x[i]<=x[u]&&y[i]<=y[u])
            f[u]=(f[u]-1ll*Dfs(i)*Form(x[u]-x[i]+y[u]-y[i],x[u]-x[i])%Mod+Mod)%Mod;//,printf("u %d i %d\n",u,i);
    return f[u];
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    fac[1]=1;
    inv[1]=facinv[1]=1;
    for(int i=2;i<n+m;i++){
        fac[i]=1ll*fac[i-1]*i%Mod;
        inv[i]=Pow(i,Mod-2);
        facinv[i]=1ll*facinv[i-1]*inv[i]%Mod;
    }
    for(int i=1;i<=k;i++)
        scanf("%d%d",x+i,y+i);
    k++;
    x[k]=n,y[k]=m;
    printf("%d\n",Dfs(k));
    return 0;
}