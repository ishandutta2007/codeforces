#include <bits/stdc++.h>
using namespace std;
int n,ans;
long long arr[200005];
set<long long> t;
void go(vector<long long> v)
{
	for (long long p:v)
	{
		if (t.find(p)!=t.end())
		continue;
		long long cur=0;
		for (int i=0;i<n;i++)
		{
			if (arr[i]<p)
			cur+=p-arr[i];
			else
			cur+=min(arr[i]%p,p-arr[i]%p);
		}
		ans=min((long long)ans,cur);
		t.insert(p);
	}
}
vector<long long> get(long long x)
{
	vector<long long> p;
	for (int i=2;1LL*i*i<=x;i++)
	{
		if (x%i==0)
		{
			p.push_back(i);
			while (x%i==0)
			x/=i;
		}
	}
	if (x>1)
	p.push_back(x);
	return p;
}
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%I64d",&arr[i]);
	ans=n;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	shuffle(arr,arr+n,rng);
	for (int i=0;i<min(n,25);i++)
	{
		go(get(arr[i]));
		go(get(arr[i]+1));
		go(get(arr[i]-1));
	}
	printf("%d",ans);
}