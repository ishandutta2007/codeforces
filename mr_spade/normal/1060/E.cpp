#include<cstdio>
#include<vector>
#define int long long
using std::vector;
const int N=2e5+5;
int n;
int ts0,ts1;
int tw0,tw1;
int s0[N],s1[N];
int w0[N],w1[N];
vector<int> g[N];
void dfs(int now,int father)
{
	int ss0,ss1,ww0,ww1;
	s0[now]=1;
	for(auto i:g[now])
	{
		if(i==father)
			continue;
		dfs(i,now);
		ss0=s0[now]+s1[i];
		ss1=s1[now]+s0[i];
		ww0=w0[now]+w1[i]+s1[i];
		ww1=w1[now]+w0[i]+s0[i];
		ts0+=s0[now]*s1[i]+s1[now]*s0[i];
		ts1+=s0[now]*s0[i]+s1[now]*s1[i];
		tw0+=s0[now]*(w1[i]+s1[i])+s1[now]*(w0[i]+s0[i]);
		tw0+=s0[i]*w1[now]+s1[i]*w0[now];
		tw1+=s0[now]*(w0[i]+s0[i])+s1[now]*(w1[i]+s1[i]);
		tw1+=s0[i]*w0[now]+s1[i]*w1[now];
		s0[now]=ss0;s1[now]=ss1;
		w0[now]=ww0;w1[now]=ww1;
	}
	return;
}
signed main()
{
	int u,v;
	register int i;
	scanf("%lld",&n);
	for(i=1;i<=n-1;i++)
	{
		scanf("%lld%lld",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	printf("%lld\n",tw0/2+(tw1+ts1)/2);
	return 0;
}