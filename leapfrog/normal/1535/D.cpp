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
const int N=1000005;int K,n,a[N],Q;char ch[N],s[N];
inline int gt(int x) {for(int i=K-1;~i;i--) {x^=1<<i;if((x>>i)&1) return x;}return -1;}
inline void pushup(int x)
{
	if(ch[x]=='1') a[x]=a[x<<1|1];
	if(ch[x]=='0') a[x]=a[x<<1];
	if(ch[x]=='?') a[x]=a[x<<1]+a[x<<1|1];
}
inline void dfs0(int x)
{
	if((x>>K)&1) return a[x]=1,void();
	dfs0(x<<1),dfs0(x<<1|1),pushup(x);
}
inline void upd(int x) {if(x) pushup(x),upd(x>>1);}
int main()
{
	read(K),n=1<<K,n--,scanf("%s",s+1),dfs0(1),read(Q);for(int i=0;i<n;i++) ch[gt(i)]=s[i+1];
	dfs0(1);for(int x;Q;Q--) read(x),x=gt(x-1),scanf("%s",s),ch[x]=*s,upd(x),printf("%d\n",a[1]);
	return 0;
}