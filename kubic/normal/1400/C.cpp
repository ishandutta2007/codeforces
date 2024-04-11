#include <bits/stdc++.h>
using namespace std;
#define N 100005
int T,n,m,ans[N];char a[N];
void slv()
{
	scanf("%s %d",a+1,&m);n=strlen(a+1);
	for(int i=1;i<=n;++i) ans[i]=1;
	for(int i=1;i<=n;++i) if(a[i]=='0')
	{
		if(i-m>=1) ans[i-m]=0;
		if(i+m<=n) ans[i+m]=0;
	}
	for(int i=1;i<=n;++i) if(a[i]=='1')
	{
		int t=0;
		if(i-m>=1) t|=ans[i-m];
		if(i+m<=n) t|=ans[i+m];
		if(!t) {puts("-1");return;}
	}for(int i=1;i<=n;++i) printf("%d",ans[i]);
	puts(""); 
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}