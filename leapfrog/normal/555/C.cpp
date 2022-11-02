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
struct SegmentTree
{
	struct node{int ls,rs,tg;}T[10000005];int tt,rt;SegmentTree() {rt=tt=1;}
	inline node& New(int &x) {return x?T[x]:(x=++tt,T[x]=(node){0,0,0});}
	inline void allc(int &x,int dc) {New(x),T[x].tg=max(T[x].tg,dc);}
	inline void pushdw(int x) {allc(T[x].ls,T[x].tg),allc(T[x].rs,T[x].tg);}
	inline void modif(int &x,int l,int r,int dl,int dr,int dc)
	{
		if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allc(x,dc);else pushdw(x);
		modif(T[x].ls,l,(l+r)>>1,dl,dr,dc),modif(T[x].rs,((l+r)>>1)+1,r,dl,dr,dc);
	}
	inline int query(int x,int l,int r,int dw)
	{
		if(!x) return 0;else if(l==r) return T[x].tg;
		if(dw<=((l+r)>>1)) return max(T[x].tg,query(T[x].ls,l,(l+r)>>1,dw));
		else return max(T[x].tg,query(T[x].rs,((l+r)>>1)+1,r,dw));
	}
}L,U;int n,m;
int main()
{
	set<int>st;for(read(n),read(m);m--;)
	{
		int x,y;char ch[5];read(y),read(x),scanf("%s",ch);
		if(st.count(x)) {puts("0");continue;}else st.insert(x);
		if(*ch=='U')
		{
			int rs=L.query(L.rt,1,n,y);printf("%d\n",x-rs);
			U.modif(U.rt,1,n,rs,x,y);
		}
		else
		{
			int rs=U.query(U.rt,1,n,x);printf("%d\n",y-rs);
			L.modif(L.rt,1,n,rs,y,x);
		}
	}
	return 0;
}