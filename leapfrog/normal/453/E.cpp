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
int n,Q,K[100005],R[100005],id[100005];
struct data{ll k,b;inline data operator+(data x) const {return(data){k+x.k,b+x.b};}};
struct node{int ls,rs;data vl;}T[2000005];int tt,rt[100005];
inline void pushup(int x) {T[x].vl=T[T[x].ls].vl+T[T[x].rs].vl;}
inline void build(int &x,int l,int r)
{
	int md=(l+r)>>1;x=++tt;if(l==r) return T[x].vl=(data){K[l],0},void();
	build(T[x].ls,l,md),build(T[x].rs,md+1,r),pushup(x);
}
inline void modif(int &x,int y,int l,int r,int dw)
{
	T[x=++tt]=T[y];if(l==r) return T[x].vl=(data){0,R[l]},void();
	if(dw<=((l+r)>>1)) modif(T[x].ls,T[y].ls,l,(l+r)>>1,dw),pushup(x);
	else modif(T[x].rs,T[y].rs,((l+r)>>1)+1,r,dw),pushup(x);
}
inline data query(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return(data){0,0};else if(dl<=l&&r<=dr) return T[x].vl;
	return query(T[x].ls,l,(l+r)>>1,dl,dr)+query(T[x].rs,((l+r)>>1)+1,r,dl,dr);
}
struct Chtholly{int l,r;mutable double v;char operator<(Chtholly b) const {return l<b.l;}};
typedef set<Chtholly>::iterator IT;set<Chtholly>S;
inline IT split(int wh)
{
	IT it=S.lower_bound((Chtholly){wh,114,514});
	if(it!=S.end()&&it->l==wh) return it;else it--;
	int l=it->l,r=it->r;double v=it->v;S.erase(it);
	return S.insert((Chtholly){l,wh-1,v}),S.insert((Chtholly){wh,r,v}).first;
}
inline data calc(double vl,int l,int r)
{
	int le=1,ri=n,rs=0;
	while(le<=ri) {int md=(le+ri)>>1;if(R[id[md]]<=vl*K[id[md]]) rs=md,le=md+1;else ri=md-1;}
	return query(rt[rs],1,n,l,r);
}
set<pair<int,int> >s;
inline char cmp(int a,int b) {return 1ll*R[a]*K[b]<1ll*R[b]*K[a];}
int main()
{
	read(n);for(int i=1,x;i<=n;i++)
	{
		read(x),read(R[i]),read(K[i]),id[i]=i;
		if(!R[i]&&!K[i]) R[i]=1;
		if(K[i]) S.insert((Chtholly){i,i,-1.0*x/K[i]});
		else S.insert((Chtholly){i,i,0}),s.insert(make_pair(i,x));
	}
	s.insert(make_pair(n+1,0)),build(rt[0],1,n),sort(id+1,id+n+1,cmp);
	for(int i=1;i<=n;i++) modif(rt[i],rt[i-1],1,n,id[i]);
	for(read(Q);Q--;)
	{
		set<pair<int,int> >::iterator it;int t,l,r;ll res=0;read(t),read(l),read(r);
		while(s.size()>1ull&&(it=s.lower_bound(make_pair(l,0)))->first<=r) res+=it->second,s.erase(it);
		IT ir=split(r+1),il=split(l);for(IT i=il;i!=ir;i++)
			{data x=calc(t-i->v,i->l,i->r);res+=x.b+(ll)(x.k*(t-i->v)+0.5);}
		S.erase(il,ir),S.insert((Chtholly){l,r,1.0*t}),printf("%lld\n",res);
	}
	return 0;
}