#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

int n,m;
pii s,w;

bool go_next(pii s,pii &w)
{
	pii t=w;
	if (s.X==1&&w.X==-1) w.X=1;
	if (s.X==n&&w.X==1) w.X=-1;
	if (s.Y==1&&w.Y==-1) w.Y=1;
	if (s.Y==m&&w.Y==1) w.Y=-1;
	return t!=w;
}

void init()
{
	string t;
	cin>>n>>m>>s.X>>s.Y>>t;
	w=pii(t[0]=='U'?-1:1,t[1]=='L'?-1:1);
}

void work()
{
	ll ans=1;
	set<pii> H;
	H.insert(s);
	for (int _=1;_<=1000000;++_)
	{
		while (go_next(s,w));
		int dx,dy;
		if (w.X==1) dx=n-s.X;
		if (w.X==-1) dx=s.X-1;
		if (w.Y==1) dy=m-s.Y;
		if (w.Y==-1) dy=s.Y-1;
		int t=min(dx,dy);
		ans+=t;
		s=pii(s.X+t*w.X,s.Y+t*w.Y);
		H.insert(s);
		if (H.size()==n+m-2)
		{
			cout<<ans<<endl;
			return;
		}
	}
	cout<<-1<<endl;
}

int main()
{
	init();
	work();
	return 0;
}