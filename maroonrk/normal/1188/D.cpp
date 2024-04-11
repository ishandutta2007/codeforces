#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=a;i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	const int inf=LLONG_MAX/3;
	
	int n;cin>>n;
	vi a(n);
	rep(i,n)cin>>a[i];
	int mx=*max_element(all(a));
	for(auto&v:a)v=mx-v;
	
	const int L=60;
	vvc<pi> rs(L);
	for(auto v:a)
		rep(i,L){
			int z=int(1)<<i;
		
			int w=((~v)&(z-1))+1;
			if((v>>i)&1){
				rs[i].eb(0,w);
				rs[i].eb(z+w,z*2);
			}else
				rs[i].eb(w,w+z);
			if(i==L-1)
				rs[i].eb((int(1)<<L)-v,int(1)<<L);
		}
	vi pos{0,int(1)<<L},val{0};
	per(i,L){
		dmp(i);
		dmp(pos);
		dmp(val);
		
		int z=int(1)<<i;
		
		sort(all(rs[i]));
		
		vi np;
		{
			vi tmp{z};
			for(auto r:rs[i]){
				tmp.pb(r.a);
				tmp.pb(r.b);
			}
			sort(all(tmp));
			np.resize(tmp.size()+pos.size());
			merge(all(tmp),all(pos),np.bg);
			np.erase(unique(all(np)),np.ed);
		}
		vi nv(np.size()-1);
		{
			int j=0;
			rep(k,val.size())
				while(np[j]<pos[k+1]){
					nv[j]=val[k];
					j++;
				}
		}
		{
			rep(j,rs[i].size()-1){
				assert(rs[i][j].a<=rs[i][j+1].a);
				assert(rs[i][j].b<=rs[i][j+1].b);
			}
			vi ad(np.size());
			int j=0,k=0;
			for(auto r:rs[i]){
				while(np[j]<r.a)j++;
				while(np[k]<r.b)k++;
				ad[j]++;
				ad[k]--;
			}
			rep(l,nv.size()){
				nv[l]+=ad[l];
				ad[l+1]+=ad[l];
			}
		}
		
		dmp(np);
		dmp(nv);
		
		{
			vi tmp=np;
			pos.resize(np.size());
			int hal=0;
			for(auto&p:tmp){
				if(p>=z)p-=z;
				else hal++;
			}
			merge(tmp.bg,tmp.bg+hal,tmp.bg+hal,tmp.ed,pos.bg);
			pos.erase(unique(all(pos)),pos.ed);
		}
		
		val.clear();
		val.resize(pos.size()-1,inf);
		int j=0;
		rep(k,nv.size()){
			if(np[k]==z)j=0;
			int w=np[k+1];
			dmp(w);
			if(w>z)w-=z;
			dmp(j);
			dmp(k);
			dmp(nv[k]);
			dmp(w);
			while(pos[j]<w){
				dmp(j);
				chmin(val[j],nv[k]);
				j++;
			}
		}
	}
	assert(pos.size()==2);
	assert(val.size()==1);
	cout<<val[0]<<endl;
}