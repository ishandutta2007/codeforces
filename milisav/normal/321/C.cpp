#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int n;
int a,b;
vector<int> s[200000];
bool centroid[200000];
bool visited[200000];
int child[200000];
char sol[200000];
void DFS(int r)
{
	visited[r]=true;
	child[r]=1;
	int v;
	for(int i=0;i<s[r].size();i++)
	{
		v=s[r][i];
		if(!visited[v] && !centroid[v])
		{
			DFS(v);
			child[r]+=child[v];
		}
	}
	visited[r]=false;
}
int FindCentroid(int r,int m)
{
	visited[r]=true;
	int v;
	int d=-1;
	for(int i=0;i<s[r].size();i++)
	{
		v=s[r][i];
		if(!centroid[v] && !visited[v] && child[v]>m/2)
		{
			d=FindCentroid(v,m);
		}
	}
	visited[r]=false;
	if(d!=-1) return d;
	else return r;
}
int Center(int r)
{
	int m;
	DFS(r);
	m=child[r];
	return FindCentroid(r,m);
}
int GetCentroid(int r,int l)
{
	int cent=Center(r);
	//cout<<cent<<endl;
	sol[cent]=l+'A';
	centroid[cent]=true;
	int v=0;
	for(int i=0;i<s[cent].size();i++)
	{
		v=s[cent][i];
		//cout<<v<<endl;
		if(!centroid[v])
		{
			//cout<<v<<endl;
			GetCentroid(v,l+1);
		}
	}
	return cent;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d %d",&a,&b);
		a--;
		b--;
		s[a].push_back(b);
		s[b].push_back(a);
	}
	/*for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}*/
	GetCentroid(0,0);
	for(int i=0;i<n;i++) printf("%c ",sol[i]);
	return 0;
}