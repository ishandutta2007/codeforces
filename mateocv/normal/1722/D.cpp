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
		string s; cin>>s;
		ll va=0;
		vector<ll> v;
		fore(i,0,n){
			if(s[i]=='L'){
				va+=i;
				v.pb(n-1-i-i);
			}else{
				va+=n-1-i;
				v.pb(i-(n-1-i));
			}
		}
		sort(ALL(v));
		reverse(ALL(v));
		fore(i,0,n){
			if(v[i]>0)va+=v[i];
			cout<<va<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}