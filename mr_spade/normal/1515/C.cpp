#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,x;
int h[N],sum[N];
priority_queue<pair<int,int> > Q;
inline void solve()
{
	register int i;
	cin>>n>>m>>x;
	for(i=1;i<=n;i++)
		cin>>h[i];
	cout<<"YES"<<endl;
	for(i=1;i<=m;i++)
		printf("%d ",i),sum[i]=h[i],Q.push(make_pair(-sum[i],i));
	for(i=m+1;i<=n;i++)
	{
		auto j=Q.top().second;Q.pop();
		printf("%d ",j);
		sum[j]+=h[i];Q.push(make_pair(-sum[j],j));
	}
	puts("");
	while(!Q.empty())
		Q.pop();
	return;
}
signed main()
{
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}