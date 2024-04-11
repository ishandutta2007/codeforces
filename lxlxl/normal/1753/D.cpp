#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 510000;
const int mod  = 998244353;

int idn;
int n,m,P,Q;
string a[maxn];

ll dis[maxn];
vector< pair<int,int> >V[maxn];
void ins(const int x,const int y,const int c)
{
	V[x].emplace_back(y,c);
}
priority_queue< pair<ll,int>, vector< pair<ll,int> >, greater< pair<ll,int> > > q;

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin>>n>>m; idn=n*m;
	cin>>P>>Q;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++) for(int j=0;j<m;j++)
	{
		int id=i*m+j;
		
		if(a[i][j]=='L')
		{
			if(j-1>=0&&a[i][j-1]!='#') ins(id-1,id+1,Q);
			if(j+2<m &&a[i][j+2]!='#') ins(id+2,id,Q);
			if(i-1>=0&&a[i-1][j]!='#') ins(id-m,id+1,P);
			if(i-1>=0&&a[i-1][j+1]!='#') ins(id-m+1,id,P);
			if(i+1<n &&a[i+1][j]!='#') ins(id+m,id+1,P);
			if(i+1<n &&a[i+1][j+1]!='#') ins(id+m+1,id,P);
		}
		if(a[i][j]=='U')
		{
			if(i-1>=0&&a[i-1][j]!='#') ins(id-m,id+m,Q);
			if(i+2<n &&a[i+2][j]!='#') ins(id+2*m,id,Q);
			if(j-1>=0&&a[i][j-1]!='#') ins(id-1,id+m,P);
			if(j+1<m &&a[i][j+1]!='#') ins(id+1,id+m,P);
			if(j-1>=0&&a[i+1][j-1]!='#') ins(id+m-1,id,P);
			if(j+1<m &&a[i+1][j+1]!='#') ins(id+m+1,id,P);
		}
	}
	
	for(int i=0;i<idn;i++) dis[i]=LLONG_MAX;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(a[i][j]=='.')
	{
		int id=i*m+j;
		dis[id]=0;
		q.push( make_pair(dis[id],id) );
	}
	while(!q.empty())
	{
		auto [u,v]= q.top(); q.pop();
		if(dis[v]!=u) continue;
		for(auto [y,c]:V[v])
		{
			if(dis[y]>dis[v]+c)
			{
				dis[y]=dis[v]+c;
				q.push(make_pair(dis[y],y));
			}
		}
	}
	
	ll ans=LLONG_MAX;
	int id=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(j+1<m && dis[id]!=LLONG_MAX && dis[id+1]!=LLONG_MAX)
				ans=min(ans, dis[id]+dis[id+1]);
			if(i+1<n && dis[id]!=LLONG_MAX && dis[id+m]!=LLONG_MAX)
				ans=min(ans, dis[id]+dis[id+m]);
			id++;
		}
	}
	if(ans==LLONG_MAX) ans=-1;
	cout<<ans<<endl;
	
	return 0;
}