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

pair<ll,ll> oper(pair<ll,ll> a, pair<ll,ll> b){
	return {a.fst+b.fst,a.snd+b.snd};
}

/*----------------SEGMENT_TREE_ITERATIVO----------------*/
#define NEUT {0,0}
struct STree{
	vector<pair<ll,ll>> t; int n;
	STree(int n):t(2*n+5,NEUT),n(n){}
	void upd(int p, pair<ll,ll> value){
		for(t[p += n]=value;p>1;p>>=1) t[p>>1]=oper(t[p],t[p^1]);
	}
	pair<ll,ll> query(int l, int r){ // [l, r)
		pair<ll,ll> res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1) res=oper(res,t[l++]);
			if(r&1) res=oper(res,t[--r]);
		}
		return res;
	}
};

STree st(100005);

ll countd(ll k, ll rl){
	ll l=0,r=rl;
	while(l<=r){
		ll m=(l+r)/2;
		auto q=st.query(0,m+1);
		if(q.fst<=k)l=m+1;
		else r=m-1;	
	}
	return st.query(0,r+1).snd;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		sort(ALL(a));
		vector<ll> c(n+2);
		for(auto i:a)if(i<=n)c[i]++;
		map<ll,ll> mp;//SZ(mp) cant dif
		for(auto i:a)mp[i]++;
		vector<pair<pair<ll,ll>,pair<ll,ll>>> v;
		for(auto i:mp){
			v.pb({{i.snd,1},{SZ(v),i.fst}});
		}
		auto vs=v;
		sort(ALL(vs));
		vector<ll> u(SZ(v));
		fore(i,0,SZ(vs)){
			u[vs[i].snd.fst]=i;
		}
		fore(i,0,SZ(v)+1)st.upd(i,NEUT);
		vector<ll> sump={0};
		fore(i,0,n+1)sump.pb(sump.back()+!c[i]);
		ll res=1e18;
		ll d=SZ(v);
		for(ll i=n;i>=0;i--){
			if(c[i])continue;
			//cout<<i<<":\n";
			while(SZ(v)&&v.back().snd.snd>i){
				auto b=v.back();
				v.pop_back();
				st.upd(u[b.snd.fst],b.fst);
			}
			//fore(j,0,d)cout<<st.query(j,j+1).fst<<" "<<st.query(j,j+1).snd<<"\n";
			auto s=st.query(0,d);
			if(sump[i]<=k)res=min(res,s.snd-countd(k,d-1));
			//cout<<res<<"\n";
		}
		cout<<res<<"\n";
	}
	
	return 0;
}