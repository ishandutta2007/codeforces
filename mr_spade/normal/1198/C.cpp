#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,cnt;
int book[N];
int match[N];
inline void solve()
{
	int u,v;
	register int i;
	cin>>n>>m;cnt=0;
	memset(book+1,0,sizeof(int)*m);
	memset(match+1,0,sizeof(int)*(3*n));
	for(i=1;i<=m;i++)
	{
		cin>>u>>v;
		if(!match[u]&&!match[v])
			match[u]=match[v]=1,book[i]=1,cnt++;
	}
	if(cnt>=n)
	{
		cout<<"Matching"<<endl;
		cnt=0;
		for(i=1;i<=m;i++)
			if(book[i])
			{
				cout<<i<<' ';
				if(++cnt==n)
					break;
			}
		cout<<endl;
	}
	else
	{
		cout<<"IndSet"<<endl;
		cnt=0;
		for(i=1;i<=3*n;i++)
			if(!match[i])
			{
				cout<<i<<' ';
				if(++cnt==n)
					break;
			}
		cout<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}