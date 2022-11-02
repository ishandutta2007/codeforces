//{{{
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}/*}}}*/
int n,m,f[100005];const int P=1e9+7;
int main()
{
	read(n),read(m),f[0]=f[1]=1;for(int i=2;i<=100000;i++) f[i]=(f[i-1]+f[i-2])%P;
	return printf("%lld\n",(f[n]+f[m]-1)*2ll%P),0;
}