#include<iostream>
#include<cstdio>
using namespace std;
long long n,r[222222],b[222222],p[222222],cr,cb,cp,x,ans,rpos,bpos,mxb,mxr;
char c;
int main()
{
	scanf("%I64d",&n);
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d %c",&x,&c);
		if (c=='R') r[++cr]=x;
		else if (c=='B') b[++cb]=x;
		else p[++cp]=x;
	}
	if (!cp)
	{
		printf("%I64d\n",r[cr]-r[1]+b[cb]-b[1]);
		return 0;
	}
	rpos=bpos=1;
	if (cr && r[1]<p[1])
	{
		ans+=(p[1]-r[1]);
		while(rpos<=cr && r[rpos]<p[1]) rpos++;
	}
	if (cb && b[1]<p[1])
	{
		ans+=(p[1]-b[1]);
		while(bpos<=cb && b[bpos]<p[1]) bpos++;
	}
	for (long long i=1;i<cp;i++)
	{
		if (bpos<=cb && b[bpos]<p[i+1])
		{
			mxb=b[bpos]-p[i];
			bpos++;
			while(bpos<=cb && b[bpos]<p[i+1])
			{
				mxb=max(mxb,b[bpos]-b[bpos-1]);
				bpos++;
			}
			mxb=max(mxb,p[i+1]-b[bpos-1]);
		}
		else mxb=p[i+1]-p[i];
		if (rpos<=cr && r[rpos]<p[i+1])
		{
			mxr=r[rpos]-p[i];
			rpos++;
			while(rpos<=cr && r[rpos]<p[i+1])
			{
				mxr=max(mxr,r[rpos]-r[rpos-1]);
				rpos++;
			}
			mxr=max(mxr,p[i+1]-r[rpos-1]);
		}
		else mxr=p[i+1]-p[i];
		ans+=min((p[i+1]-p[i])*2,(p[i+1]-p[i])*3-mxb-mxr);
	}
	if (cr && r[cr]>p[cp]) ans+=(r[cr]-p[cp]);
	if (cb && b[cb]>p[cp]) ans+=(b[cb]-p[cp]);
	printf("%I64d\n",ans);
	return 0;
}