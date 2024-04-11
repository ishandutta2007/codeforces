#include<iostream>
#include<map>
#include<cstdio>
#include<stdlib.h>
#include<time.h>
#include<vector>
#define pii pair<int,int>
#define mkp make_pair
using namespace std;
int grid[1111111],n,m,x,rows[1111111],cols[1111111];
map<int,vector<pii> > mp;
bool good;
int main()
{
	srand(time(0));
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			scanf("%d",&x);
			mp[x].push_back(mkp(i,j));
		}
	}
	for (map<int,vector<pii> >::iterator i=mp.begin();i!=mp.end();i++)
	{
		vector<pii> v=i->second;
		for (int j=0;j<v.size();j++)
		{
			int x=v[j].first,y=v[j].second;
			grid[x*m+y]=max(rows[x],cols[y])+1;
		}
		for (int j=0;j<v.size();j++)
		{
			int x=v[j].first,y=v[j].second;
			rows[x]=max(rows[x],grid[x*m+y]);
			cols[y]=max(cols[y],grid[x*m+y]);
		}
		good=1;
		while(good)
		{
			good=0;
			for (int j=0;j<v.size();j++)
			{
				int rnd=rand()%(j+1);
				swap(v[j],v[rnd]);
			}
			for (int j=0;j<v.size();j++)
			{
				int x=v[j].first,y=v[j].second;
				int k=max(rows[x],cols[y]);
				if (k>grid[x*m+y])
				{
					good=1;
					grid[x*m+y]=k;
					rows[x]=max(rows[x],k);
					cols[y]=max(cols[y],k);
				}
			}
		}
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		cout<<grid[i*m+j]<<" ";
		cout<<endl;
	}
	return 0;
}