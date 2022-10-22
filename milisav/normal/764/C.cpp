#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> b[300000];
int c[300000];
int a[300000];
bool v[300000];
int x,y;
int n;
void visit(int u)
{
	vector<int> q;
	q.push_back(u);
	int ind=0;
	int w;
	while(ind<q.size())
	{
		w=q[ind];
		v[w]=true;
		for(int j=0;j<b[w].size();j++)
		{
			if(!v[b[w][j]] && c[b[w][j]]==c[u])
			{
				q.push_back(b[w][j]);
			}
		}
		ind++;
	}
	ind=0;
	while(ind<q.size())
	{
		a[q[ind]]=q.size();
		ind++;
	}
}
int main() 
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d %d",&x,&y);
		x--;
		y--;
		b[x].push_back(y);
		b[y].push_back(x);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&c[i]);
		v[i]=false;
	}
	for(int i=0;i<n;i++)
	{
		if(!v[i])
		{
			visit(i);
		}
	}
	int l;
	for(int i=0;i<n;i++)
	{
		l=a[i];
		for(int j=0;j<b[i].size();j++) if(c[i]!=c[b[i][j]]) l+=a[b[i][j]];
		if(l==n)
		{
			printf("YES\n");
			printf("%d\n",i+1);
			return 0;
		}
	}
	printf("NO");
	return 0;
}