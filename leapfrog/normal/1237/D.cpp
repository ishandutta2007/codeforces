#include<bits/stdc++.h>
using namespace std;
int n,a[300005],rs[300005],s[300005],b[300005],mx,mn,l,r;
int main()
{
	scanf("%d",&n),mx=0,mn=1000000005,l=0,r=0;
	for(int i=1;i<=n;i++) scanf("%d",a+i),a[n+i]=a[(n<<1)+i]=a[i],mn=min(mn,a[i]),mx=max(mx,a[i]);
	if((mn<<1)>=mx) {for(int i=1;i<=n;i++) printf("-1%c",i==n?'\n':' ');return 0;}
	for(int i=1;i<=n*3;i++)
	{
		while(r>=l&&s[r]<a[i]) r--;
		s[++r]=a[i],b[r]=i;
		while(s[l]>(a[i]<<1)) rs[b[l]]=i-b[l],l++;
	}
	for(int i=n*3;i>=1;i--) if(!rs[i]) rs[i]=rs[i+1]+1;
	for(int i=1;i<=n;i++) printf("%d%c",rs[i],i==n?'\n':' ');
	return 0;
}