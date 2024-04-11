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
int n,m,t[600005],mn[600005],mx[600005],wh[300005];
inline int qry(int x) {int r=0;for(;x;x-=x&(-x)) r+=t[x];return r;}
inline void add(int x,int w) {for(;x<=n+m;x+=x&(-x)) t[x]+=w;}
int main()
{
	read(n),read(m);for(int i=1;i<=n;i++) add(wh[i]=i+m,1),mn[i]=mx[i]=i;
	for(int i=m,x;i;i--)
	{
		read(x),mn[x]=1,mx[x]=max(mx[x],qry(wh[x]));
		add(wh[x],-1),wh[x]=i,add(wh[x],1);
	}
	for(int i=1;i<=n;i++) mx[i]=max(mx[i],qry(wh[i]));
	for(int i=1;i<=n;i++) printf("%d %d\n",mn[i],mx[i]);
	return 0;
}