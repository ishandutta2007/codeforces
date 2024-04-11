#include<bits/stdc++.h>
using namespace std;
int n,m,nn,maxnum,maxlcm,a[1000005],b[1000005],cnt[1000005],ans[1000005];
int main()
{
	scanf("%d%d",&n,&m),memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++) scanf("%d",a+i),b[i]=a[i];
	for(int i=1;i<=n;i++) if(a[i]<=m) ++cnt[a[i]];
	sort(b+1,b+n+1),nn=unique(b+1,b+n+1)-b-1,maxnum=-1;
	for(int i=1;i<=nn&&b[i]<=m;i++) for(int j=b[i];j<=m;j+=b[i]) ans[j]+=cnt[b[i]];
	for(int i=1;i<=m;i++) if(maxnum<ans[i]) maxnum=ans[i],maxlcm=i;
	printf("%d %d\n",maxlcm,maxnum);
	for(int i=1;i<=n;i++) if(maxlcm%a[i]==0) printf("%d ",i);
	return puts(""),0;
}