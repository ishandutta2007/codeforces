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
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		map<ll,ll> ml,mr;
		fore(i,0,n){
			if(!ml.count(a[i]))ml[a[i]]=i;
			mr[a[i]]=i;
		}
		while(k--){
			ll x,y; cin>>x>>y;
			if(!ml.count(x)||!mr.count(y)||ml[x]>mr[y])cout<<"NO\n";
			else cout<<"YES\n";
		}
	}
	
	return 0;
}