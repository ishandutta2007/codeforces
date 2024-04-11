#include <bits/stdc++.h>
using namespace std;
#define N 1005
#define M 15
int T,n,ans,a[N],c[N],p[M]={0,2,3,5,7,11,13,17,19,23,29,31};
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ans=0;scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),c[i]=0;
		for(int i=1;i<=11;++i)
		{
			for(int j=1;j<=n;++j) if(!c[j] && !(a[j]%p[i])) {++ans;break;}
			for(int j=1;j<=n;++j) if(!c[j] && !(a[j]%p[i])) c[j]=ans;
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;++i) printf("%d ",c[i]);puts("");
	}return 0;
}