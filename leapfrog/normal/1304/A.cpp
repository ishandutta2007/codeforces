//
//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T;long long x,y,a,b;
int main()
{
	for(read(T);T--;)
	{
		read(x),read(y),read(a),read(b);
		if((y-x)%(a+b)) puts("-1");else printf("%lld\n",(y-x)/(a+b));
	}
	return 0;
}