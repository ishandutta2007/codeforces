#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=6000+5;
int dis[MaxN][MaxN];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	int sum=0;
	rep(i,0,n-1)
		rep(j,0,n-1)
		{
			if(dis[i/m][j/m])
				dis[i][j]=(dis[i/m][j/m]+1);
			else if((i%m)!=(j%m))
				dis[i][j]=1;
			sum=max(sum,dis[i][j]);
		}
	cout<<sum<<endl;
	rep(i,0,n-1)
		rep(j,i+1,n-1)
			cout<<dis[i][j]<<' ';
	cout<<endl;
	return 0;
}