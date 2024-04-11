#include<iostream>
#include<cstdio>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
int n,m,dist[5555555],mx,k;
char s[2222][2222],bst;
int get(int i,int j)
{
	return i*(n+10)+j+1;
}
vector<pair<int,int> > g[5555555];
deque<int> q;
vector<int> v,nv;
void bfs()
{
	for (int i=1;i<=get(n-1,n-1);i++) dist[i]=1e9;
	if (s[0][0]=='a') dist[get(0,0)]=0;
	else dist[get(0,0)]=1;
	q.push_back(get(0,0));
	while(!q.empty())
	{
		int x=q.front();q.pop_front();
		for (int i=0;i<g[x].size();i++)
		{
			int to=g[x][i].first,val=g[x][i].second;
			if (dist[to]>dist[x]+val)
			{
				dist[to]=dist[x]+val;
				if (dist[to]==dist[x]) q.push_front(to);
				else q.push_back(to);  
			}
		}
	 } 
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++)
	{
		scanf("%s",&s[i]);
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (i+1<n)
			{
				if (s[i+1][j]=='a') g[get(i,j)].push_back(make_pair(get(i+1,j),0));
				else g[get(i,j)].push_back(make_pair(get(i+1,j),1));  
			}
			if (j+1<n)
			{
				if (s[i][j+1]=='a') g[get(i,j)].push_back(make_pair(get(i,j+1),0));
				else g[get(i,j)].push_back(make_pair(get(i,j+1),1));  
			}
		}
	}
	bfs();
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (dist[get(i,j)]<=k) mx=max(mx,i+j+1);
		}
	}
	for (int i=1;i<=mx;i++) putchar('a');
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (dist[get(i,j)]<=k && i+j+1==mx) 
			{
				if (j+1<n) v.push_back(i); 
				if (i+1<n) v.push_back(i+1); 
			}
		}
	}
	if (!mx) v.push_back(0); 
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	while(mx<=2*n-2)
	{
		nv.clear();bst='z';
		for (int i=0;i<v.size();i++) 
		{
			if (s[v[i]][mx-v[i]]>bst) continue;
			if (s[v[i]][mx-v[i]]<bst)
			{
				nv.clear();
				if (v[i]+1<n) nv.push_back(v[i]+1);
				if (mx-v[i]+1<n) nv.push_back(v[i]);
				bst=s[v[i]][mx-v[i]];
			}
			else 
			{
				if (v[i]+1<n) nv.push_back(v[i]+1);
				if (mx-v[i]+1<n) nv.push_back(v[i]);
			}
		}
		printf("%c",bst);
		mx++;
		sort(nv.begin(),nv.end());
		nv.resize(unique(nv.begin(),nv.end())-nv.begin());
		v=nv;
	}
	printf("\n");
	return 0;
}