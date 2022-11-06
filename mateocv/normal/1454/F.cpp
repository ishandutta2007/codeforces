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

const int MAXN=200005;

pair<ll,ll> oper(pair<ll,ll> a, pair<ll,ll> b){
	return {min(a.fst,b.fst),max(a.snd,b.snd)};
}

#define NEUT {2e9,0}
struct STree{
	vector<pair<ll,ll>> t; int n;
	STree(int n):n(n),t(2*n+5,NEUT){}
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

STree st(MAXN);

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)st.upd(i,{a[i],a[i]});
		ll maxi=0,br=0;
		fore(i,0,n){
			maxi=max(maxi,a[i]);
			ll l=i+1,r=n-1;
			while(l<=r){
				ll m=(l+r)/2;
				if(st.query(m,n).snd<=maxi)r=m-1;
				else l=m+1;
			}
			if(st.query(l,n).snd!=maxi)continue;
			auto q0=st.query(i+1,l).fst;
			auto q1=st.query(l,n).snd;
			auto q2=st.query(i+1,l+1).fst;
			auto q3=st.query(l+1,n).snd;
			if(maxi==q0&&maxi==q1){
				cout<<"YES\n"<<i+1<<" "<<l-i-1<<" "<<n-l<<"\n";
				assert(i+1>=0&&l-i-1>=0&&n-l>=0);
				br++; break;
			}
			if(maxi==q2&&maxi==q3){
				cout<<"YES\n"<<i+1<<" "<<l-i<<" "<<n-l-1<<"\n";
				assert(i+1>=0&&l-i>=0&&n-l-1>=0);
				br++; break;
			}
		}
		if(!br)cout<<"NO\n";
	}
	
	return 0;
}