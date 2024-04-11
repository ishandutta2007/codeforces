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
set<int>st[128];int n,m,T[200005];char a[200005];
inline void add(int x,int w) {for(;x<=n;x+=x&(-x)) T[x]+=w;}
inline int qry(int x) {int r=0;for(;x;x-=x&(-x)) r+=T[x];return r;}
inline int getwh(int x)
{
	int le=x,ri=n,rs=x;
	while(le<=ri) {int md=(le+ri)>>1;if(md-qry(md)>=x) rs=md,ri=md-1;else le=md+1;}
	return rs;
}
int main()
{
	read(n),read(m),scanf("%s",a+1);for(int i=1;i<=n;i++) st[(int)a[i]].insert(i);
	for(int l,r;m--;)
	{
		char ch[5];read(l),read(r),scanf("%s",ch),l=getwh(l),r=getwh(r);
		set<int>::iterator le=st[(int)*ch].lower_bound(l),ri=le;
		for(;ri!=st[(int)*ch].end()&&*ri<=r;ri++) add(*ri,1);
		st[(int)*ch].erase(le,ri);
	}
	for(int i=1;i<=n;i++) if(!(qry(i)-qry(i-1))) putchar(a[i]);
	return putchar('\n'),0;
}