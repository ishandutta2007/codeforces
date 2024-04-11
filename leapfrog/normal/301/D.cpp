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
int n,m,T[200005],a[200005],b[200005],rs[200005];
vector<int>v[200005];vector<pair<int,int> >q[200005];
inline void add(int x,int w) {for(;x;x-=x&(-x)) T[x]+=w;}
inline int qry(int x) {int r=0;for(;x<=n;x+=x&(-x)) r+=T[x];return r;}
int main()
{
	read(n),read(m);for(int i=1;i<=n;i++) read(a[i]),b[a[i]]=i;
	for(int i=1;i<=n;i++) for(int j=i+i;j<=n;j+=i) v[j].push_back(i);
	for(int i=1,l,r;i<=m;i++) read(l),read(r),q[r].push_back(make_pair(l,i));
	for(int i=1;i<=n;i++)
	{
		for(auto x:v[a[i]]) if(b[x]<i) add(b[x],1);
		for(int x=a[i];x<=n;x+=a[i]) if(b[x]<=i) add(b[x],1);
		for(auto x:q[i]) rs[x.second]=qry(x.first);
	}
	for(int i=1;i<=m;i++) printf("%d\n",rs[i]);
	return 0;
}