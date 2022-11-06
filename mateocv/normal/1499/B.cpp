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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		ll a=-1,b=SZ(s)+1;
		fore(i,0,SZ(s)-1){
			if(s[i]==s[i+1]){
				if(s[i]=='0'){
					a=max(a,i);
				}else{
					b=min(b,i);
				}
			}
		}
		if(a<=b)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}