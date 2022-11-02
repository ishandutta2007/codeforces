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
int T;long long n;
inline char check(long long x) {long long y=x;while(y) {int d=y%10;y/=10;if(d&&x%d) return 0;}return 1;}
int main()
{
	for(read(T);T--;)
	{
		read(n);while(!check(n)) n++;
		printf("%lld\n",n);
	}
	return 0;
}