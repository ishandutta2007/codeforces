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
ll n,r=1;
int main()
{
	read(n);for(int i=2;1ll*i*i<=n;i++) if(n%i==0)
		{r*=i;while(n%i==0) n/=i;}
	return printf("%lld\n",r*n),0;
}