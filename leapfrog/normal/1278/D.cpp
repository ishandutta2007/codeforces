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
struct node{int wh,id;char op;char operator<(node b) const {return wh<b.wh;}}t[1000005];
int n,fa[500005],tt,ps[1000005],edg,ri[500005];set<int>st;typedef set<int>::iterator IT;
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
int main()
{
	read(n);for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1,l,r;i<=n;i++)
	{
		read(l),read(r),ps[r]=i,ri[i]=r;
		t[++tt]=(node){l,i,1},t[++tt]=(node){r,i,0};
	}
	sort(t+1,t+tt+1);for(int i=1;i<=tt;i++) if(!t[i].op) st.erase(t[i].wh);
		else
		{
			for(IT j=st.begin();j!=st.end()&&*j<=ri[t[i].id];j++)
			{
				edg++;if(edg>=n) return puts("NO"),0;
				int x=getf(t[i].id),y=getf(ps[*j]);
				if(x^y) fa[x]=y;else return puts("NO"),0;
			}
			st.insert(ri[t[i].id]);
		}
	if(edg<n-1) return puts("NO"),0;else return puts("YES"),0;
}