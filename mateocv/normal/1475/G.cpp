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

vector<ll> d[MAXN];

ll a[MAXN],maxi[MAXN];

int main(){FIN;
	fore(i,1,MAXN){
		for(ll j=i;j<MAXN;j+=i){
			d[j].pb(i);
		}
	}
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)cin>>a[i];
		sort(a,a+n);
		fore(i,0,MAXN)maxi[i]=0;
		fore(i,0,n){
			ll va=0;
			for(auto j:d[a[i]]){
				va=max(va,maxi[j]);
			}
			maxi[a[i]]=va+1;
		}
		ll res=0;
		fore(i,0,MAXN)res=max(res,maxi[i]);
		cout<<n-res<<"\n";
	}
	
	return 0;
}