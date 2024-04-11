#include <bits/stdc++.h>
using namespace std;
#define N 1000005
const int lim=1e6;
int n,ans,a[N];bool tg[N];
int gcd(int x,int y) {return y?gcd(y,x%y):x;}
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;++i) scanf("%d",&a[i]),tg[a[i]]=1;
	for(int i=1,t;i<=lim;++i) if(!tg[i])
	{t=0;for(int j=i;j<=lim;j+=i) if(tg[j]) t=gcd(t,j);if(t==i) ++ans;}
	printf("%d\n",ans);return 0;
}