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

ll dist(ll n){
	vector<ll> v;
	while(n>0){
		v.pb(n%10);
		n/=10;
	}
	sort(ALL(v));
	fore(i,0,SZ(v)){
		if(v[i]==v[i+1])return 0;
	}
	return 1;
}

int main(){FIN;
	ll l,r; cin>>l>>r;
	fore(i,l,r+1){
		if(dist(i)){
			cout<<i; return 0;
		}
	}
	cout<<-1;
	return 0;
}