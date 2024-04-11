//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
int b,g,n;
int main()
{
	read(b),read(g),read(n);int cnt=0;
	for(int i=0;i<=g;i++) if(n>=i&&n<=b+i) cnt++;
	return printf("%d\n",cnt),0;
}