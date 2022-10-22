#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define db double
int T,n,a[N],b[N];db ans;
void slv()
{
	scanf("%d",&n);ans=a[0]=b[0]=0;
	for(int i=1,x,y;i<=n*2;++i)
	{
		scanf("%d %d",&x,&y);
		if(x) a[++a[0]]=abs(x);else b[++b[0]]=abs(y);
	}sort(a+1,a+n+1);sort(b+1,b+n+1);
	for(int i=1;i<=n;++i)
		ans+=sqrt(1ll*a[i]*a[i]+1ll*b[i]*b[i]);
	printf("%.10lf\n",ans);
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}