#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define mid ((l+r)/2)
int T,l,r,ans,cnt[N];
void upd(int l,int r,int qL,int qR)
{
	if(l>=qL && r<=qR)
	{
		for(int i=0;i<=20;++i) if(r>>i&1)
		{
			if(l>>i&1) cnt[i]+=r-l+1;
			else cnt[i]+=(r-l+1)/2;
		}return;
	}if(qL<=mid) upd(l,mid,qL,qR);
	if(qR>mid) upd(mid+1,r,qL,qR);
}
void slv()
{
	scanf("%d %d",&l,&r);ans=0;
	for(int i=0;i<=20;++i) cnt[i]=0;
	upd(0,(1<<20)-1,l,r);
	for(int i=0;i<=20;++i) ans=max(ans,cnt[i]);
	printf("%d\n",r-l-ans+1);
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}