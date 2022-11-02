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
int n,ch[4000005][2],tt,rt;ll a[100005],s[100005],t[100005];
inline void ins(int &x,ll vl,int d=40)
{
	x?x:x=++tt;if(d<0) return;
	ins(ch[x][(vl>>d)&1],vl,d-1);
}
inline ll qry(int x,ll vl,int d=40)
{
	int nw;if(d<0) return 0;else nw=(vl>>d)&1;
	if(ch[x][!nw]) return qry(ch[x][!nw],vl,d-1)+(1ll<<d);
	else return qry(ch[x][nw],vl,d-1);
}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
	for(int i=n;i>=1;i--) t[i]=t[i+1]^a[i];
	for(int i=0;i<=n;i++) ins(rt,s[i]);
	ll rs=0;for(int i=1;i<=n+1;i++) rs=max(rs,qry(rt,t[i]));
	return printf("%lld\n",rs),0;
}