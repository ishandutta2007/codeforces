#include<bits/stdc++.h>
using namespace std;
int n,m,prevv[1111],preve[1111],s,t,a[555],b[555],k[555];
int Q[1111],beg,en,mni;
long long dist[1111],h[1111],mn;
bool used[1111];
struct edge
{
	int to,cap,rev;
	long long cost;
};
vector<edge> g[1111];
long long mcf()
{
	long long res=0;
	int flow=0;
	bool fl=0;
	while(1)
	{
		if (!fl)
		{
			queue<int> q;
			for (int i=1;i<=t;i++) dist[i]=1e18;
			memset(used,0,sizeof(used));
			dist[s]=0;
			q.push(s);used[s]=1; 
			while(!q.empty())
			{
				int x=q.front();
				q.pop();used[x]=0;
				for (int i=0;i<g[x].size();i++)
				{
					edge e=g[x][i];
					if (e.cap>0 && dist[e.to]>dist[x]+e.cost)
					{
						dist[e.to]=dist[x]+e.cost;
						prevv[e.to]=x;
						preve[e.to]=i;
						if (!used[e.to])
						{
							used[e.to]=1;
							q.push(e.to); 
						}  
					}
				}
			}
		}
		else
		{
			beg=en=0;
			for (int i=1;i<=t;i++) dist[i]=1e18;
			dist[s]=0;
			Q[en++]=s;
			memset(used,0,sizeof(used));
			used[s]=1;
			while(beg<en)
			{
				mn=1e18;mni=0;
				for (int i=beg;i<en;i++)
				{
					if (dist[Q[i]]<mn)
					{
						mn=dist[Q[i]];
						mni=i;
					}
				}
				int x=Q[mni];
				swap(Q[mni],Q[beg]);beg++;
				for (int i=0;i<g[x].size();i++)
				{
					edge e=g[x][i];
					if (e.cap>0 && dist[e.to]>dist[x]+e.cost+h[x]-h[e.to])
					{
						dist[e.to]=dist[x]+e.cost+h[x]-h[e.to];
						prevv[e.to]=x;
						preve[e.to]=i;
						if (!used[e.to]) 
						{
							used[e.to]=1;
							Q[en++]=e.to;
						}
					}
				}
			}
		}
		fl=1;
		if (dist[t]==1e18) break;
		for (int i=1;i<=t;i++) h[i]+=dist[i];
		int f=1e9;
		for (int i=t;i!=s;i=prevv[i])
		{
			f=min(f,g[prevv[i]][preve[i]].cap);
		}
		if (h[t]>=0) break;
		res-=h[t]*f;flow+=f;
		for (long long i=t;i!=s;i=prevv[i])
		{
			g[prevv[i]][preve[i]].cap-=f;
			g[i][g[prevv[i]][preve[i]].rev].cap+=f;
		}
	}
	return res;
}
void addedge(int s,int t,long long cost,int cap)
{
	g[s].push_back((edge){t,cap,(int)g[t].size(),cost});
	g[t].push_back((edge){s,0,(int)g[s].size()-1,-cost});
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&k[i]);
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<n;j++)
		{
			addedge(i,n+1+j,1ll*b[i]*min(j,k[i])-a[i],1);
		}
	}
	s=2*n+1;t=2*n+2;
	for (int i=1;i<=n;i++)
	{
		addedge(s,i,0,1);
		addedge(n+i,t,0,1);
	}
	printf("%lld\n",mcf());
	return 0;
}