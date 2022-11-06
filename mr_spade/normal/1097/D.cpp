#include<cstdio>
#include<vector>
#define int long long
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
int n,k,ans;
struct cell
{
	int a,b;
};
vector<cell> V;
int dp[105][105];
void dfs(int step,int x,int f)
{
	if(step==(int)V.size())
	{
		ans=add(ans,mul(x,f));
		return;
	}
	register int i;
	for(i=0;i<=V[step].b;i++)
		dfs(step+1,x,mul(f,dp[step][i])),x=mul(x,V[step].a);
	return;
}
signed main()
{
	int x,cnt;
	register int i,j,l;
	scanf("%lld%lld",&n,&k);x=n;
	for(i=2;i*i<=n;i++)
		if(x%i==0)
		{
			cnt=0;
			while(x%i==0)
				x/=i,cnt++;
			V.push_back(cell{i,cnt});
		}
	if(x!=1)
		V.push_back(cell{x,1});
	for(i=0;i<(int)V.size();i++)
	{
		dp[i][V[i].b]=1;
		for(j=1;j<=k;j++)
		{
			x=0;
			for(l=V[i].b;l>=0;l--)
			{
				x=add(x,mul(dp[i][l],qpow(l+1,mod-2)));
				dp[i][l]=x;
			}
		}
	}
	dfs(0,1,1);
	printf("%lld\n",ans);
	return 0;
}