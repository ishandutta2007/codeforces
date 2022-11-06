#include<bits/stdc++.h>
using namespace std;
#define re register
int a[200100],b1[200100],c1[200100],mxb[200100],mxc[200100],ta,sta[200100],mta[200100];
int main()
{
	re int n,bg;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++){scanf("%d",&a[i]);if(a[i]==1)bg=i;}
	for(re int i=1;i<=n;i++)c1[(i-bg+n)%n]=b1[(i-bg+n)%n]=a[i];
	reverse(c1+1,c1+n);
	mxb[0]=mxc[0]=1;
	for(re int i=1;i<n;i++)
	{
		mxb[i]=mxb[i-1];
		re int mx=1;
		while(ta&&b1[i]<sta[ta])mx=max(mx+1,mta[ta]+1),ta--;
		sta[++ta]=b1[i];mta[ta]=mx;
		mxb[i]=max(mxb[i],mx+ta);
	}
	ta=0;
	for(re int i=1;i<n;i++)
	{
		mxc[i]=mxc[i-1];
		re int mx=1;
		while(ta&&c1[i]<sta[ta])mx=max(mx+1,mta[ta]+1),ta--;
		sta[++ta]=c1[i];mta[ta]=mx;
		mxc[i]=max(mxc[i],mx+ta);
	}
	re int ans=n+1,nw=0;
	for(re int i=0;i<n;i++)if(ans>max(mxb[i],mxc[n-1-i]))
	{
		ans=max(mxb[i],mxc[n-1-i]);
		nw=(bg+i)%n;
	}
	printf("%d %d\n",ans,nw);
}