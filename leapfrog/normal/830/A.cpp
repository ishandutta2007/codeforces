#include<bits/stdc++.h>
using namespace std;
int n,k,p,l,r,mid,a[1005],b[2005];
inline char chck(int x)
{
	for(int i=1,j=0;i<=n;i++)
	{
		while(j<=k) {j++;if(abs(a[i]-b[j])+abs(b[j]-p)<=x) break;}
		if(j>k) return 0;
	}
	return 1;
}
int main()
{
	scanf("%d%d%d",&n,&k,&p),l=0,r=2e9;
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=k;i++) scanf("%d",b+i);
	sort(a+1,a+n+1),sort(b+1,b+k+1);
	while(l<r) {mid=((long long)l+r)>>1;if(chck(mid)) r=mid;else l=mid+1;}
	return printf("%d\n",l),0;
}