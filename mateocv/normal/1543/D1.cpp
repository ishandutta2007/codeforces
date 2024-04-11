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

ll ask(ll val){
	cout<<val<<endl;
	ll resp; cin>>resp;
	assert(resp!=-1);
	return resp;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		ll va=0;
		fore(i,0,n){
			ll a=ask(va^i);
			if(a==1)break;
			else va^=va^i;
		}
	}
	
	return 0;
}