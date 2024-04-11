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
char a[100005],b[100005];int n,at,bt;
int main()
{
	scanf("%s",a+1),n=strlen(a+1);for(int i=1;i<=n;i++) at+=a[i]=='1';
	scanf("%s",b+1),n=strlen(b+1);for(int i=1;i<=n;i++) bt+=b[i]=='1';
	return at+=at&1,puts(at>=bt?"YES":"NO"),0;
}