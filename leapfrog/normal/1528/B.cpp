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
int n,a[1000005],s[1000005],y[1000005];const int P=998244353;
int main()
{
	read(n);for(int i=1;i<=n;i++) for(int j=i;j<=n;j+=i) y[j]++;
	for(int i=1;i<=n;i++) a[i]=(s[i-1]+y[i])%P,s[i]=(s[i-1]+a[i])%P;
	return printf("%d\n",a[n]),0;
}