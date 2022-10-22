#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int xs,ys,xe,ye;
char s[200];
int a[200][200];
vector<int> g;
vector<pair<int,int> > l;
bool test()
{
	int xt=xs,yt=ys;
	if(xs==xe && ys==ye) return true;
	for(int i=0;i<k;i++)
	{
		xt+=l[g[s[i]-'0']].first;
		yt+=l[g[s[i]-'0']].second;
		if(xt>=n || yt>=m || xt<0 || yt<0) return false;
		if(a[xt][yt]==-1) return false;
		if(xt==xe && yt==ye) return true;
	}
	return false;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		for(int j=0;j<m;j++)
		{
			if(s[j]=='#') a[i][j]=-1;
			if(s[j]=='S')
			{
				xs=i;
				ys=j;
			}
			if(s[j]=='E')
			{
				xe=i;
				ye=j;
			}
		}
	}
	scanf("%s",s);
	k=strlen(s);
	l.push_back(make_pair(1,0));
	l.push_back(make_pair(-1,0));
	l.push_back(make_pair(0,1));
	l.push_back(make_pair(0,-1));
	g.push_back(0);
	g.push_back(1);
	g.push_back(2);
	g.push_back(3);
	int r=0;
	int h=1;
	if(test()) r++;
	while(next_permutation(g.begin(),g.end()))
	{
		h++;
		if(test()) r++;
	}
	printf("%d",r);
	return 0;
}