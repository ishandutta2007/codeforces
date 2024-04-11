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
		string res;
		fore(i,0,k){
			ll cant=n/k;
			fore(j,0,26){
				if(c[j]&&cant){
					c[j]--;
					cant--;
				}else{
					res+=('a'+j);
					break;
				}
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}