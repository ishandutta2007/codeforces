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

#define oper max
#define NEUT 0
struct STree{
	vector<ll> t; int n;
	STree(int n):t(2*n+5,NEUT),n(n){}
	void upd(int p, ll value){
		for(t[p += n]+=value;p>1;p>>=1) t[p>>1]=oper(t[p],t[p^1]);
	}
	ll query(int l, int r){ // [l, r)
		ll res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1) res=oper(res,t[l++]);
			if(r&1) res=oper(res,t[--r]);
		}
		return res;
	}
};

vector<ll> fact(ll n){
	vector<ll> res;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			res.pb(i);
			while(n%i==0)n/=i;
		}
	}
	if(n>1)res.pb(n);
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		auto p=fact(n);
		//cout<<"p: ";
		//for(auto i:p)cout<<i<<" ";
		//cout<<"\n";
		vector<STree> st(SZ(p),STree(n));
		ll res=0;
		fore(i,0,n){
			fore(j,0,SZ(p)){
				st[j].upd(i%(n/p[j]),a[i]);
			}
		}
		fore(j,0,SZ(p))res=max(res,st[j].query(0,n)*(n/p[j]));
		cout<<res<<"\n";
		while(q--){
			ll pos,val; cin>>pos>>val; pos--;
			fore(j,0,SZ(p))st[j].upd(pos%(n/p[j]),val-a[pos]);
			a[pos]=val;
			res=0;
			fore(j,0,SZ(p))res=max(res,st[j].query(0,n)*(n/p[j]));
			cout<<res<<"\n";
		}
	}
	
	return 0;
}