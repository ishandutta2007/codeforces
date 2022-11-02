//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
const int P=1e9+7;char v[200005];int p[200005],pc;
int n,q;vector<pair<int,int> >s[200005];int res=1;
struct node{int ls,rs,vl;}t[14000005];int rt[200005],tt;
inline void pushup(int x) {t[x].vl=min(t[t[x].ls].vl,t[t[x].rs].vl);}
inline void modif(int &x,int l,int r,int dw,int dk)
{
	x?x:x=++tt;if(l==r) return t[x].vl+=dk,void();
	if(dw<=((l+r)>>1)) modif(t[x].ls,l,(l+r)>>1,dw,dk),pushup(x);
	else modif(t[x].rs,((l+r)>>1)+1,r,dw,dk),pushup(x);
}
inline void init()
{
	const int N=200000;v[1]=v[0]=1;
	for(int i=1;i<=N;i++)
	{
		if(!v[i]) p[++pc]=i;
		for(int j=1;j<=pc&&i*p[j]<=N;j++) {v[i*p[j]]=1;if(i%p[j]==0) break;}
	}
	for(int i=1;i<=pc;i++)
	{
		for(int j=1;p[i]*j<=N;j++)
		{
			int t=j,c=0;while(t%p[i]==0) t/=p[i],++c;
			s[p[i]*j].push_back(make_pair(p[i],c+1));
		}
	}
}
inline int ksm(int x,int q) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void solve(int x,int y)
{
	for(auto i:s[y])
	{
		int ls=t[rt[i.first]].vl;modif(rt[i.first],1,n,x,i.second);
		res=1ll*res*ksm(i.first,t[rt[i.first]].vl-ls)%P;
	}
}
int main()
{
	read(n),read(q),init();for(int i=1,x;i<=n;i++) read(x),solve(i,x);
	for(int x,y;q--;) read(x),read(y),solve(x,y),printf("%d\n",res);
	return 0;
}