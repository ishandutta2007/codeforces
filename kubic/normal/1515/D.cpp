#include <bits/stdc++.h>
using namespace std;
#define N 200005
int T,n,n1,n2,w1,w2,z1,z2,t,ans,cnt1[N],cnt2[N];
void slv()
{
	scanf("%d %d %d",&n,&n1,&n2);w1=w2=z1=z2=ans=0;
	for(int i=1;i<=n;++i) cnt1[i]=cnt2[i]=0;
	for(int i=1,x;i<=n1;++i) scanf("%d",&x),++cnt1[x];
	for(int i=1,x;i<=n2;++i) scanf("%d",&x),++cnt2[x];
	for(int i=1,t;i<=n;++i)
	{
		t=min(cnt1[i],cnt2[i]);cnt1[i]-=t;cnt2[i]-=t;
		w1+=(cnt1[i]&1);w2+=(cnt2[i]&1);
		z1+=cnt1[i];z2+=cnt2[i];
	}t=min(w1,w2);w1-=t;w2-=t;z1-=t;z2-=t;ans+=t;
	if(w2) swap(w1,w2),swap(z1,z2);
	t=min(w1,z2);w1-=t;z1-=t;z2-=t;ans+=t;
	ans+=(w1+z1+z2)/2;printf("%d\n",ans);
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0; 
}