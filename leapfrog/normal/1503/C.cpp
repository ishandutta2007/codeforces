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
struct node{int a,c;bool operator<(node y) const {return a<y.a;}}a[100005];int n,mx;ll res=0;
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i].a),read(a[i].c),res+=a[i].c;
	sort(a+1,a+n+1);for(int i=1;i<=n;i++) res+=max(0,a[i+1].a-(mx=max(mx,a[i].a+a[i].c)));
	return printf("%lld\n",res),0;
}