#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
using namespace std;
const int MAXN=200010;
int n,a[MAXN],f[MAXN],ans=1000000000;
pair<int,int> A[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&A[i].first,&A[i].second);
	sort(A+1,A+n+1);
	for(int i=1;i<=n;i++) a[i]=A[i].first;
	f[1]=0;
	for(int i=2;i<=n;i++)
	{
		int x=lower_bound(a+1,a+n+1,A[i].first-A[i].second)-a-1;
		f[i]=f[x]+i-x-1;
	}
	for(int i=1;i<=n;i++)
		ans=min(ans,f[i]+n-i);
	printf("%d\n",ans);
	return 0;
}