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
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MaxN=310;

int n,k;
int a[MaxN][MaxN];
ld c[MaxN];
ld ans[MaxN];

int main()
{
	cin>>n>>k;
	for (int i=1;i<=n;++i)
		for (int j=0;j<=k;++j)
			scanf("%d",&a[i][j]);
	for (int d=0;d<k;++d)
	{
		for (int i=1;i<=n;++i)
			c[i]=a[i][d+1]-a[i][d];
		vector<ld> p;
		for (int i=1;i<=n;++i)
			for (int j=i+1;j<=n;++j)
			{
				if (c[i]==c[j]) continue;
				ld x=(ld)(a[j][d]-a[i][d])/(c[i]-c[j]);
				if (0<x&&x<1)
					p.push_back(x);
			}
		p.push_back(0);
		p.push_back(1);
		sort(p.begin(),p.end());
		for (int w=0;w<p.size()-1;++w)
		{
			ld v=0,vv=0;
			ld s=0;
			for (int i=1;i<=n;++i)
				if (a[i][d]+p[w]*c[i]>v+1e-8||a[i][d]+p[w+1]*c[i]>vv+1e-8)
				{
					ld t=(p[w+1]-p[w])*(a[i][d]+p[w]*c[i]+a[i][d]+p[w+1]*c[i])/2-s;
					ans[i]+=t;
					s+=t;
					v=a[i][d]+p[w]*c[i];
					vv=a[i][d]+p[w+1]*c[i];
				}
		}
	}
	for (int i=1;i<=n;++i)
		printf("%.10f\n",ans[i]);
	return 0;
}