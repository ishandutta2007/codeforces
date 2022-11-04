//In the name of Allah
//
//
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#ifndef MY
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif
const int MN=100+10;
bool mark[MN];
vector <int> list[MN];
int d[MN];
int n,t;
int res;
void dfs(int a)
{
	mark[a]=1;
	for (int i=0;i<list[a].size();i++)
	{
		int u=list[a][i];
		if (!mark[u])
		{
			d[u]=d[a]+1;
			dfs(u);
		}
	}
}
int calc()
{
	int r=0;
	for (int i=0;i<n;i++)
	{
		memset(mark,0,sizeof(mark));
		d[i]=0;
		dfs(i);
		for (int j=0;j<n;j++)
			r=max(r,d[j]);
	}
	return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>t;
	for (int i=0;i<t;i++)
	{
		cin>>n;
		for (int i=0;i<n;i++)
			list[i].clear();
		for (int i=1;i<n;i++)
		{
			int a,b;
			cin>>a>>b; a--; b--;
			list[a].push_back(b);
			list[b].push_back(a);
		}
		res+=calc();
	}
	cout<<res<<endl;
	return 0;
}