//Coded by STUPID_JUSTlN {{{
//Gened on 2021.10.24 18:05:02
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
const int N=1000005;char ch[N];vector<pair<int,int> >v[N];
int T[N<<2],n,a[N],ps[N],vl[N],st[N],tp,res[N];
inline void chkmn(int &x,int y) {x>y?x=y:x;}
inline void pushdw(int x) {chkmn(T[x<<1],T[x]),chkmn(T[x<<1|1],T[x]);}
const int V=N;int pr[V],pc,ls[V],ph[V],mu[V];char pv[V];//prinit{{{
inline void prinit(int n=V-1)
{
	pv[1]=mu[1]=ph[1]=1,ls[1]=0;for(int i=1;i<=n;i++)
	{
		if(!pv[i]) pr[++pc]=i,mu[i]=-1,ph[i]=i-1,ls[i]=i;
		for(int j=1;j<=pc&&i*pr[j]<=n;j++)
		{
			ls[i*pr[j]]=pr[j],mu[i*pr[j]]=i%pr[j]?-mu[i]:0;
			ph[i*pr[j]]=ph[i]*(pr[j]-!!(i%pr[j]));
			pv[i*pr[j]]=1;if(i%pr[j]==0) break;
		}
	}
}//}}}
inline void build(int x,int l,int r)
{
	if(l==r) return T[x]=n,void();else T[x]=1e9;
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r);
}
inline void modif(int x,int l,int r,int dl,int dr,int dc)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return chkmn(T[x],dc);
	modif(x<<1,l,(l+r)>>1,dl,dr,dc),modif(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc);
}
inline void pull(int x,int l,int r,int *a)
{
	if(l==r) return a[l]=T[x],void();else pushdw(x);
	pull(x<<1,l,(l+r)>>1,a),pull(x<<1|1,((l+r)>>1)+1,r,a);
}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	build(1,1,n),scanf("%s",ch+1),prinit();
	for(int i=1;i<=n;i++)
	{
		int x=a[i];while(ls[x])
		{
			int w=ls[x],cn=0;
			while(x%w==0) cn++,x/=w;
			v[w].push_back(make_pair(i,ch[i]=='*'?cn:-cn));
		}
	}
	for(int k=1;k<=1000000;k++) if(!v[k].empty())
	{
		int tt=v[k].size();for(int i=0;i<tt;i++)
			ps[i+1]=v[k][i].first,vl[i+1]=vl[i]+v[k][i].second;
		st[tp=1]=tt;//ps[i] : (ps[i-1],ps[i]]
		for(int i=tt;i>=1;st[++tp]=--i)
		{
			for(;tp&&vl[st[tp]]>=vl[i-1];tp--);
			if(tp) modif(1,1,n,ps[i-1]+1,ps[i],ps[st[tp]]-1);
		}
	}
	pull(1,1,n,res);ll rs=0;
	for(int i=1;i<=n;i++) rs+=res[i]-i+1;
	return printf("%lld\n",rs),0;
}