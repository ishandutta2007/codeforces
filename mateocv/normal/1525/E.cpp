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

const ll MOD=998244353;

ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

ll fact[22];

ll solve(vector<ll> v){
	//for(auto i:v)cout<<i<<" ";
	//cout<<"\n";
	ll cant[SZ(v)];
	mset(cant,0);
	for(auto i:v){
		if(i>0)cant[i-1]++;
	}
	ll res=1,va=0;
	fore(i,0,SZ(v)){
		va+=cant[SZ(v)-1-i];
		if(va>0)res=res*va%MOD;
		else res=0;
		va--;
	}
	res=res*fpow(fact[SZ(v)],MOD-2)%MOD;
	res=(MOD+1-res)%MOD;
	//cout<<res<<"\n";
	return res;
}

int main(){FIN;
	fact[0]=1;
	fore(i,1,22)fact[i]=fact[i-1]*i%MOD;
	ll n,m; cin>>n>>m;
	vector<vector<ll>> a(n,vector<ll>(m));
	fore(i,0,n){
		fore(j,0,m)cin>>a[i][j],a[i][j]--;
	}
	ll res=0;
	fore(j,0,m){
		vector<ll> v;
		fore(i,0,n)v.pb(a[i][j]);
		res=(res+solve(v))%MOD;
	}
	cout<<res<<"\n";
	
	return 0;
}