#include <bits/stdc++.h>
using namespace std;
#define N 200005
int T,n,m,c,s[N];char a[N];
void slv()
{
	scanf("%d %d %s",&n,&m,a+1);
	for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i]-48;
	if(1ll*s[n]*m%n) {puts("-1");return;}c=1ll*s[n]*m/n;
	for(int i=m;i<=n;++i) if(s[i]-s[i-m]==c)
	{printf("1\n%d %d\n",i-m+1,i);return;}
	for(int i=1;i<m;++i) if(s[i]+s[n]-s[n-m+i]==c)
	{printf("2\n%d %d\n%d %d\n",1,i,n-m+i+1,n);return;}
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}