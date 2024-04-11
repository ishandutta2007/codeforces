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

ll getf(ll n){
	ll res=1;
	while(n%2==0){
		res*=2;
		n/=2;
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		if(__builtin_popcountll(n)==1){
			cout<<"-1\n";
			continue;
		}
		auto g=getf(2ll*n);
		auto res=min(g,(2ll*n)/g);
		cout<<res<<"\n";
	}
	
	return 0;
}