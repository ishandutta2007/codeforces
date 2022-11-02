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
int n,K,nw,x;
inline int pls(int x,int y)
{
	int rs=0;for(int vl=1;x||y;x/=K,y/=K)
		{int tp=(x%K+y%K)%K;rs+=vl*tp,vl*=K;}
	return rs;
}
inline int del(int x,int y)
{
	int rs=0;for(int vl=1;x||y;x/=K,y/=K)
		{int tp=(x%K-y%K+K)%K;rs+=vl*tp,vl*=K;}
	return rs;
}
inline void solve()
{
	read(n),read(K),nw=0;
	for(int i=0;i<n;i++)
	{
		int d;if(i&1) d=del(nw,i);else d=pls(nw,i);
		cout<<d<<endl,read(x);if(x) return;else nw=del(d,nw);
	}
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}