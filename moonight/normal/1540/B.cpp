#include<bits/stdc++.h>
#define ll long long
#define db double
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(i,a) for(int i=0;i<a.size();++i)
const int N=205;
const int P=1000000007;
int n,fac[N],ifac[N],a[N],par[N],dep[N],lca[N][N],res[N][N];
std::vector<int> g[N];
//pw: calculate the power a^b (mod P)
inline int rd()
{
	char c=getchar();int x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x;
}
inline int pw(int a,int b)
{
	int r=1;
	while(b)
	{
		if(b&1)r=1ll*r*a%P;
		a=1ll*a*a%P;b>>=1;
	}
	return r;
}
inline int C(int a,int b)
{
	return 1ll*fac[a]*ifac[b]%P*ifac[a-b]%P;
}
inline int iC(int a,int b)
{
	return 1ll*ifac[a]*fac[b]%P*fac[a-b]%P;
}
void dfs(int x,int fr)
{
	par[x]=fr;dep[x]=dep[fr]+1;
	fore(i,g[x])
	{
		int y=g[x][i];
		if(y==fr)continue;
		dfs(y,x);
	}
}
inline bool cmp(int x,int y){return dep[x]<dep[y];}
int main()
{
	n=rd();int ans=0;
	rep0(i,1,n)
	{
		int u=rd(),v=rd();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	fac[0]=1;ifac[0]=1;
	rep(i,1,n)fac[i]=1ll*fac[i-1]*i%P,ifac[i]=pw(fac[i],P-2);
	rep(i,1,n)res[i][0]=1;
	rep(i,1,n)rep(j,1,n)res[i][j]=1ll*(res[i-1][j]+res[i][j-1])*ifac[2]%P;
//	rep(i,1,n)rep(j,1,n)res[i][j]=1ll*C(i+j-1,j)*iC(i+j,j)%P;//C(i+j-1,i-1)
//	std::cout<<pw(3,P-2)<<std::endl;
	rep(rt,1,n)
	{
		rep(i,1,n)rep(j,1,n)lca[i][j]=0;
		rep(i,1,n)lca[i][i]=i;
		dfs(rt,0);
		rep(i,1,n)a[i]=i;
		std::sort(a+1,a+n+1,cmp);
		rep(i,1,n)rep(j,1,n)if(i^j)
		{
			int x=a[i],y=a[j];
			if(dep[x]<dep[y])lca[x][y]=lca[x][par[y]];
			else if(dep[x]>dep[y])lca[x][y]=lca[par[x]][y];
			else lca[x][y]=lca[par[x]][par[y]];
//			std::cout<<x<<" "<<y<<" "<<lca[x][y]<<std::endl;
		}
		rep(i,1,n)rep(j,i+1,n)
		{
			int t=lca[i][j];
			if(t==i)continue;
			if(t==j)ans++;
			else ans=(ans+res[dep[i]-dep[t]][dep[j]-dep[t]])%P;
//			std::cout<<rt<<" "<<i<<" "<<j<<" "<<ans<<std::endl;
		}
	}
	ans=1ll*ans*pw(n,P-2)%P;
	printf("%d\n",ans);
	return 0;
} 
/*
5
1 2
1 3
1 4
2 5

	1
/	| 	\
2	3	4
|
5
*/