#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
long long n,k;
inline long long check(long long x)
{
	long long rs=0,q=1+!(x&1);
	while(x+q<=n) x<<=1,rs+=q,q<<=1;
	if(n>=x) return n-x+1+rs;else return rs;
}
int main()
{
	read(n),read(k);
	long long l,r,rs1,rs2,md;rs1=rs2=0;
	l=1,r=n>>1;while(l<=r) {md=(l+r)>>1;if(check(md<<1)>=k) rs1=md<<1,l=md+1;else r=md-1;}
	l=0,r=n>>1;while(l<=r) {md=(l+r)>>1;if(check(md<<1|1)>=k) rs2=md<<1|1,l=md+1;else r=md-1;}
	return printf("%lld\n",max(rs1,rs2)),0;
}