#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
using namespace std;
map<long long,int>M;
int n;
long long L[2<<17],R[2<<17];
long long ans[2<<17],sum[4<<17];
main()
{
	scanf("%d",&n);
	vector<long long>a;
	for(int i=0;i<n;i++)
	{
		scanf("%lld%lld",&L[i],&R[i]);
		a.push_back(L[i]);
		a.push_back(R[i]+1);
	}
	sort(a.begin(),a.end());
	a.erase(unique(a.begin(),a.end()),a.end());
	for(int i=0;i<a.size();i++)M[a[i]]=i;
	for(int i=0;i<n;i++)
	{
		sum[M[L[i]]]++;
		sum[M[R[i]+1]]--;
	}
	for(int i=1;i<4<<17;i++)sum[i]+=sum[i-1];
	for(int i=0;i+1<a.size();i++)
	{
		ans[sum[i]]+=a[i+1]-a[i];
	}
	for(int i=1;i<=n;i++)printf("%lld%c",ans[i],i==n?'\n':' ');
}