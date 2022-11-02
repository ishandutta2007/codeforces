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
int n,a[200005],b[200005],l[200005],rs[200005];const int INF=1e9;
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) {read(a[i]),read(b[i]),l[i]=i;if(a[i]>b[i]) swap(a[i],b[i]);}
	sort(l+1,l+n+1,[](int i,int j){return a[i]^a[j]?a[i]<a[j]:b[i]>b[j];});int p=l[1];
	for(int z=1,i=l[z];z<=n;i=l[++z]) if(b[i]>b[p]) rs[i]=p;else p=i,rs[i]=-1;
	for(int i=1;i<=n;i++) printf("%d%c",rs[i],i==n?'\n':' ');
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}