#include <bits/stdc++.h>
using namespace std;
#define N 105
#define ll long long
int ans;ll aX,bX,aY,bY,sX,sY,t,X[N],Y[N],dst[N],a[N];
ll max(ll x,ll y) {return x>y?x:y;}
int main()
{
	scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld",&X[0],&Y[0],&aX,&aY,&bX,&bY,&sX,&sY,&t);
	for(int i=0;i<=100;++i)
	{
		if(i) X[i]=aX*X[i-1]+bX,Y[i]=aY*Y[i-1]+bY;dst[i]=abs(X[i]-sX)+abs(Y[i]-sY);
		if(dst[i]<=t) a[++a[0]]=i;if(dst[i]>t && (X[i]>sX || Y[i]>sY)) break;
	}
	for(int i=1;i<=a[0];++i) for(int j=i;j<=a[0];++j)
	{
		ll f=0;
		for(int k=i;k<j;++k) f+=abs(X[a[k]]-X[a[k+1]])+abs(Y[a[k]]-Y[a[k+1]]);
		if(f+abs(sX-X[a[i]])+abs(sY-Y[a[i]])<=t || f+abs(sX-X[a[j]])+abs(sY-Y[a[j]])<=t)
			ans=max(ans,j-i+1);
	}printf("%d\n",ans);return 0;
}