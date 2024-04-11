#include <bits/stdc++.h>
using namespace std;
#define N 300005
#define M 15
#define STT 1<<8
int n,m,all,l=1,r,ds[N*M],stt[N],a[N][M];
bool vs[STT];vector<int> c[STT];struct node {int x,y;}ans;
node chk(int x)
{
	for(int i=0;i<all;++i) vs[i]=0,c[i].clear();
	for(int i=1;i<=n;++i)
	{
		stt[i]=0;
		for(int j=1;j<=m;++j) if(a[i][j]>=x) stt[i]|=1<<(j-1);
		if(stt[i]==all) return (node) {i,i};vs[stt[i]]=1;c[stt[i]].push_back(i);
	}
	for(int i=1;i<all;++i) if(vs[i])
		for(int j=0;j<i;++j) if(vs[j] && (i|j)==all) return (node) {c[i][0],c[j][0]};
		return (node) {0,0};
}
int main()
{
	scanf("%d %d",&n,&m);all=(1<<m)-1;
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
		scanf("%d",&a[i][j]),ds[++ds[0]]=a[i][j];
	sort(ds+1,ds+ds[0]+1);ds[0]=unique(ds+1,ds+ds[0]+1)-ds-1;r=ds[0];
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
		a[i][j]=lower_bound(ds+1,ds+ds[0]+1,a[i][j])-ds;
	while(l<=r) {int mid=(l+r)>>1;node t=chk(mid);if(t.x) ans=t,l=mid+1;else r=mid-1;}
	printf("%d %d\n",ans.x,ans.y);return 0;
}