//
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
int n,a,d;const unsigned long long P=1e9,V=368131125,X=1.2e10;
int main()
{
	read(n),read(a),read(d),printf("%llu %llu\n",V*a%P*X+1,V*d%P*X);
}