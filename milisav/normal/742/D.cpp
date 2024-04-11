#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
struct h
{
	int be;
	int we;
};
vector<h> gr[1000];
vector<int> ne[1000];
int knap[1005][1005];
int n,m,w;
int wh[10000];
int bh[10000];
int x,y;
int k;
bool bfsed[1000];
vector<int> q;
void bfs(int beg)
{
	int u=beg;
	bfsed[u]=true;
	int v;
	q.clear();
	q.push_back(u);
	int ind=0;
	int g=q.size();
	int wu=wh[u],bu=bh[u];
	h pom;
	bool m1=false;
	pom.we=wu;
	pom.be=bu;
	//cout<<u<<" "<<wh[u]<<" "<<bh[u]<<endl;
	//cout<<wu<<" "<<bu<<endl;
	gr[k].push_back(pom);
	while(ind<g)
	{
		u=q[ind];
		for(int j=0;j<ne[u].size();j++)
		{
			v=ne[u][j];
			//cout<<u<<" "<<v<<endl;
			if(!bfsed[v])
			{
				bfsed[v]=true;
				m1=true;
				pom.we=wh[v];
				pom.be=bh[v];
				//cout<<wh<<" "<<bh<<endl;
				gr[k].push_back(pom);
				q.push_back(v);
				g++;
				wu+=wh[v];
				bu+=bh[v];
			}
		}
		ind++;
	}
	//cout<<wu<<" "<<bu<<" "<<k<<endl;
	if(m1)
	{
		pom.we=wu;
		pom.be=bu;
		gr[k].push_back(pom);
	}
	k++;
}
int main()
{
	scanf("%d %d %d",&n,&m,&w);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&wh[i]);
		bfsed[i]=false;
	}
	for(int i=0;i<n;i++) scanf("%d",&bh[i]);
	//cout<<m<<endl;
	for(int i=0;i<m;i++) 
	{
		scanf("%d %d",&x,&y);
		x--;
		y--;
		ne[x].push_back(y);
		ne[y].push_back(x);
	}
	//cout<<"eoi"<<endl;
	k=0;
	for(int i=0;i<n;i++)
	{
		if(!bfsed[i])
		{
			bfs(i);
		}
	}
	for(int i=0;i<k;i++)
	{
		//cout<<i<<" iiiiii"<<endl;
		for(int j=0;j<gr[i].size();j++)
		{
			//cout<<gr[i][j].we<<" "<<gr[i][j].be<<endl;
			if(gr[i][j].we<=w && knap[i+1][gr[i][j].we]<gr[i][j].be) knap[i+1][gr[i][j].we]=gr[i][j].be;
			for(int l=0;l<=w;l++)
			{
				if(knap[i][l]!=0)
				{
					if(l+gr[i][j].we<=w && knap[i+1][l+gr[i][j].we]<knap[i][l]+gr[i][j].be) knap[i+1][l+gr[i][j].we]=knap[i][l]+gr[i][j].be;
				}
			}
		}
		for(int l=0;l<=w;l++)
		{
			if(knap[i+1][l]<knap[i][l]) knap[i+1][l]=knap[i][l];
		}
	}
	int res=-1;
	//cout<<k<<endl;
	for(int i=0;i<=k;i++)
	{
		for(int l=0;l<=w;l++)
		{
			if(knap[i][l]>res) res=knap[i][l];
		}
	}
	cout<<res<<endl;
	return 0;
}