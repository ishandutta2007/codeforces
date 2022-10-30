//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int main()
{
	int n,nw=1,f;read(n);
	for(;nw<=n;f=nw&1,nw<<=1,nw|=1,nw+=f) if(n==nw+1||n==nw) return puts("1"),0;
	return puts("0"),0;
}