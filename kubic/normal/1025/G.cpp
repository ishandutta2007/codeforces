#include <bits/stdc++.h>
using namespace std;
#define N 505
#define MOD 1000000007
int n,ans,w[N],cnt[N];bool tg[N];
int add(int x,int y) {x+=y;return x<MOD?x:x-MOD;}
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;++i) w[i]=add(w[i-1]*2,1);ans=w[n-1];
	for(int i=1,x;i<=n;++i) {scanf("%d",&x);if(~x) ++cnt[x];else tg[i]=1;}
	for(int i=1;i<=n;++i) if(tg[i]) ans=add(ans,MOD-w[cnt[i]]);
	printf("%d\n",ans);return 0;
}