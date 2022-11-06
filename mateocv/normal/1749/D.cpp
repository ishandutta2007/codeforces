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

bool esp(ll n){
	if(n==1)return 0;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0)return 0;
	}
	return 1;
}

const ll MOD=998244353;

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll res=0,va=1,lc=1;
	ll tot=0,pot=1;
	fore(i,0,n){
		pot=pot*(m%MOD)%MOD;
		tot=(tot+pot)%MOD;
	}
	fore(i,1,n+1){
		if(esp(i))lc*=i;
		if(lc>m)break;
		va=va*((m/lc)%MOD)%MOD;
		res=(res+va)%MOD;
	}
	cout<<(tot+MOD-res)%MOD<<"\n";
	
	return 0;
}