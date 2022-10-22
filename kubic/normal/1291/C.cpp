#include <bits/stdc++.h>
using namespace std;
#define N 3505
int T,n,m,c,ans,a[N];
int min(int x,int y) {return x<y?x:y;}
int max(int x,int y) {return x>y?x:y;}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ans=0;scanf("%d %d %d",&n,&m,&c);--m;if(c>=m) c=m;
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		for(int i=0,t;i<=c;++i)
		{
			t=0x3f3f3f3f;
			for(int j=i;j<=m-c+i;++j) t=min(t,max(a[j+1],a[j+n-m]));
			if(t<0x3f3f3f3f) ans=max(ans,t);
		}printf("%d\n",ans);
	}return 0;
}