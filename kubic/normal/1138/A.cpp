#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
int n,ans,cntA1,a[N],a1[N],a2[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) {scanf("%d",&a[i]);if(a[i]!=a1[cntA1]) a1[++cntA1]=a[i];++a2[cntA1];}
	for(int i=1;i<cntA1;++i) ans=max(ans,min(a2[i],a2[i+1]));printf("%d\n",ans<<1);
}