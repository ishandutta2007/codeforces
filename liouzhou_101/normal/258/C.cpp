#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

const int MaxN=100010;
const int MOD=1000000007;

int n;
int a[MaxN];

long long ans;

int top,Q[MaxN];

long long power(long long x,long long p)
{
	if (!p) return 1;
	long long t=power(x,p>>1);
	t=t*t%MOD;
	if (p&1) t=t*x%MOD;
	return t;
}

int main()
{
	cin>>n;
	int m=0;
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		m=max(a[i],m);
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=m;++i)
	{
		int p=sqrt(i);
		top=0;
		for (int j=1;j<=p;++j)
			if (i%j==0) Q[++top]=j;
		for (int j=p;j>=1;--j)
			if (i%j==0) if (j*j!=i) Q[++top]=i/j;
		for (int j=1;j<=top;++j)
			Q[j]=lower_bound(a+1,a+n+1,Q[j])-a;
		Q[top+1]=n+1;
		long long get=1;
		for (int j=top;j>=1;--j)
		{
			int t=power(j,Q[j+1]-Q[j]);
			if (j==top) t-=power(j-1,Q[j+1]-Q[j]);
			get=get*t%MOD;
		}
		(ans+=get)%=MOD;
	}
	cout<<(ans+MOD)%MOD<<endl;
	return 0;
}