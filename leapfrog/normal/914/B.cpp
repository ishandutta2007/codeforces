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
int n,a[100005],cn[100005];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),cn[a[i]]++;
	int mx=0;for(int i=1;i<=n;i++) mx=max(mx,a[i]);
	for(int i=0;i<=mx;i++) if(cn[i]&1) return puts("Conan"),0;
	return puts("Agasa"),0;
}