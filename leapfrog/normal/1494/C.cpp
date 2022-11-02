//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int Ca,n,m,ls[200005],nx[200005],a[200005],b[200005],c[200005];
inline void solve()
{
	int res1=0,res2=0;read(n),read(m);for(int i=0;i<=m+3;i++) ls[i]=nx[i]=c[i]=0;
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=m;i++) read(b[i]);
	a[n+1]=b[m+1]=1e9+5,a[0]=b[0]=-a[n+1];
	int wh1;for(int i=1;i<=n+1;i++) if(a[i-1]<0&&a[i]>0) wh1=i;
	int wh2;for(int i=1;i<=m+1;i++) if(b[i-1]<0&&b[i]>0) wh2=i;
	for(int i=wh2;i<=m;i++)
	{
		while(a[wh1]<=b[i]) c[i]++,wh1++;
		if(a[wh1-1]==b[i]) nx[i]++;
	}
	for(int i=m;i>=wh2;i--) nx[i]+=nx[i+1];
	res1=nx[wh2];for(int i=wh2;i<=m;i++) c[i]+=c[i-1];
	for(int i=wh2,qwq;i<=m;i++)
	{
		qwq=lower_bound(b+1,b+m+1,b[i]-c[i]+1)-b;
		res1=max(res1,i-qwq+1+nx[i+1]);
	}
	for(int i=1;i<=n+1;i++) if(a[i-1]<0&&a[i]>0) wh1=i;
	for(int i=1;i<=m+1;i++) if(b[i-1]<0&&b[i]>0) wh2=i;
	wh1--,wh2--;for(int i=wh2;i>=1;i--)
	{
		while(a[wh1]>=b[i]) c[i]++,wh1--;
		if(a[wh1+1]==b[i]) ls[i]++;
	}
	c[wh2+1]=0;for(int i=1;i<=wh2;i++) ls[i]+=ls[i-1];
	for(int i=wh2;i>=1;i--) c[i]+=c[i+1];
	for(int i=wh2,qwq;i>=1;i--)
	{
		if(!c[i]) qwq=i-1;else qwq=upper_bound(b,b+m+1,b[i]+c[i]-1)-b-1;
		res2=max(res2,qwq-i+1+ls[i-1]);
	}
	printf("%d\n",res1+res2);
}
int main() {for(read(Ca);Ca--;) solve();}