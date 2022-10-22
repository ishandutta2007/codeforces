#include<bits/stdc++.h>
#define ll long long
#define N 300010
using namespace std;
struct dat{int l,r,id,as;}e[N];
bool cmp1(dat a,dat b){return a.l>b.l;}
bool cmp2(dat a,dat b){return a.id<b.id;}
int pr[N][22],sf[N][22],a[N],lst[30],ans[N][30];
int main()
{
	int n,q,i,j,k,t;cin>>n>>q;
	for (i=1;i<=n;i++)
	{
		cin>>a[i];
		t=a[i];
		for (j=0;j<20;j++,t>>=1) if (t&1)
		{
			pr[i][j]=lst[j];sf[lst[j]][j]=i;lst[j]=i;
		}
	}
	for (j=0;j<20;j++)
	{
		pr[i][j]=lst[j];sf[lst[j]][j]=i;lst[j]=i;
	}
	for (i=1;i<=q;i++) cin>>e[i].l>>e[i].r,e[i].id=i;
	memset(ans,100,sizeof(ans));int tmp=1;
	sort(e+1,e+q+1,cmp1);
	for (i=n;i;i--)
	{
		t=a[i];
		for (j=0;j<20;j++,t>>=1) if (t&1)
		{
			int w=sf[i][j];
			for (k=0;k<20;k++) ans[i][k]=min(ans[i][k],ans[w][k]);
			ans[i][j]=i;
		}
		while (e[tmp].l==i)
		{
			e[tmp].as=0;
			for (j=0;j<20;j++) if (a[e[tmp].r]&(1<<j) && ans[i][j]<=e[tmp].r) {e[tmp].as=1;break;}
			tmp++;
		}
	}
	sort(e+1,e+q+1,cmp2);for (i=1;i<=q;i++) if (e[i].as) puts("Shi");else puts("Fou");
}