#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

ll c[200005];
int z[200005];
pair<ll,int> x[200005];

#define oper(a,b) mp(a.fst+b.fst,a.snd+b.snd)
#define NEUT mp(0,0LL)
struct STree {
	vector<pair<int,ll> > st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void upd(int k, int s, int e, int p, pair<int,ll> v){
		if(s+1==e){st[k]=v;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	ll query(int k, int s, int e, int q){
		if(q==0)return 0LL;
		if(st[k].fst<q)return 1LL<<60;
		if(st[k].fst==q)return st[k].snd;
		if(s+1==e)assert(0);
		int m=(s+e)/2;
		if(st[2*k].fst>=q)return query(2*k,s,m,q);
		return st[2*k].snd+query(2*k+1,m,e,q-st[2*k].fst);
	}
	void upd(int p, pair<int,ll> v){upd(1,0,n,p,v);}
	ll query(int q){
		if(q==0)return 0LL;
		return query(1,0,n,q);
		//auto p=query(1,0,n,q);
		//return p.snd;
	}
};



vector<pair<ll,int> > w[4];
ll s1,s2,s3;
int n,m,k;

int main(){
	scanf("%d%d%d",&n,&m,&k);
	fore(i,0,n)scanf("%lld",c+i);
	int aa;
	scanf("%d",&aa);
	while(aa--){
		int k;
		scanf("%d",&k);k--;
		z[k]|=1<<0;
	}
	scanf("%d",&aa);
	while(aa--){
		int k;
		scanf("%d",&k);k--;
		z[k]|=1<<1;
	}
	fore(i,0,n)x[i]=mp(c[i],z[i]);
	sort(x,x+n);
	fore(i,0,n)w[x[i].snd].pb(mp(x[i].fst,i));

	int asd=min((int)w[3].size(),k);
	if(k-asd>w[1].size()||k-asd>w[2].size()||asd+k-asd+k-asd>m){puts("-1");return 0;}
	STree st(n);
	ll r=1LL<<60;
	fore(i,0,asd)s3+=w[3][i].fst;
	fore(i,0,k-asd)s1+=w[1][i].fst;
	fore(i,0,k-asd)s2+=w[2][i].fst;
	fore(i,asd,w[3].size())st.upd(w[3][i].snd,mp(1,w[3][i].fst));
	fore(i,k-asd,w[1].size())st.upd(w[1][i].snd,mp(1,w[1][i].fst));
	fore(i,k-asd,w[2].size())st.upd(w[2][i].snd,mp(1,w[2][i].fst));
	fore(i,0,w[0].size())st.upd(w[0][i].snd,mp(1,w[0][i].fst));
	r=min(r,s1+s2+s3+st.query(m-(asd+k-asd+k-asd)));//printf("%lld %lld %lld %lld\n",s1,s2,s3,st.query(m-(asd+k-asd+k-asd)));
	for(int q=asd-1;q>=0;--q){
		if(k-q>w[1].size())break;
		if(k-q>w[2].size())break;
		if(q+k-q+k-q>m)break;
		s3-=w[3][q].fst;
		st.upd(w[1][k-q-1].snd,mp(0,0LL));
		st.upd(w[2][k-q-1].snd,mp(0,0LL));
		s1+=w[1][k-q-1].fst;
		s2+=w[2][k-q-1].fst;
		r=min(r,s1+s2+s3+st.query(m-(q+k-q+k-q)));
	}
	if(r==(1LL<<60))puts("-1");
	else printf("%lld\n",r);
	return 0;
}