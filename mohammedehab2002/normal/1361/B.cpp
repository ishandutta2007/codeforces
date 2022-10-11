#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int n,p,inv,a[1000005];
long long pow_log(long long x,int y)
{
	long long ret=1;
	for (int i=0;(1<<i)<=y;i++)
	{
		if (y&(1<<i))
		ret=(ret*x)%mod;
		x=(x*x)%mod;
	}
	return ret;
}
long long f(int x)
{
	if (p==1)
	return x;
	return (pow_log(p,x)-1)*inv%mod;
}
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&p);
		inv=pow_log(p-1,mod-2);
		vector<pair<pair<int,int>,int> > v;
		for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
		sort(a,a+n);
		for (int i=n-1;i>=0;i--)
		{
			if (v.empty())
			v.push_back({{a[i],a[i]},1});
			else
			{
				auto tmp=v.back();
				v.pop_back();
				auto tmp2=make_pair(make_pair(tmp.first.first,tmp.first.first),tmp.second);
				tmp.first.first++;
				if (tmp.first.first<=tmp.first.second)
				v.push_back(tmp);
				tmp2.second--;
				if (tmp2.second)
				v.push_back(tmp2);
				if (p!=1 && tmp2.first.first>a[i])
				v.push_back({{a[i],tmp2.first.first-1},p-1});
			}
		}
		int ans=0;
		for (auto i:v)
		{
			ans=(ans+i.second*f(i.first.second+1))%mod;
			ans=(ans-i.second*f(i.first.first)%mod+mod)%mod;
		}
		printf("%d\n",ans);
	}
}