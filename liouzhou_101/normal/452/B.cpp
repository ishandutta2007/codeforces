#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<queue>
#include<list>
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

ld calc(vector<pii> &p)
{
	ld t=0;
	for (int i=0;i<3;++i)
		t+=sqrt((p[i].X-p[i+1].X)*(p[i].X-p[i+1].X)+(p[i].Y-p[i+1].Y)*(p[i].Y-p[i+1].Y));
	return t;
}

vector<pii> solve(int n,int m)
{
	ld best=0;
	vector<pii> v;
	vector<pii> p,tmp;
	p.push_back(pii(0,0));
	p.push_back(pii(0,1));
	p.push_back(pii(1,0));
	p.push_back(pii(0,m));
	p.push_back(pii(0,m-1));
	p.push_back(pii(1,m));
	p.push_back(pii(n,0));
	p.push_back(pii(n,1));
	p.push_back(pii(n-1,0));
	p.push_back(pii(n,m));
	p.push_back(pii(n-1,m));
	p.push_back(pii(n,m-1));
	for (auto a : p)
		if (0<=a.X&&a.X<=n&&0<=a.Y&&a.Y<=m) tmp.push_back(a);
	p=tmp;
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	int k=p.size();
	for (int a1=0;a1<k;++a1)
		for (int a2=0;a2<k;++a2) if (a1!=a2)
			for (int a3=0;a3<k;++a3) if (a3!=a1&&a3!=a2)
				for (int a4=0;a4<k;++a4) if (a4!=a1&&a4!=a2&&a4!=a3)
				{
					vector<pii> w;
					w.push_back(p[a1]);
					w.push_back(p[a2]);
					w.push_back(p[a3]);
					w.push_back(p[a4]);
					ld d=calc(w);
					if (d>best)
					{
						best=d;
						v=w;
					}
				}
	return v;
}

int main()
{
	int n,m;
	cin>>n>>m;
	auto v=solve(n,m);
	for (auto p : v)
		printf("%d %d\n",p.X,p.Y);
	return 0;
}