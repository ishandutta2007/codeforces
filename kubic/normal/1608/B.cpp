#include <bits/stdc++.h>
using namespace std;
#define N 200005
int T,n,m1,m2,mn,a[N];bool fl;
void slv()
{
	scanf("%d %d %d",&n,&m1,&m2);mn=1e9;
	if(abs(m1-m2)>1) {puts("-1");return;}
	if(m1+m2>n-2) {puts("-1");return;}fl=m1<m2;
	for(int i=1,l=1,r=0;i<=n;++i)
	{if(fl) a[i]=++r;else a[i]=--l;if(i<m1+m2+2) fl^=1;}
	for(int i=1;i<=n;++i) mn=min(mn,a[i]);
	for(int i=1;i<=n;++i) printf("%d ",a[i]-mn+1);puts("");
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}