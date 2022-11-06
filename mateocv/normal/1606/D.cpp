#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

pair<ll,ll> NEUT={1e18,-1e18};

pair<ll,ll> oper(pair<ll,ll> a, pair<ll,ll> b){
	return {min(a.fst,b.fst),max(a.snd,b.snd)};
}

struct STree{
	vector<pair<ll,ll> > t; int n;
	STree(int n):t(2*n+5,NEUT),n(n){}
	void upd(int p, pair<ll,ll>  value){
		for(t[p += n]=value;p>1;p>>=1) t[p>>1]=oper(t[p],t[p^1]);
	}
	pair<ll,ll>  query(int l, int r){ // [l, r)
		pair<ll,ll>  res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1) res=oper(res,t[l++]);
			if(r&1) res=oper(res,t[--r]);
		}
		return res;
	}
};

struct pi{
	pair<ll,ll> l,r;
	ll id;
};

bool cmp(pi a, pi b){
	return a.l.snd<b.l.snd;
}

bool mat(pair<ll,ll> a, pair<ll,ll> b){
	return a.snd<b.fst;
}

pair<bool,string> solve(vector<pi> v){
	//cout<<"solve\n";
	//for(auto i:v)cout<<i.l.fst<<" "<<i.l.snd<<" "<<i.r.fst<<" "<<i.r.snd<<" "<<i.id<<"\n";
	sort(ALL(v),cmp);
	//for(auto i:v)cout<<i.l.fst<<" "<<i.l.snd<<" "<<i.r.fst<<" "<<i.r.snd<<" "<<i.id<<"\n";
	STree sl(SZ(v)),sr(SZ(v));
	fore(i,0,SZ(v)){
		sl.upd(i,v[i].l);
		sr.upd(i,v[i].r);
	}
	/*
	fore(i,0,SZ(v)){
		auto q=sl.query(i,i+1);
		cout<<q.fst<<" "<<q.snd<<"\n";
	}
	fore(i,0,SZ(v)){
		auto q=sr.query(i,i+1);
		cout<<q.fst<<" "<<q.snd<<"\n";
	}
	*/
	pair<bool,string> res;
	res.fst=1;
	fore(i,0,SZ(v))res.snd+='R';
	fore(i,0,SZ(v)-1){
		res.snd[v[i].id]='B';
		auto l0=sl.query(0,i+1),l1=sl.query(i+1,SZ(v));
		auto r0=sr.query(0,i+1),r1=sr.query(i+1,SZ(v));
		//cout<<l0.fst<<" "<<l0.snd<<"\n";
		//cout<<l1.fst<<" "<<l1.snd<<"\n";
		//cout<<r0.fst<<" "<<r0.snd<<"\n";
		//cout<<r1.fst<<" "<<r1.snd<<"\n";
		if(mat(l0,l1)&&mat(r1,r0)){
			return res;
		}
	}
	return {0,""};
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<vector<ll>> v(n);
		fore(i,0,n){
			v[i].resize(m);
			fore(j,0,m)cin>>v[i][j];
		}
		STree st(n*m);
		fore(i,0,n){
			fore(j,0,m){
				st.upd(m*i+j,{v[i][j],v[i][j]});
			}
		}
		ll br=0;
		fore(j,1,m){
			vector<pi> vp;
			fore(i,0,n)vp.pb({st.query(m*i,m*i+j),st.query(m*i+j,m*i+m),i});
			auto sol=solve(vp);
			if(sol.fst){
				cout<<"YES\n";
				cout<<sol.snd<<" "<<j<<"\n";
				br++; break;
			}
		}
		if(!br)cout<<"NO\n";
	}
	
	return 0;
}