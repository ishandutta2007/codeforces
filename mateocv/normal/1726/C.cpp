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

string s;

#define oper min
#define NEUT {1e9,-1}
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

STree st(200005);

ll solve(ll l, ll r, ll val){
	if(l>=r)return 0;
	vector<ll> v={l-1};
	while(1){
		auto q=st.query(l,r);
		if(q.fst!=val)break;
		v.pb(q.snd);
		st.upd(q.snd,NEUT);
	}
	//v.pb(r);
	ll res=1;
	fore(i,0,SZ(v)-1)res+=solve(v[i]+2,v[i+1],val+1);
	//cout<<"solve "<<l<<" "<<r<<" "<<val<<" "<<res<<"\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		cin>>s;
		ll va=0;
		fore(i,0,SZ(s)){
			if(s[i]=='(')va++;
			else va--;
			st.upd(i,{va,i});
		}
		cout<<solve(0,SZ(s),0)<<"\n";
	}
	
	return 0;
}