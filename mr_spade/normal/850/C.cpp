#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#include<map>
using std::map;
const int N=30;
int n,ans;
map<int,int> M,memo;
int sg(int s)
{
	s&=~1;
	if(s==0)
		return 0;
	if(memo.find(s)!=memo.end())
		return memo[s];
	int now;
	bool book[N]={0};
	register int i;
	for(i=1;i<N;i++)
		if(s>>i)
			book[sg((s&((1<<i)-1))|(s>>i))]=1;
	for(now=0;book[now];now++);
	return memo[s]=now;
}
inline void add(int x)
{
	int cnt;
	register int i;
	for(i=2;i*i<=x;i++)
	{
		cnt=0;
		while(x%i==0)
			cnt++,x/=i;
		if(cnt)
			M[i]|=1<<cnt;
	}
	if(x>1)
		M[x]|=2;
	return;
}
signed main()
{
	int _;
	map<int,int>::iterator it;
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&_);
		add(_);
	}
	for(it=M.begin();it!=M.end();it++)
		ans^=sg(it->second);
	puts(ans?"Mojtaba":"Arpa");
	return 0;
}