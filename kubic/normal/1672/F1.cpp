#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long
#define pb push_back
int T,n,mx,ps,a[N],b[N],cnt[N];vector<int> vc[N];
bool cmp(int x,int y) {return cnt[x]>cnt[y];}
void slv()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) cnt[i]=0,vc[i].clear();
	for(int i=1;i<=n;++i)
		b[i]=i,scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) ++cnt[a[i]];
	sort(b+1,b+n+1,cmp);b[n+1]=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=cnt[b[i+1]];++j) vc[b[i]].pb(b[i+1]);
		for(int j=cnt[b[i]];j>cnt[b[i+1]];--j) vc[b[i]].pb(b[1]);
	}
	for(int i=1;i<=n;++i)
	{
		printf("%d ",*--vc[a[i]].end());
		vc[a[i]].erase(--vc[a[i]].end());
	}putchar('\n');
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}