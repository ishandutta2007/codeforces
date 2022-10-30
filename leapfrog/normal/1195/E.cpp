#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a,b,x,y,z,g[3005*3005],h[3005][3005],f[3005][3005];deque<int>q,zr;long long ans=0;
signed main()
{
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&n,&m,&a,&b,g,&x,&y,&z);
	for(int i=1;i<=n*m;i++) g[i]=(g[i-1]*x+y)%z;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) h[i][j]=g[(i-1)*m+j-1];
	for(int i=1;i<=n;i++)
	{
		q=zr;
		for(int j=1;j<=m;j++)
		{
			while(!q.empty()&&h[i][q.back()]>=h[i][j]) q.pop_back();
			while(!q.empty()&&q.front()+b-1<j) q.pop_front();
			q.push_back(j),f[i][j]=h[i][q.front()];
		}
	}
	for(int j=1;j<=m;j++)
	{
		q=zr;
		for(int i=1;i<=n;i++)
		{
			while(!q.empty()&&f[q.back()][j]>=f[i][j]) q.pop_back();
			while(!q.empty()&&q.front()+a-1<i) q.pop_front();
			q.push_back(i);if(i>=a&&j>=b) ans+=f[q.front()][j];
		}
	}
	return printf("%lld\n",ans),0;
}