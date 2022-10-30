//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
const int P=1e9+7;int n,r[1000005],F[1000005],ls[1000005];char ch[1000005];
int main()
{
	scanf("%s",ch+1),n=strlen(ch+1);for(int i=1;i<=n;i++) if(ch[i]=='0') r[i]=r[i-1]+1;
	for(int i=n;i;i--) F[i]=(F[ls[r[i]+1]]+F[ls[0]]+(r[i]<=r[n]))%P,ls[r[i]]=i;
	if(ls[0]) printf("%lld\n",1ll*F[ls[0]]*ls[0]%P);else printf("%d\n",n);
}