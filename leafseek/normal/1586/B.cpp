#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=100000+5;
int u[MaxN];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int T;
	cin>>T;
	int n,m;
	while(T--)
	{
		cin>>n>>m;
		rep(i,1,n) u[i]=false;
		int a,b,c;
		rep(i,1,m)
			cin>>a>>b>>c,u[b]=true;
		rep(i,1,n)
		{
			if(!u[i])
			{
				c=i;
				break;
			}
		}
		rep(i,1,n)
		{
			if(c==i)
				continue;
			cout<<c<<' '<<i<<'\n';
		}
	}
	return 0;
}