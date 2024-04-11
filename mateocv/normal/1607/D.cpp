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
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		string s; cin>>s;
		vector<ll> v[2];
		fore(i,0,n){
			if(s[i]=='B')v[0].pb(a[i]);
			else v[1].pb(a[i]);
		}
		ll br=0;
		sort(ALL(v[0]));
		fore(i,0,SZ(v[0])){
			if(i>v[0][i])br++;
		}
		sort(ALL(v[1]));
		fore(i,0,SZ(v[1])){
			if(i+SZ(v[0])<v[1][i])br++;
		}
		if(br)cout<<"NO\n";
		else cout<<"YES\n";
	}
	
	return 0;
}