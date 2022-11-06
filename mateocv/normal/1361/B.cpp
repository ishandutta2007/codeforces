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

ll be(ll b, ll e, ll mod){
  ll r=1;
  while(e)if(e&1)r=(r*b)%mod,e^=1; else b=(b*b)%mod,e/=2;
  return r;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,p; cin>>n>>p;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		sort(a,a+n);
		if(p==1){
			if(n%2==1)cout<<1<<"\n";
			else cout<<"0\n";
			continue;
		}
		reverse(a,a+n);
		vector<ll> v[2];
		fore(i,0,n){
			if(SZ(v[0])==0&&SZ(v[1])==0){
				v[0].pb(a[i]);
			}else{
				v[1].pb(a[i]);
			}
			while(SZ(v[1])>=p&&v[1][SZ(v[1])-p]==v[1].back()){
				fore(j,0,p-1)v[1].pop_back();
				v[1][SZ(v[1])-1]++;
			}
			while(SZ(v[0])&&SZ(v[1])&&v[0].back()==v[1].back()){
				v[0].pop_back(); v[1].pop_back();
			}
		}
		ll res=0;
		fore(i,0,SZ(v[0])){
			res=(res+be(p,v[0][i],MOD))%MOD;
		}
		fore(i,0,SZ(v[1])){
			res=(res-be(p,v[1][i],MOD)+MOD)%MOD;
		}
		cout<<res<<"\n";
	}
	
	return 0;
}