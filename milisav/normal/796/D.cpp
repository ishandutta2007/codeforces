#include <bits\stdc++.h>
using namespace std;
int n,k,d;
int p[500000];
int m[500000];
int u,v;
vector<pair<int,int> > b[500000];
void bfs()
{
	vector<int> q;
	for(int i=0;i<k;i++)
	{
		if(m[p[i]]==0)
		{
			m[p[i]]=i+1;
			q.push_back(p[i]);
		}
	}
	int ind=0;
	while(ind<q.size())
	{
		u=q[ind];
		for(int j=0;j<b[u].size();j++)
		{
			v=b[u][j].first;
			//cout<<u<<" "<<v<<endl;
			if(m[v]==0)
			{
				m[v]=m[u];
				q.push_back(v);
			}
		}
		ind++;
	}
}
int main()
{
	scanf("%d %d %d",&n,&k,&d);
	for(int i=0;i<k;i++)
	{
		scanf("%d",&p[i]);
		p[i]--;
	}
	for(int i=0;i<n-1;i++)
	{
		scanf("%d %d",&u,&v);
		u--;
		v--;
		b[u].push_back(make_pair(v,i+1));
		b[v].push_back(make_pair(u,i+1));
	}
	bfs();
	int r=0;
	for(int i=0;i<n;i++)
	{
		u=i;
		for(int j=0;j<b[u].size();j++)
		{
			v=b[u][j].first;
			if(v>u && m[u]!=m[v]) r++;
		}
	}
	printf("%d\n",r);
	for(int i=0;i<n;i++)
	{
		//cout<<m[u]<<" ";
		u=i;
		for(int j=0;j<b[u].size();j++)
		{
			v=b[u][j].first;
			if(v>u && m[u]!=m[v])
			{
				printf("%d ",b[u][j].second);
			}
		}
	}
	return 0;
}