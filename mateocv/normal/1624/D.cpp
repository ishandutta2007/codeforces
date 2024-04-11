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
		string s; cin>>s;
		vector<ll> c(26);
		for(auto i:s)c[i-'a']++;
		ll cant[2]={0,0};
		fore(i,0,26){
			cant[0]+=c[i]/2;
			cant[1]+=c[i]%2;
		}
		ll l=1,r=n;
		while(l<=r){
			ll m=(l+r)/2;
			if(cant[0]>=k*(m/2)&&k*m<=n)l=m+1;
			else r=m-1;
		}
		cout<<r<<"\n";
	}
	
	return 0;
}