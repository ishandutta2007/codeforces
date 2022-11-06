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

ll MOD=1000000007;

ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

ll fact[1010];

ll comb(ll n, ll k){
	if(k>n)return 0;
	return fact[n]*fpow(fact[k]*fact[n-k]%MOD,MOD-2)%MOD;
}

int main(){FIN;
	fact[0]=1;
	fore(i,1,1010)fact[i]=fact[i-1]*i%MOD;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll> aa=a;
		sort(ALL(aa));
		fore(i,0,k-1)aa.pop_back();
		ll ul=aa.back();
		aa=a;
		sort(ALL(aa));
		while(aa.back()!=ul)aa.pop_back(),k--;
		ll tot=0;
		for(auto i:a)tot+=(i==ul);
		//cout<<tot<<" "<<k<<"\n";
		cout<<comb(tot,k)<<"\n";
	}
	
	return 0;
}