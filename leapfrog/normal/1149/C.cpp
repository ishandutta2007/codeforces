//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct node{int s,le,ri,lmx,rmx,lrmx,res;}t[800005];int n,Q;char ch[200005];
inline node operator+(node a,node b)
{
	node r;r.s=a.s+b.s,r.le=max(a.le,a.s+b.le),r.ri=min(b.ri,a.ri+b.s);
	r.lmx=max(a.lmx,max(a.lrmx+b.le,b.lmx-a.s)),r.rmx=max(b.rmx,max(b.lrmx-a.ri,a.rmx+b.s));
	r.lrmx=max(a.lrmx+b.s,b.lrmx-a.s),r.res=max(max(a.res,b.res),max(a.rmx+b.le,b.lmx-a.ri));
	return r;
}
inline void build(int x,int l,int r)
{
	int g;if(l==r) g=ch[l]=='('?1:-1,t[x]=(node){g,max(g,0),min(g,0),1,1,1,1};
	else build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),t[x]=t[x<<1]+t[x<<1|1];
}
inline void updat(int x,int l,int r,int dw)
{
	int g;if(l==r) g=ch[l]=='('?1:-1,t[x]=(node){g,max(g,0),min(g,0),1,1,1,1};
	else if(dw<=((l+r)>>1)) updat(x<<1,l,(l+r)>>1,dw),t[x]=t[x<<1]+t[x<<1|1];
	else updat(x<<1|1,((l+r)>>1)+1,r,dw),t[x]=t[x<<1]+t[x<<1|1];
}
int main()
{
	read(n),read(Q),scanf("%s",ch+1),n<<=1,n-=2,build(1,1,n),printf("%d\n",t[1].res);
	for(int i=1,x,y;i<=Q;i++) read(x),read(y),swap(ch[x],ch[y]),updat(1,1,n,x),updat(1,1,n,y),printf("%d\n",t[1].res);
	return 0;
}