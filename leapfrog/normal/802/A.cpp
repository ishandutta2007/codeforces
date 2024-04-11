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
struct node{int nm,nx;char operator<(node b) const {return nx<b.nx;}};
int n,K,rs,tot,sc[400005];pair<int,int>a[400005];priority_queue<node>q;char b[400005];
int main()
{
	read(n),read(K);for(int i=1;i<=n;i++) read(a[i].first);
	for(int i=n;i;sc[a[i].first]=i,i--) a[i].second=!sc[a[i].first]?1e9:sc[a[i].first];
	for(int i=1;i<=n;q.push((node){i,a[i].second}),i++) if(!b[a[i].first])
	{
		rs++,tot++,b[a[i].first]=1;
		if(tot>K) {tot--;node x=q.top();q.pop(),b[a[x.nm].first]=0;}
	}
	return printf("%d\n",rs),0;
}