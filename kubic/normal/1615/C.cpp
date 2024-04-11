#include <bits/stdc++.h>
using namespace std;
#define N 200005
int T,n,ans,cnt[2];char a[N],b[N];
void slv()
{
	scanf("%d %s %s",&n,a+1,b+1);ans=1e9;cnt[0]=cnt[1]=0;
	for(int i=1;i<=n;++i) if(a[i]!=b[i]) ++cnt[a[i]-'0'];
	if(cnt[0]==cnt[1]) ans=cnt[0]+cnt[1];cnt[0]=cnt[1]=0;
	for(int i=1;i<=n;++i) if(a[i]==b[i]) ++cnt[a[i]-'0'];
	if(cnt[0]+1==cnt[1]) ans=min(ans,cnt[0]+cnt[1]);
	if(ans<1e9) printf("%d\n",ans);else puts("-1");
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}