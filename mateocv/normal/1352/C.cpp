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

ll cant(ll m, ll n){
	return m-m/n;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		ll l=0,r=2e9+10;
		while(l<=r){
			ll m=(l+r)/2;
			if(cant(m,n)>=k)r=m-1;
			else l=m+1;
		}
		cout<<l<<"\n";
	}
	
	return 0;
}