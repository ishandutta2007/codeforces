#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int m,a,b,d,l,x,pos,mx,all,dist[444444];
long long ans,L,R,X,XX;
vector<int> g[444444];
priority_queue<pair<int,int> > pq;
int gcd(int a,int b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
long long calc(int l,int x)
{
	long long res=0;
	X=1ll*(l-x)/a+1;
	L=l;R=min(1ll*X*a+x-1,(long long)m);
	res=(R-L+1)*X;
	if (R==m) return res;
	R=m;XX=1ll*(m-x)/a+1;
	L=(XX-1)*a+x;
	res+=(R-L+1)*XX;
	X++;XX--;
	res+=a*((X+XX)*(XX-X+1)/2);
	return res;
}
int main()
{
	cin>>m>>a>>b;
	d=gcd(a,b);
	all=2*(a+b);
	for (int i=0;i<=all;i++)
	{
		if (i+a<=all) g[i].push_back(i+a);
		if (i>=b) g[i].push_back(i-b);  
	}
	dist[0]=0;
	for (int i=1;i<=all;i++) dist[i]=2e9;
	pq.push(make_pair(0,0));
	while(!pq.empty())
	{
		int x=pq.top().second;pq.pop();
		for (int j=0;j<g[x].size();j++)
		{
			int to=g[x][j];
			if (dist[to]>max(to,dist[x]))
			{
				dist[to]=max(to,dist[x]);
				pq.push(make_pair(-dist[to],to)); 
			}
		}
	}
	for (int i=0;i<a;i++)
	{
		if (i%d==0)
		{
			if (i==0) ans+=calc(0,0);
			else
			{
				if (dist[i]>m) continue;
				ans+=calc(dist[i],i);
			}
		}
	}
	printf("%lld\n",ans);
	return Accepted;
}