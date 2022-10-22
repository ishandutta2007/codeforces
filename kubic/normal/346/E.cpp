#include <bits/stdc++.h>
using namespace std;
int T,a,p,n,m;
int slv1(int a,int p,int n,bool fl)
{
	if(p<=n) return 1;if(a>p) a%=p;
	int r=p%a,d=1ll*a*n/p,r1=1ll*a*n%p;
	if(!d) return max(a,(fl?p-a*n:0));
	if(r1<p-r-a) return slv1(r,a,d-1,1);
	return slv1(r,a,d,1);
}
void slv()
{
	scanf("%d %d %d %d",&a,&n,&p,&m);
	puts(slv1(a,p,n,0)<=m?"YES":"NO");
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}