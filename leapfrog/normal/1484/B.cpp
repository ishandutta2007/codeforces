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
int T,n,m,a[100005],cf[100005];const int INF=-2000000000;
inline void solve()
{
	read(n);int mx=INF;for(int i=1;i<=n;i++) read(a[i]),mx=max(mx,a[i]);
	for(int i=1;i<=n;i++) cf[i]=a[i]-a[i-1];
	int wh1=INF,wh2=INF;
	for(int i=2;i<=n;i++)
	{
		if(cf[i]>=0) if(wh1==INF) wh1=cf[i];else {if(wh1!=cf[i]) return puts("-1"),void();}
		else if(wh2==INF) wh2=-cf[i];else {if(wh2!=-cf[i]) return puts("-1"),void();}
	}
	if(wh1==INF||wh2==INF) return puts("0"),void();
	if(wh1+wh2<=mx) puts("-1");else printf("%d %d\n",wh1+wh2,wh1);
}
int main() {for(read(T);T--;) solve();return 0;}