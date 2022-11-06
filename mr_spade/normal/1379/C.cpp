#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,m,tot;
int a[N<<1],b[N<<1];
struct cmp
{
	inline bool operator()(int x,int y)
	{
		return max(a[x],b[x])<max(a[y],b[y]);
	}
};
priority_queue<int,vector<int>,cmp> Q;
int run(int n)
{
	if(n==0)
		return 0;
	if(Q.empty())
		return -1;
	int x=Q.top();Q.pop();
	if(a[x]==b[x])
		return n*a[x];
	if(a[x]>b[x])
	{
		a[tot+1]=b[tot+1]=b[x];Q.push(tot+1);tot++;
		return a[x]+run(n-1);
	}
	int res=run(n);
	return max(a[x]+(n-1)*b[x],res);
}
inline void solve()
{
	register int i;
	while(!Q.empty())
		Q.pop();
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m;i++)
		scanf("%lld%lld",&a[i],&b[i]);
	for(i=1;i<=m;i++)
		Q.push(i);
	tot=m;
	printf("%lld\n",run(n));
	return;
}
signed main()
{
	int T;
	scanf("%lld",&T);
	while(T--)
		solve();
	return 0;
}