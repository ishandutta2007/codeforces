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

STree st(100005);

ll solve(ll l, ll r, ll val){
	if(l==r)return 1;
	auto q=st.query(l,r);
	if(q.fst!=val)return 0;
	return solve(l,q.snd,val+1)&&solve(q.snd+1,r,val);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		reverse(ALL(a));
		ll pos=-1,c=0;
		fore(i,0,n){
			if(a[i]==1){
				pos=i;
				c++;
			}
		}
		if(c!=1){
			cout<<"NO\n";
			continue;
		}
		vector<ll> b;
		fore(i,pos+1,pos+n+1){
			b.pb(a[i%n]);
		}
		fore(i,0,n)st.upd(i,{b[i],i});
		if(solve(0,n-1,2))cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}