#include <bits/stdc++.h>
using namespace std;
int a[100005],pc[100005];
long long f(int l,int p)
{
	long long tmp=l/p;
	return (l%p)*(tmp+1)*(tmp+1)+(p-l%p)*tmp*tmp;
}
struct cmp
{
	bool operator()(const int &i,const int &j) const
	{
		long long ai=f(a[i],pc[i])-f(a[i],pc[i]+1),aj=f(a[j],pc[j])-f(a[j],pc[j]+1);
		if (ai==aj)
		return (i<j);
		return (ai>aj);
	}
};
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	set<int,cmp> s;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		pc[i]=1;
		if (a[i]>1)
		s.insert(i);
	}
	for (int _=0;_<k-n;_++)
	{
		int i=*s.begin();
		s.erase(s.begin());
		pc[i]++;
		if (pc[i]!=a[i])
		s.insert(i);
	}
	long long ans=0;
	for (int i=1;i<=n;i++)
	ans+=f(a[i],pc[i]);
	printf("%I64d",ans);
}