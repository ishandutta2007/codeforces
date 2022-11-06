#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

bool solve(vector<ll> &a, vector<ll> &b){
	ll sa=0,la=0,ra=0;
	fore(i,0,SZ(a)){
		sa+=a[i];
		if(a[i])la=min(la,i);
		if(a[i])ra=max(ra,i);
	}
	ll sb=0,lb=0,rb=0;
	fore(i,0,SZ(b)){
		sb+=b[i];
		if(b[i])lb=min(lb,i);
		if(b[i])rb=max(rb,i);
	}
	if(sa==0)return 1;
	if(sb==0)return 0;
	if(la<rb)return 1;
	if(la>rb)return 0;
	return (a[la]<b[rb]&&sa==a[la])||(a[la]==b[rb]&&sb>b[rb]&&sa==a[la]);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll q; cin>>q;
		vector<ll> c[2];
		fore(k,0,2)c[k].resize(26);
		while(q--){
			ll ty; cin>>ty; ty--;
			ll k; cin>>k;
			string x; cin>>x;
			for(auto i:x){
				c[ty][i-'a']+=k;
			}
			auto so=solve(c[0],c[1]);
			cout<<(so?"YES\n":"NO\n");
		}
	}
	
	return 0;
}