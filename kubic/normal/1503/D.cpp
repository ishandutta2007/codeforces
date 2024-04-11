#include <bits/stdc++.h>
using namespace std;
#define N 200005
int n,nw1,nw2,cnt1,cnt2,w1,w2,ans,ps[N],sf[N];bool w[N];
int main()
{
	scanf("%d",&n);
	for(int i=1,l,r;i<=n;++i)
	{
		scanf("%d %d",&l,&r);if(l>r) swap(l,r),w[l]=1;
		if(l>n) {puts("-1");return 0;}ps[l]=r;
	}for(int i=n;i;--i) sf[i]=max(sf[i+1],ps[i]);
	for(int i=1,pr=1e9;i<=n;++i)
	{
		pr=min(pr,ps[i]);
		if(!cnt1 || ps[i]<nw1) nw1=ps[i],++cnt1,w1+=w[i]^1;
		else if(!cnt2 || ps[i]<nw2) nw2=ps[i],++cnt2,w2+=w[i];
		else {puts("-1");return 0;}
		if(pr>sf[i+1])
		{
			ans+=min(w1+w2,cnt1+cnt2-w1-w2);
			nw1=nw2=cnt1=cnt2=w1=w2=0;
		}
	}printf("%d\n",ans);return 0;
}