#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;
map<int,map<int,int> > m,vis;
int x0,y0,x1,y1,n,darr[][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
vector<pair<int,int> > v[100005];
int cons(int n)
{
	for (int i=0;i<v[n-1].size();i++)
	{
		for (int x=0;x<8;x++)
		{
			int a=v[n-1][i].first+darr[x][0],b=v[n-1][i].second+darr[x][1];
			if (!m[a][b] || vis[a][b])
			continue;
			v[n].push_back(make_pair(a,b));
			vis[a][b]=1;
			if (a==x1 && b==y1)
			return n;
		}
	}
	if (!v[n].size())
	return -1;
	return cons(n+1);
}
int main()
{
	cin >> x0 >> y0 >> x1 >> y1 >> n;
	for (int i=0;i<n;i++)
	{
		int r,a,b;
		cin >> r >> a >> b;
		for (int i=a;i<=b;i++)
		m[r][i]=1;
	}
	v[0].push_back(make_pair(x0,y0));
	cout << cons(1);
}