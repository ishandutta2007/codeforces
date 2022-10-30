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
const int N=200005,P=998244353;
int n,m,a[N],b[N],vl[N];map<int,int>mp;
int main()
{
	read(n),read(m);for(int i=1;i<=n;i++) read(a[i]);
	int rs=1;a[n+1]=1e9;for(int i=1;i<=m;i++) read(b[i]);
	for(int i=n;i;i--) a[i]=min(a[i],a[i+1]),mp[a[i]]++;
	if(a[1]!=b[1]) return puts("0"),0;
	for(int i=2;i<=m;i++) rs=1ll*rs*mp[b[i]]%P;
	return printf("%d\n",rs),0;
}