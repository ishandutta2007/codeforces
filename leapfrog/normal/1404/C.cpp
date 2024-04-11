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
int n,m,a[300005],T[300005],rs[300005];vector<pair<int,int> >q[300005];
inline void add(int x,int c) {for(;x<=n;x+=x&(-x)) T[x]+=c;}
inline int qry(int x) {int r=0;for(;x;x-=x&(-x)) r+=T[x];return r;}
int main()
{
	read(n),read(m);for(int i=1,x;i<=n;i++) read(x),a[i]=i-x;
	for(int i=1,l,r;i<=m;i++) read(l),read(r),q[n-r].push_back(make_pair(l+1,i));
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0) add(1,1),add(i+1,-1);
		else if(a[i]>0)
		{
			int le=1,ri=i-1,rs=0;
			while(le<=ri) {int md=(le+ri)>>1;if(qry(md)<a[i]) ri=md-1;else rs=md,le=md+1;}
			add(1,1),add(rs+1,-1);
		}
		for(auto x:q[i]) rs[x.second]=qry(x.first);
	}
	for(int i=1;i<=m;i++) printf("%d\n",rs[i]);
	return 0;
}