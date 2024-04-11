//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int a,b,n;ll rs=0;
int main()
{
	read(a),read(b),n=a+b;
	for(int l=1,r,k;l<=n;l=r+1)
	{
		k=n/l,r=n/k;if(a<k||b<k) continue;
		int la=(a+k)/(k+1),ra=a/k,lb=(b+k)/(k+1),rb=b/k;
		if(la<=ra&&lb<=rb) rs+=max(0,min(r,rb+ra)-max(l,la+lb)+1);
	}
	return printf("%lld\n",rs),0;
}