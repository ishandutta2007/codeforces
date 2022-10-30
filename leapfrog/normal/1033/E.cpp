//Coded by leapfrog on 2021.10.27 {{{
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
const int N=605;typedef vector<int>vi;int n,fa[N],dep[N];char vs[N];
#ifndef ONLINE_JUDGE
char fg[N][N];int totcnt;
#endif
inline int qry(vi q)
{
	int x=0;if((int)q.size()<2) return 0;
#ifdef ONLINE_JUDGE
	printf("? %d\n",(int)q.size());for(auto x:q) printf("%d ",x);
	putchar('\n'),fflush(stdout);read(x);if(x==-1) exit(0);else return x;
#else
	//printf("? ");for(auto x:q) printf("%d ",x);putchar('\n');
	for(size_t i=0;i<q.size();i++) for(size_t j=i+1;j<q.size();j++) x+=fg[q[i]][q[j]];
	return totcnt++,x;
#endif
}
inline vi split(const vi &a,int l,int r)
{
	vi rs;for(int i=l;i<=r;i++) rs.push_back(a[i]);
	return rs;
}
inline vi merge(const vi &a,const vi &b)
{
	vi r;if(a.size()>b.size()) {r=a;for(auto x:b) r.push_back(x);}
	else {r=b;for(auto x:a) r.push_back(x);}
	return r;
}
inline vi solve(const vi &x,int ls,int l,int r)
{
	int md=(l+r)>>1,vl;vi rs,tmp;
	if(l==r) return rs.push_back(x[l]),dep[x[l]]=dep[fa[x[l]]=ls]+1,rs;
	tmp=split(x,l,md),vl=qry(tmp),tmp.push_back(ls),vl=qry(tmp)-vl;
	for(int i=l;i<=md;i++) vl-=vs[x[i]];
	if(vl) rs=merge(rs,solve(x,ls,l,md));
	tmp=split(x,md+1,r),vl=qry(tmp),tmp.push_back(ls),vl=qry(tmp)-vl;
	for(int i=md+1;i<=r;i++) vl-=vs[x[i]];
	if(vl) rs=merge(rs,solve(x,ls,md+1,r));
	return rs;
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y]) x=fa[x];
	while(x!=y) x=fa[x],y=fa[y];
	return x;
}
inline void NOT(vi v)
{
	int l=0,r=v.size()-1,md=(l+r)>>1;
	for(;l<=r;md=(l+r)>>1)
	{
		if(qry(split(v,l,md))) r=md;
		else if(qry(split(v,md+1,r))) l=md+1;
		else break;
	}int rsl=-1,rsr=-1;
	//printf("!!! %d %d %d\n",l,r,md);
	//printf("VEC : ");for(auto x:v) printf("%d ",x);putchar('\n');
	for(int L=l,R=md,mid=(L+R)>>1;L<=R;mid=(L+R)>>1)
		if(qry(merge(split(v,l,mid),split(v,md+1,r)))) rsl=mid,R=mid-1;else L=mid+1;
	for(int L=md+1,R=r,mid=(L+R)>>1;L<=R;mid=(L+R)>>1)
		if(qry(merge(split(v,rsl,rsl),split(v,L,mid)))) rsr=mid,R=mid-1;else L=mid+1;
	int x=v[rsl],y=v[rsr],lc=LCA(x,y);printf("N %d\n",dep[x]+dep[y]-dep[lc]*2+1);
#ifndef ONLINE_JUDGE
	if(!fg[x][y]) puts("Failed on After"),void();
#endif
	vector<int>tp;while(x!=lc) printf("%d ",x),x=fa[x];
	printf("%d ",lc);while(y!=lc) tp.push_back(y),y=fa[y];
	reverse(tp.begin(),tp.end());for(auto w:tp) printf("%d ",w);
	putchar('\n'),fflush(stdout),exit(0);
}
int main()
{
	queue<int>q;read(n),vs[1]=1,q.push(1);
#ifndef ONLINE_JUDGE
	int m;read(m);for(int i=1,x,y;i<=m;i++) read(x,y),fg[x][y]=fg[y][x]=1;
#endif
	while(!q.empty())
	{
		int x=q.front();q.pop();vi nw;
		for(int i=1;i<=n;i++) if(!vs[i]) nw.push_back(i);
		int qwq=qry(nw);nw.push_back(x),qwq=qry(nw)-qwq,nw.pop_back();if(!qwq) continue;
		vi tp=solve(nw,x,0,nw.size()-1);for(auto x:tp) q.push(x),vs[x]=1;
	}
#ifndef ONLINE_JUDGE
	//for(int i=2;i<=n;i++) printf("%d%c",fa[i],i==n?'\n':' ');
	for(int i=2;i<=n;i++) if(!fg[fa[i]][i]) puts("Failed"),exit(1);
	printf("totcount : %d\n",totcnt);
#endif
	vi tp;for(int i=1;i<=n;i++) if(dep[i]&1) tp.push_back(i);
	if(qry(tp)) return NOT(tp),0;else tp.clear();
	for(int i=1;i<=n;i++) if(!(dep[i]&1)) tp.push_back(i);
	if(qry(tp)) return NOT(tp),0;else printf("Y %d\n",(int)tp.size());
	for(auto x:tp) printf("%d ",x);
	return putchar('\n'),fflush(stdout),0;
}