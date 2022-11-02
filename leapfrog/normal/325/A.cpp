//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename t>inline void read(t &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,mxx,mxy,mnx=1e9,mny=1e9;ll sm=0;
int main()
{
	for(read(n);n--;)
	{
		int x,y,X,Y;read(x),read(y),read(X),read(Y),sm+=1ll*(X-x)*(Y-y);
		mxx=max(mxx,X),mxy=max(mxy,Y),mnx=min(mnx,x),mny=min(mny,y);
	}
	return puts(1ll*(mxx-mnx)*(mxy-mny)==sm&&mxx-mnx==mxy-mny?"YES":"NO"),0;
}