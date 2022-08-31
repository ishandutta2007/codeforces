#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;

const unsigned long long INF=10000000000000000000ULL;

int n;

struct node
{
	unsigned long long p;
	int a;
}p[110];

bool cmp(node A,node B)
{
	return A.p>B.p;
}

unsigned long long v[110][110];

unsigned long long V,limit0,limit1,ans,x,y,z,s0;

void solve1(int k,unsigned long long s)
{
	if (s>limit1) return;
	if (k>n)
	{
		unsigned long long s1=V/s/s0;
		if (s*s1+s1*s0+s0*s<ans)
		{
			ans=s*s1+s1*s0+s0*s;
			x=s;
			y=s0;
			z=s1;
		}
		return;
	}
	for (int i=p[k].a;i>=0;--i)
		solve1(k+1,s*v[k][i]);
}

void solve0(int k,unsigned long long s)
{
	if (s>limit0) return;
	if (k>n)
	{
		limit1=sqrt((long double)(V/s));
		if (2*s*limit1+limit1*limit1<ans)
		{
			s0=s;
			solve1(1,1);
		}
		return;
	}
	for (int i=p[k].a;i>=0;--i)
	{
		p[k].a-=i;
		solve0(k+1,s*v[k][i]);
		p[k].a+=i;
	}
}

int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n;
		for (int i=1;i<=n;++i)
			cin>>p[i].p>>p[i].a;
		sort(p+1,p+n+1,cmp);
		V=1;
		for (int i=1;i<=n;++i)
		{
			v[i][0]=1;
			for (int j=1;j<=p[i].a;++j)
				v[i][j]=v[i][j-1]*p[i].p;
			V*=v[i][p[i].a];
		}
		ans=INF;
		limit0=pow((long double)V,(long double)1.0/3.0)+1;
		solve0(1,1);
		cout<<ans*2<<" "<<x<<" "<<y<<" "<<z<<endl;
	}
	return 0;
}