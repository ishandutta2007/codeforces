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

const ll MOD=998244353,MAXN=300005;

ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

ll fact[MAXN],facti[MAXN];

ll comb(ll n, ll k){
	if(k>n)return 0;
	return fact[n]*(facti[k]*facti[n-k]%MOD)%MOD;
}

int main(){FIN;
	fact[0]=1;
	fore(i,1,MAXN)fact[i]=fact[i-1]*i%MOD;
	fore(i,0,MAXN)facti[i]=fpow(fact[i],MOD-2);
	ll n,m; cin>>n>>m;
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	fore(i,1,n)a[i]+=a[i-1];
	ll s=a.back();
	if(s&1){
		cout<<fpow(m,n)<<"\n";
		return 0;
	}
	set<ll> st;
	for(auto i:a){
		if(i>s/2)st.insert(i-s/2);
	}
	ll c=0;
	for(auto i:a)c+=st.count(i);
	//cout<<"c: "<<c<<"\n";
	ll res=0;
	fore(k,0,min(m,c)+1){
		if(k==m&&k<c)continue;
		ll te=comb(c,k);
		te=te*fact[m]%MOD;
		te=te*facti[m-k]%MOD;
		te=te*fpow(m-k,n-2*k-(c-k))%MOD;
		te=te*fpow(m-k-1,c-k)%MOD;
		res=(res+te)%MOD;
		//cout<<k<<": "<<te<<"\n";
	}
	cout<<res<<"\n";
	
	return 0;
}