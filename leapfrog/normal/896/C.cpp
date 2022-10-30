#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{int l,r;mutable ll v;bool operator<(node b) const {return l<b.l;}};
int n,m;ll seed,vmax,a[100005];set<node>s;typedef set<node>::iterator it;
inline ll ksm(ll x,int q,ll P) {ll r=1;x%=P;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline it split(int w)
{
	it i=s.lower_bound((node){w,-1,0});
	if(i!=s.end()&&i->l==w) return i;
	--i;int l=i->l,r=i->r;ll v=i->v;
	s.erase(i),s.insert((node){l,w-1,v});
	return s.insert((node){w,r,v}).first;
}
inline void add(int l,int r,ll v)
{
	it le=split(l),ri=split(r+1);
	for(;le!=ri;le++) le->v+=v;
}
inline void cha(int l,int r,ll v) {it le=split(l),ri=split(r+1);s.erase(le,ri),s.insert((node){l,r,v});}
inline ll rnk(int l,int r,int k)
{
	vector<pair<ll,int> >vec;vec.clear();it le=split(l),ri=split(r+1);
	for(;le!=ri;le++) vec.push_back(make_pair(le->v,le->r-le->l+1));
	sort(vec.begin(),vec.end());
	for(int i=0;i<(int)vec.size();i++) {k-=vec[i].second;if(k<=0) return vec[i].first;}
	return -1;
}
inline ll sum(int l,int r,int q,ll P)
{
	it le=split(l),ri=split(r+1);ll res=0;
	for(;le!=ri;le++) res=(res+1ll*(le->r-le->l+1)*ksm(le->v,q,P)%P)%P;
	return res;
}
inline ll rnd() {ll r=seed;seed=(1ll*seed*7+13)%1000000007;return r;}
int main()
{
	scanf("%d%d%lld%lld",&n,&m,&seed,&vmax),s.insert((node){n+1,n+1,0});
	for(int i=1;i<=n;i++) a[i]=rnd()%vmax+1,s.insert((node){i,i,a[i]});
	for(int i=1;i<=m;i++)
	{
		int op=rnd()%4+1,l=rnd()%n+1,r=rnd()%n+1,x,y;if(l>r) swap(l,r);
		if(op==3) x=rnd()%(r-l+1)+1;else {x=rnd()%vmax+1;if(op==4) y=rnd()%vmax+1;}
		if(op==1) add(l,r,x);else if(op==2) cha(l,r,x);else if(op==3) printf("%lld\n",rnk(l,r,x));else printf("%lld\n",sum(l,r,x,y));
	}
	return 0;
}