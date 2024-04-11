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
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n){
		cin>>a[i];
	}
	ll sob=0;
	vector<ll> res;
	fore(i,0,n){
		sob+=a[i]-a[0]-i;
		res.pb(a[0]+i);
	}
	fore(i,0,n){
		res[i]+=sob/n;
	}
	fore(i,0,(sob%n)){
		res[i]++;
	}
	fore(i,0,n)cout<<res[i]<<" ";
	
	return 0;
}