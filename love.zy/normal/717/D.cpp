#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <deque>
#include <bitset>
#include <algorithm>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define scan2(x, y) scanf("%d%d", &x, &y)
#define scan3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))

struct mat
{
	int n;
	double m[130][130];

	mat operator * (struct mat b)const
	{
		struct mat ans;
		ans.n=n;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)ans.m[i][j]=0;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				for(int k=0;k<=n;k++)
					ans.m[i][j]+=m[i][k]*b.m[k][j];
		return ans;
	}

	mat operator + (struct mat b)const
	{
		struct mat ans;
		ans.n=n;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)ans.m[i][j]=0;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)ans.m[i][j]=m[i][j]+b.m[i][j];
		return ans;
	}

	mat operator ^ (int t)const
	{
		struct mat ans,p;
		ans.n=p.n=n;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)p.m[i][j]=m[i][j];
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				if(i==j)ans.m[i][j]=1;else ans.m[i][j]=0;
		while(t>0)
		{
			if(t&1)ans=ans*p;
			p=(p*p);
			t=t>>1;
		}
		return ans;
	}

};

int main()
{
	int i,j,n,m;
	double a[130];
	scanf("%d %d",&n,&m);
	memset(a,0,sizeof(a));
	struct mat xs;
	xs.n=127;
	for(i=0;i<=m;i++)scanf("%lf",&a[i]);
	for(i=0;i<=127;i++)
		for(j=0;j<=127;j++)
			xs.m[i][j]=a[i^j];
	struct mat ans=xs^(n-1);
	double tot=1;
	for(i=0;i<=m;i++)tot-=a[i]*ans.m[i][0];
	printf("%.8lf",tot);
    return 0;
}