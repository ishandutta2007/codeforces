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

vector<string> v;

ll MOD=998244353;

ll be(ll b, ll e, ll mod){
  ll r=1;
  while(e)if(e&1)r=(r*b)%mod,e^=1; else b=(b*b)%mod,e/=2;
  return r;
}

vector<vector<ll>> miniv,minih;

vector<ll> cant;

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,n){
		string s; cin>>s;
		v.pb(s);
	}
	fore(i,0,n){
		miniv.pb({});
		minih.pb({});
		fore(j,0,m){
			if(v[i][j]=='*'){
				miniv[i].pb(0);
				minih[i].pb(0);
			}else{
				if(i==0){
					miniv[i].pb(1);
				}else{
					miniv[i].pb(miniv[i-1][j]+1);
				}
				if(j==0){
					minih[i].pb(1);
				}else{
					minih[i].pb(minih[i][j-1]+1);
				}
			}
		}
	}
	ll c=0;
	fore(i,0,n){
		fore(j,0,m){
			c+=(v[i][j]=='o');
		}
	}
	cant.pb(0);
	cant.pb(0);
	fore(i,2,c+1){
		ll b=cant.back();
		ll bb=cant[SZ(cant)-2];
		if(i%2==0)cant.pb((b+be(2,c-i,MOD))%MOD);
		else cant.pb((bb+be(2,c-i,MOD))%MOD);
	}
	//fore(i,0,5)cout<<cant[i]<<" ";
	//cout<<"\n";
	fore(i,0,c-1)cant.pb(be(2,c-i-1,MOD));
	ll res=0;
	fore(i,0,n){
		fore(j,0,m){
			if(v[i][j]=='o'){
				res=(res+cant[miniv[i][j]])%MOD;
				res=(res+cant[minih[i][j]])%MOD;
			}
		}
	}
	cout<<res<<"\n";
	return 0;
}