#include <cstdio>
#include <iostream>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
#define repd(i,l,r,d) for(int i=l;i<=r;i+=d)
#define perd(i,r,l,d) for(int i=r;i>=l;i-=d)
#define N 1000005
#define M 5005
int s1[M][M],s2[M][M],n,m,p,t,cur,a[N],g[2],f[2][M];
int main(){
	scanf("%d%d%d",&n,&m,&p);t=0;
	rep(i,1,n) scanf("%d",&a[i]),t=std::max(t,a[i]);
	s1[0][0]=s2[0][0]=1;
	rep(i,1,t) rep(j,1,std::min(i,m)){
		s1[i][j]=(1ll*s1[i-1][j]*(j-1)+1ll*s1[i-1][j-1]*j)%p;
		s2[i][j]=(1ll*s2[i-1][j]*(j-1)+1ll*s2[i-1][j-1]*(m-j+1))%p;
	}
	a[0]=0;g[0]=1;cur=0;
	rep(i,1,n){
		t=std::min(a[i-1],a[i]);g[cur^=1]=0;
		rep(j,1,t) f[cur][j]=((1ll*g[cur^1]*s2[a[i]][j]-1ll*f[cur^1][j]*s1[a[i]][j])%p+p)%p;
		rep(j,t+1,a[i]) f[cur][j]=(1ll*g[cur^1]*s2[a[i]][j])%p;
		rep(j,1,a[i]) g[cur]=(g[cur]+f[cur][j])%p;
	}
	printf("%d",g[cur]);
}