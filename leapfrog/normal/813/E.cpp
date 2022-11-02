//Coded by Kamiyama_Shiki on 2021.11.12 {{{
//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=100005;
int n,K,Q,a[N],ls[N];vector<int>v[N];
struct node{int sz,ls,rs;}T[N*100];int tt,rt[N];
inline void modif(int &x,int y,int l,int r,int dw)
{
	T[x=++tt]=T[y],T[x].sz++;if(l==r) return;
	if(dw<=((l+r)>>1)) modif(T[x].ls,T[y].ls,l,(l+r)>>1,dw);
	else modif(T[x].rs,T[y].rs,((l+r)>>1)+1,r,dw);
}
inline int query(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r||!x) return 0;else if(dl<=l&&r<=dr) return T[x].sz;
	return query(T[x].ls,l,(l+r)>>1,dl,dr)+query(T[x].rs,((l+r)>>1)+1,r,dl,dr);
}
int main()
{
	read(n,K);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++)
	{
		if((int)v[a[i]].size()<K) ls[i]=0;else ls[i]=v[a[i]][v[a[i]].size()-K];
		v[a[i]].push_back(i);
	}
	read(Q);for(int i=1;i<=n;i++) modif(rt[i],rt[i-1],0,n,ls[i]);
	for(int i=1,l,r,rs=0;i<=Q;i++)
	{
		read(l,r),l=(l+rs)%n+1,r=(r+rs)%n+1;if(l>r) swap(l,r);
		printf("%d\n",rs=query(rt[r],0,n,0,l-1)-query(rt[l-1],0,n,0,l-1));
	}
	return 0;
}