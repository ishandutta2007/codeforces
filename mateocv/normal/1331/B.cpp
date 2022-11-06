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

pair<ll,ll> fact(ll n){
	for(ll i=2;i*i<=n;i++){
		if(n%i==0)return {i,n/i};
	}
	assert(0);
}

int main(){FIN;
	ll n; cin>>n;
	cout<<fact(n).fst<<fact(n).snd<<"\n";
	return 0;
}