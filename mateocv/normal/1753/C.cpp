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

ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		ll c=0;
		for(auto i:a)c+=i;
		ll cant=0;
		fore(i,0,c)cant+=(a[n-1-i]==0);
		ll res=0;
		ll tot=(n*(n-1)/2)%MOD;
		fore(i,1,cant+1){
			ll te=tot*fpow(i*i%MOD,MOD-2)%MOD;
			res=(res+te)%MOD;
		}
		cout<<res<<"\n";
	}
	
	return 0;
}