#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using std::min;
using std::vector;
const int mod=1e9+7;
inline int add(int a,int b)
{
	return (a+=b)>=mod?a-mod:a;
}
inline int sub(int a,int b)
{
	return (a-=b)<0?a+mod:a;
}
inline int mul(int a,int b)
{
	return (long long)a*b%mod;
}
inline int qpow(int a,int b)
{
	int res=1;
	for(;b;a=mul(a,a),b>>=1)
		if(b&1)
			res=mul(res,a);
	return res;
}
const int N=1e5+5,K=205;
int n,k,ans;
int S[K][K],fact[K];
int size[N];
vector<int> e[N];
int f[N][K];
int tmp[K],tmp2[K];
int g[K];
void dfs(int x,int father)
{
	int kx,ky;
	register int i,j;
	f[x][0]=2;size[x]=1;
	for(auto y:e[x])
		if(y!=father)
		{
			dfs(y,x);kx=min(k,size[x]);ky=min(k,size[y]);
			memcpy(tmp,f[y],sizeof(int)*(ky+1));
			for(i=ky;i>0;i--)
				tmp[i]=add(tmp[i],tmp[i-1]);
			for(i=0;i<=ky;i++)
				g[i]=sub(g[i],tmp[i]);
			tmp[0]=add(tmp[0],1);
			memset(tmp2,0,sizeof(int)*(k+1));
			for(i=0;i<=kx;i++)
				for(j=0;j<=ky&&i+j<=k;j++)
					tmp2[i+j]=add(tmp2[i+j],mul(f[x][i],tmp[j]));
			memcpy(f[x],tmp2,sizeof(int)*(k+1));
			size[x]+=size[y];
		}
	f[x][0]=sub(f[x][0],1);
	kx=min(k,size[x]);
	for(i=0;i<=kx;i++)
		g[i]=add(g[i],f[x][i]);
	return;
}
signed main()
{
	int x,y;
	register int i,j;
	scanf("%d%d",&n,&k);
	fact[0]=1;
	for(i=1;i<=k;i++)
		fact[i]=mul(fact[i-1],i);
	S[0][0]=1;
	for(i=1;i<=k;i++)
	{
		S[i][0]=0;S[i][i]=1;
		for(j=1;j<i;j++)
			S[i][j]=add(S[i-1][j-1],mul(j,S[i-1][j]));
	}
	for(i=1;i<=n-1;i++)
	{
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,0);
	for(i=1;i<=k;i++)
		ans=add(ans,mul(mul(S[k][i],fact[i]),g[i]));
	printf("%d\n",ans);
	return 0;
}