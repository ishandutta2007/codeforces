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
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=100010;

int n,m,k;
map<int,vector<pii> > a,b;
int s=0;

void deal(map<int,vector<pii> > &a,int n,int m)
{
	if ((m+1-a.size())%2) s^=n;
	for (map<int,vector<pii> >::iterator it=a.begin();it!=a.end();++it)
	{
		sort(it->Y.begin(),it->Y.end());
		vector<pii> v;
		pii p=it->Y[0];
		for (int i=1;i<it->Y.size();++i)
		{
			if (it->Y[i].X>p.Y)
			{
				v.push_back(p);
				p=it->Y[i];
			}
			else
				p.Y=max(p.Y,it->Y[i].Y);
		}
		v.push_back(p);
		it->Y=v;
		int t=0;
		for (int i=0;i<v.size();++i)
			t+=v[i].Y-v[i].X;
		s^=n-t;
	}
}

int search(vector<pii> &v,int L,int R,int get)
{
	int ans=R;
	while (L<=R)
	{
		int m=(L+R)>>1;
		int t=m;
		for (int i=0;i<v.size();++i)
		{
			if (v[i].X>=m) t+=v[i].Y-v[i].X;
			else if (v[i].Y>=m) t+=v[i].Y-m;
		}
		if (t>=get)
		{
			ans=m;
			R=m-1;
		}
		else
			L=m+1;
	}
	return ans;
}

int main()
{
	cin>>n>>m>>k;
	for (int i=1;i<=k;++i)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if (x1==x2)
		{
			if (y1>y2) swap(y1,y2);
			a[x1].push_back(pii(y1,y2));
		}
		else if (y1==y2)
		{
			if (x1>x2) swap(x1,x2);
			b[y1].push_back(pii(x1,x2));
		}
	}
	deal(a,m,n);
	deal(b,n,m);
	if (s)
	{
		puts("FIRST");
		if (a.size()<n)
			for (int i=1;i<n;++i)
			{
				if (!a.count(i))
				{
					a[i];
					break;
				}
			}
		for (map<int,vector<pii> >::iterator it=a.begin();it!=a.end();++it)
		{
			vector<pii> v=it->Y;
			int t=0;
			for (int i=0;i<v.size();++i)
				t+=v[i].Y-v[i].X;
			t=m-t;
			if (!t) continue;
			if ((s^t)>=t) continue;
			int p=search(v,0,m,m-(s^t));
			printf("%d %d %d %d\n",it->X,0,it->X,p);
			return 0;
		}
		if (b.size()<m)
			for (int i=1;i<m;++i)
			{
				if (!b.count(i))
				{
					b[i];
					break;
				}
			}
		for (map<int,vector<pii> >::iterator it=b.begin();it!=b.end();++it)
		{
			vector<pii> v=it->Y;
			int t=0;
			for (int i=0;i<v.size();++i)
				t+=v[i].Y-v[i].X;
			t=n-t;
			if (!t) continue;
			if ((s^t)>=t) continue;
			int p=search(v,0,n,n-(s^t));
			printf("%d %d %d %d\n",0,it->X,p,it->X);
			return 0;
		}
	}
	else
	{
		puts("SECOND");
	}
	return 0;
}