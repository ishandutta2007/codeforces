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
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=200005;int n,a[N],id[N],b[N],rs[N];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) read(b[i]),id[i]=i;
	sort(id+1,id+n+1,[](int x,int y){return b[x]<b[y];});
	sort(a+1,a+n+1);for(int i=1;i<=n;i++) rs[id[i]]=a[n-i+1];
	for(int i=1;i<=n;i++) printf("%d%c",rs[i],i==n?'\n':' ');
	return 0;
}