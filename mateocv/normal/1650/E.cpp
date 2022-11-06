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
	return {min(a.fst,b.fst),max(a.snd,b.snd)};
}

#define NEUT {1e9, 0}
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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,d; cin>>n>>d;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll> b={a[0]-1};
		fore(i,1,n)b.pb(a[i]-a[i-1]-1);
		STree st(n+1);
		fore(i,0,n)st.upd(i,{b[i],b[i]});
		ll res=0;
		fore(i,0,n){
			auto q0=st.query(0,i);
			auto q1=st.query(i+2,n);
			pair<ll,ll> q=NEUT;
			if(i<n-1)q={b[i]+b[i+1]+1,b[i]+b[i+1]+1};
			q=oper(q,q0);
			q=oper(q,q1);
			res=max(res,min(q.fst,(q.snd-1)/2));
			res=max(res,min(q.fst,d-1-(i==n-1?a[n-2]:a[n-1])));
		}
		cout<<res<<"\n";
	}
	
	return 0;
}