#include<bits/stdc++.h>
using namespace std;
int t,n,a[2000005],b[2000005],lst[2000005];
inline char wrk()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	for(int i=0;i<n;i++) scanf("%d",b+i);
	for(int i=0;i<n;i++) if(b[(i-1+n)%n]+b[i]<a[i]) return 0;
	for(int i=1;i<n;i++)
	{
		if(b[i-1]>=a[i]) lst[i]=a[i],b[i-1]-=a[i];
		else {lst[i]=b[i-1],b[i-1]=0,b[i]-=(a[i]-lst[i]);if(b[i]<0) return 0;}
	}
	for(int i=n-2;i>0;i--) {b[i-1]+=min(b[i],lst[i]);if(b[i-1]<0) return 0;}
	if(b[0]+b[n-1]>=a[0]) return 1;else return 0;
}
int main()
{
	for(scanf("%d",&t);t--;) wrk()?puts("YES"):puts("NO");
	return 0;
}