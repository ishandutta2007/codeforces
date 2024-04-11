#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> a[300000];
vector<int> b[300000];
vector<int> t;
int p[300000];
bool k[300000];
int n;
int m;
int u,v;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++) 
	{
		scanf("%d %d",&u,&v);
		u--;
		v--;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(int i=0;i<n;i++)
	{
		p[i]=a[i].size();
		k[i]=false;
	}
	m=n;
	for(int i=0;i<n;i++) if(p[i]==1) t.push_back(i);
	int ind=0;
	int x;
	while(ind<t.size())
	{
		u=t[ind];
		k[u]=true;
		v=-1;
		for(int i=0;i<a[u].size();i++) if(!k[a[u][i]]) v=a[u][i];
		if(v!=-1)
		{
			x=0;
			p[v]--;
			if(p[v]==1) t.push_back(v);
			if(b[u].size()>0)
			{
				x=b[u][0];
				for(int i=1;i<b[u].size();i++)
				{
					if(b[u][i]!=x)
					{
						printf("-1");
						return 0;
					}
				}
			}
			//cout<<u+1<<" "<<x<<" "<<v+1<<" "<<p[v]<<endl;
			b[v].push_back(x+1);
		}
		ind++;
	}
	int r;
	for(int i=0;i<n;i++) if(!k[i]) u=i;
	if(b[u].size()==1) x=b[u][0];
	else
	{
		sort(b[u].begin(),b[u].end());
		x=b[u][0];
		r=1;
		for(int i=1;i<b[u].size();i++)
		{
			if(b[u][i]!=b[u][i-1])
			{
				x+=b[u][i];
				r++;
			}
		}
	}
	if(r>2)
	{
		printf("-1");
		return 0;
	}
	while(x%2==0) x=x/2;
	printf("%d",x);
	return 0;
}