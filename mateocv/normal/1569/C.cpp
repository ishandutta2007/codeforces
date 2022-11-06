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

const ll MOD=998244353;

ll fact[MAXN];

ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

int main(){FIN;
	fact[0]=1;
	fore(i,1,MAXN)fact[i]=fact[i-1]*i%MOD;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		sort(ALL(a));
		if(a[n-2]+2<=a[n-1]){
			cout<<"0\n";
		}else if(a[n-1]==a[n-2]){
			cout<<fact[n]<<"\n";
		}else{
			ll c=0;
			fore(i,0,n){
				if(a[i]>=a[n-1]-1)c++;
			}
			ll res=fact[n];
			res=(res-res*fpow(c,MOD-2)%MOD+MOD)%MOD;
			cout<<res<<"\n";
		}
	}
	
	return 0;
}