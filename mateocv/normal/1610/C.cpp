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

vector<pair<ll,ll>> a;

bool can(ll m){
	ll va=0;
	fore(i,0,SZ(a)){
		if(a[i].fst>=m-1-va&&a[i].snd>=va)va++;
	}
	return va>=m;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		a.clear();
		a.resize(n);
		fore(i,0,n)cin>>a[i].fst>>a[i].snd;
		ll l=1,r=n;
		while(l<=r){
			ll m=(l+r)/2;
			if(can(m))l=m+1;
			else r=m-1;
		}
		cout<<r<<"\n";
	}
	
	return 0;
}