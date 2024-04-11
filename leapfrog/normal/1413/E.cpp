//
//
#include<bits/stdc++.h>
using namespace std;const int X=303;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T;long long a,b,c,d;
int main()
{
	for(read(T);T--;)
	{
		read(a),read(b),read(c),read(d);
		if(a>b*c) {puts("-1");continue;}
		printf("%lld\n",(((a-1)/b)/d+1)*a-((((a-1)/b)/d+1)-1)*(((a-1)/b)/d+1)/2*b*d);
	}
}