//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
int a[205],v,n,at;
inline void ckck()
{
	a[0]=1e9+5;while(at<n)
	{
		int wh=0;for(int i=1;i<=at;i++) if(a[i]!=1&&a[i]<a[wh]) wh=i;
		a[wh]=a[wh]/10;for(int i=at+1;i<=at+9;i++) a[i]=a[wh];
		at+=9;
	}
}
inline void solve()
{
	read(v,n);ll vl=1;at=0;while(vl<=v) vl*=10;
	while(vl) {for(int i=1;i<=v/vl;i++) a[++at]=vl;v%=vl,vl/=10;}
	//for(int i=1;i<=at;i++) printf("%d%c",a[i],i==at?'\n':' ');
	ckck();while(at>n) a[at-1]+=a[at],at--;
	for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}