#include <bits/stdc++.h>
using namespace std;
char tmp[1000005];
int par[1000005],nex[2][1000005];
vector<int> del[1000005];
int find(int x)
{
	if (par[x]!=x)
	par[x]=find(par[x]);
	return par[x];
}
void Union(int x,int y)
{
	x=find(x);
	y=find(y);
	par[x]=y;
}
int main()
{
	int n;
	scanf("%d %s",&n,tmp);
	string s(tmp);
	nex[0][n]=nex[1][n]=n;
	for (int i=n-1;i>=0;i--)
	{
		nex[0][i]=nex[0][i+1];
		nex[1][i]=nex[1][i+1];
		if (s[i]!='?')
		nex[s[i]-'0'][i]=i;
		del[max(nex[0][i],nex[1][i])-i].push_back(i);
	}
	for (int i=0;i<=n;i++)
	par[i]=i;
	for (int x=1;x<=n;x++)
	{
		int cur=find(0),ans=0;
		while (cur<n)
		{
			ans++;
			cur=find(cur+x);
		}
		for (int i:del[x])
		Union(i,i+1);
		printf("%d ",ans);
	}
}