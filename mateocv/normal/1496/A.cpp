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
		ll br=0;
		fore(i,0,k){
			if(s[i]!=s[SZ(s)-1-i]){
				br++; break;
			}
		}
		if(!br&&SZ(s)>2*k)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}