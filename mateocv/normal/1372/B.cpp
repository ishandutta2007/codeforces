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

ll sm(ll n){
	for(ll i=2;i*i<=n;i++){
		if(n%i==0)return i;
	}
	return n;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll s=sm(n);
		if(s==n){
			cout<<s-1<<" "<<1<<"\n";
		}else{
			cout<<n/s<<" "<<n-n/s<<"\n";
		}
	}
	
	return 0;
}