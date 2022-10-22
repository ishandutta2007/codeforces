#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
const int inf=100000;
int n;
int a[maxn+5],b[maxn+5];
int check(int mx)
{
	int de=0;
	for(int i=1;i<=n;i++) 
	{
		if(a[i]==0&&b[i]==0) continue;
		if(a[i]==1&&b[i]==0) de--;
		if(a[i]==0&&b[i]==1) de+=mx;
		if(a[i]==1&&b[i]==1) continue;
	} 
	if(de>0) return 1;
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int l=1,r=inf,best=-1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid)) best=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",best);
	return 0;
}