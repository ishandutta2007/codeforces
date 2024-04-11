#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define pb push_back
#define eb emplace_back
#define si(x) int(x.size())
#define a first
#define b second
#define mp make_pair

template<class t>using vc=vector<t>;

using pi=pair<int,int>;
using vi=vc<int>;

void NO(){
	cout<<"NO"<<endl;
}

void YES(){
	cout<<"YES"<<endl;
}

template<class t>int lwb(const vc<t>&x,t v){
	return lower_bound(all(x),v)-x.bg;
}

using ld=double;

void slv(){
	vc<tuple<ld,ld,ld>> lr;
	int n,q;cin>>n>>q;
	ld base=0;
	rep(_,n){
		int m;cin>>m;
		vi c(m);rep(j,m)cin>>c[j];
		int cs=accumulate(all(c),int(0));
		vi p(m);rep(j,m)cin>>p[j];
		int ps=accumulate(all(p),int(0));
		
		ld tar=0;
		rep(j,m)tar+=abs(ld(c[j])/cs-ld(p[j])/ps);
		base+=tar;
		
		using P=pair<int,ld>;
		vc<P> cp(m);
		rep(j,m)cp[j]=mp(c[j],ld(p[j])/ps);
		sort(all(cp),[&](P a,P b){
			return a.a/a.b<b.a/b.b;
			//return a.a*b.b<b.a*a.b;
		});
		
		int r=cs;
		ld cur=cs;
		
		//cerr<<cs<<" "<<ps<<endl;
		
		rep(i,m){
			ld nx=cp[i].a/cp[i].b;
			if(cur<nx){
				//cerr<<cur<<" "<<nx<<" "<<2*r<<endl;
				//lr.eb(cur,nx,2*r);
				ld w=2*r;
				lr.eb(-w/(cur*cur),-w/(nx*nx),sqrt(w)/2);
				cur=nx;
			}
			r-=cp[i].a;
		}
	}
	vc<ld> vs;
	for(auto [l,r,w]:lr){
		vs.pb(l);
		vs.pb(r);
	}
	sort(all(vs));
	
	int s=si(vs);
	vc<ld> cnt(s);
	for(auto [l,r,w]:lr){
		cnt[lwb(vs,l)]+=w;
		cnt[lwb(vs,r)]-=w;
	}
	
	auto calccost=[&](ld x){
		return 2/sqrt(-x);
	};
	auto calcval=[&](ld x){
		return -2*sqrt(-x);
	};
	
	rep(i,s-1)cnt[i+1]+=cnt[i];
	vc<ld> cost(s);
	rep(i,s-1)cost[i+1]=cost[i]+cnt[i]*(calccost(vs[i+1])-calccost(vs[i]));
	vc<ld> val(s);
	rep(i,s-1)val[i+1]=val[i]+cnt[i]*(calcval(vs[i+1])-calcval(vs[i]));
	
	rep(_,q){
		ld x;cin>>x;
		int i=lwb(cost,x);
		if(i<s){
			ld w=0;
			if(i>0){
				i--;
				w=val[i];
				ld y=x-cost[i];
				ld lf=vs[i],rt=vs[i+1];
				ld z=calccost(vs[i]);
				rep($,60){
					ld m=(lf+rt)/2;
					if((calccost(m)-z)*cnt[i]<y)lf=m;
					else rt=m;
				}
				w+=(calcval(lf)-calcval(vs[i]))*cnt[i];
			}
			cout<<base-w<<"\n";
		}else{
			cout<<0<<"\n";
		}
	}
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(10);
	
	//int t;cin>>t;
	int t=1;
	rep(_,t)slv();
}