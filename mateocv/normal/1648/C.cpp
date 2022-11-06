#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const ll MOD=998244353;

const int MAXN=200005;

ll oper(ll x, ll y){
	x+=y;
	if(x>=MOD)x-=MOD;
	return x;
}

#define NEUT 0
struct STree{
	vector<ll> t; int n;
	STree(int n):t(2*n+5,NEUT),n(n){}
	void upd(int p, ll value){
		for(t[p += n]=value;p>1;p>>=1) t[p>>1]=oper(t[p],t[p^1]);
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

ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

ll inv[MAXN],fact[MAXN];

STree st(MAXN);

ll c[MAXN];

int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<ll> a(n),b(m);
	fore(i,0,n)cin>>a[i],a[i]--;
	fore(i,0,m)cin>>b[i],b[i]--;
	inv[0]=0;
	fore(i,1,MAXN)inv[i]=fpow(i,MOD-2);
	fact[0]=1;
	fore(i,1,MAXN)fact[i]=fact[i-1]*i%MOD;
	for(auto i:a)c[i]++;
	fore(i,0,MAXN){
		if(c[i])st.upd(i,c[i]);
	}
	ll cant=1;
	fore(i,0,MAXN)cant=cant*fact[c[i]]%MOD;
	ll res=0;
	ll ul=0;
	fore(i,0,min(n,m)){
		//cout<<i<<":\n";
		ll val=cant*fpow(st.query(0,b[i]),MOD-2)%MOD;
		//cout<<cant<<" "<<st.query(0,b[i])<<" "<<val<<" ";
		val=fact[n-i-1]*fpow(val,MOD-2)%MOD;
		//cout<<val<<"\n";
		res=oper(res,val);
		if(c[b[i]]){
			cant=cant*inv[c[b[i]]]%MOD;
			c[b[i]]--;
			st.upd(b[i],c[b[i]]);
			ul++;
		}else{
			break;
		}
		//cout<<res<<"\n";
	}
	if(n<m&&ul==n){
		assert(cant==1);
		res=oper(res,1);
	}
	cout<<res<<"\n";
	
	return 0;
}