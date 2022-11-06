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

int main(){FIN;
	vector<ll> v;
	ll va=1;
	while(SZ(v)<2000){
		if(va%10!=3&&va%3!=0)v.pb(va);
		va++;
	}
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		n--;
		cout<<v[n]<<"\n";
	}
	
	return 0;
}