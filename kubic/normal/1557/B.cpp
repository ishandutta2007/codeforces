#include <bits/stdc++.h>
using namespace std;
#define N 100005
int T,n,m,cnt,a[N],b[N],ord[N];
bool cmp(int x,int y) {return a[x]<a[y];}
void slv()
{
	scanf("%d %d",&n,&m);cnt=0;
	for(int i=1;i<=n;++i) ord[i]=i,scanf("%d",&a[i]);
	sort(ord+1,ord+n+1,cmp);
	for(int i=1;i<=n;++i) b[ord[i]]=i;
	for(int i=2;i<=n;++i) if(b[i]!=b[i-1]+1) ++cnt;
	puts(cnt+1<=m?"Yes":"No");
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}