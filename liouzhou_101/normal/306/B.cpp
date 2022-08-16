#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<bitset>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=200010;

int n,m;

struct node
{
	int x,y,p;
}p[MaxN];

bool cmp(node A,node B)
{
	return pii(A.x,-A.y)<pii(B.x,-B.y);
}

int u[2000010];
pii c[2000010];

int main()
{
	cin>>n>>m;
	for (int i=1;i<=m;++i)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
		p[i].y=p[i].x+p[i].y-1;
		p[i].p=i;
		u[p[i].x]++;
		u[p[i].y+1]--;
		c[p[i].x]=max(c[p[i].x],pii(p[i].y,i));
	}
	for (int i=1;i<=n+1;++i)
		u[i]+=u[i-1];
	sort(p+1,p+m+1,cmp);
	vector<int> v;
	v.push_back(p[1].p);
	int last=p[1].x;
	int most=p[1].y;
	while (1)
	{
		if (u[most+1])
		{
			pii t(0,0);
			for (int i=last;i<=most+1;++i)
				t=max(t,c[i]);
			last=most+1;
			most=t.X;
			v.push_back(t.Y);
		}
		else
		{
			while (most<=n)
			{
				++most;
				if (u[most]) break;
			}
			if (most>n) break;
			last=most;
			most=c[last].X;
			v.push_back(c[last].Y);
		}
	}
	bitset<MaxN> s;
	s.set();
	for (int i=0;i<v.size();++i)
		s[v[i]]=0;
	cout<<m-v.size()<<endl;
	for (int i=1;i<=m;++i)
		if (s[i]) printf("%d ",i);
	return 0;
}