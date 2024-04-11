#include<bits/stdc++.h>
using namespace std;
int n,a[100005],t[100005],l,r,md,rs;
inline char chk(int k)
{
	int qaq=n-k;for(int i=1;i<=k;i++) t[i<<1]=a[i];
	for(int i=1;i<=k+1;i++) t[(i<<1)-1]=a[qaq++];
	for(int i=1;i<=k;i++) if(t[i<<1]>=t[(i<<1)-1]||t[i<<1]>=t[i<<1|1]) return 0;
	qaq=k+1;for(int i=(k+1)<<1;i<=n;i++) t[i]=a[qaq++];
	return 1;
}
int main()
{
	scanf("%d",&n),l=1,r=(n-1)>>1;for(int i=1;i<=n;i++) scanf("%d",a+i);
	sort(a+1,a+n+1);
	while(l<=r) {md=(l+r)>>1;if(chk(md)) rs=md,l=md+1;else r=md-1;}
	printf("%d\n",rs),chk(rs);for(int i=1;i<=n;i++) printf("%d%c",t[i],i==n?'\n':' ');
	return 0;
}