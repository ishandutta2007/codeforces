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
const int N=100005;int n,X,Y,qz[N],hz[N];char s[N];ll sq[N],sh[N];
int main()
{
	scanf("%s",s+1),n=strlen(s+1),read(X,Y);
	if(X<Y) {swap(X,Y);for(int i=1;i<=n;i++) if(s[i]^'?') s[i]^=1;}
	for(int i=1;i<=n;i++) qz[i]=qz[i-1]+(s[i]!='0');// 0 
	for(int i=n;i>=1;i--) hz[i]=hz[i+1]+(s[i]!='1');// 1 
	for(int i=1;i<=n;i++) sq[i]=sq[i-1]+(s[i]=='0'?1ll*Y*qz[i-1]:1ll*X*(i-1-qz[i-1]));
	for(int i=n;i>=1;i--) sh[i]=sh[i+1]+(s[i]=='1'?1ll*Y*hz[i+1]:1ll*X*(n-i-hz[i+1]));
	//for(int i=1;i<=n;i++) printf("%d %d : %lld %lld\n",qz[i],hz[i],sq[i],sh[i]);
	ll rs=1e18;for(int i=0;i<=n;i++) rs=min(rs,sq[i]+sh[i+1]+1ll*X*(i-qz[i])*(n-i-hz[i+1])+1ll*Y*qz[i]*hz[i+1]);
	return printf("%lld\n",rs),0;
}