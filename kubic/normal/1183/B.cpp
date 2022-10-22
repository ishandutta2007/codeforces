#include <bits/stdc++.h>
using namespace std;
#define N 105
#define INF 0x3f3f3f3f
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
int T,n,m,t[2],a[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		t[0]=INF;t[1]=0;scanf("%d %d",&n,&m);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),t[0]=min(t[0],a[i]),t[1]=max(t[1],a[i]);
		if(t[0]+(m<<1)<t[1]) puts("-1");else printf("%d\n",t[0]+m);
	}
}