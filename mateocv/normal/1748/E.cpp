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
#define NEUT {-1,-1}
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

const ll MOD=1000000007;

STree st(1000006);

ll dp[1000006];

ll n,m;

ll f(ll l, ll r, ll x, ll y){
	//cout<<l<<" "<<r<<" "<<x<<" "<<y<<"\n";
	if(l==r)return 1;
	if(y==-1)return 0;
	ll &res=dp[m*x+y];
	if(res>=0)return res;
	res=f(l,r,x,y-1);
	auto ql=st.query(l,x);
	auto qr=st.query(x+1,r);
	res=(res+f(l,x,-ql.snd,y-1)*f(x+1,r,-qr.snd,y))%MOD;
	//cout<<l<<" "<<r<<" "<<x<<" "<<y<<" : "<<res<<"\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)st.upd(i,{a[i],-i});
		fore(i,0,n){
			fore(j,0,m){
				dp[m*i+j]=-1;
			}
		}
		auto q=st.query(0,n);
		cout<<f(0,n,-q.snd,m-1)<<"\n";
	}
	
	return 0;
}