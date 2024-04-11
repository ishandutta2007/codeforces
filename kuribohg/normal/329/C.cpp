#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#include<utility>
using namespace std;
const int MAXN=100010;
int n,m,x,y,p[MAXN];
set<pair<int,int> > S;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		S.insert(make_pair(x,y));
	}
	for(int i=1;i<=n;i++) p[i]=i;
	for(int T=1;T<=100;T++)
	{
		random_shuffle(p+1,p+n+1);
		bool ok=true;
		for(int i=1;i<=m;i++)
		{
			int x=p[i],y=p[i+1];
			if(i==n) y=p[1];
			if(x>y) swap(x,y);
			if(S.count(make_pair(x,y))) {ok=false;break;}
		}
		if(ok)
		{
			for(int i=1;i<=m;i++)
			{
				int x=p[i],y=p[i+1];
				if(i==n) y=p[1];
				printf("%d %d\n",x,y);
			}
			return 0;
		}
	}
	puts("-1");
	return 0;
}