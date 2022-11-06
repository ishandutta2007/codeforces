#include<cstdio>
#include<vector>
using std::vector;
const int mod=998244353;
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
const int N=2e5+5;
int fact[N];
inline void init(int n)
{
	register int i;
	fact[0]=1;
	for(i=1;i<=n;i++)
		fact[i]=mul(fact[i-1],i);
	return;
}
int n,ans=1;
vector<int> e[N];
int ch[N];
void dfs(int x,int pre)
{
	for(int y:e[x])
		if(y!=pre)
			ch[x]++,dfs(y,x);
	return;
}
signed main()
{
	int x,y;
	register int i;
	scanf("%d",&n);
	init(n);
	for(i=1;i<=n-1;i++)
	{
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,0);
	ans=fact[ch[1]];
	for(i=2;i<=n;i++)
		ans=mul(ans,fact[ch[i]+1]);
	ans=mul(ans,n);
	printf("%d\n",ans);
	return 0;
}