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
		if(n&1){
			ll tot=0;
			fore(i,0,n){
				if(!(i&1))tot+=((s[i]-'0')&1);
			}
			if(tot){
				cout<<"1\n";
			}else{
				cout<<"2\n";
			}
		}else{
			ll tot=0;
			fore(i,0,n){
				if(i&1)tot+=(!((s[i]-'0')&1));
			}
			if(tot){
				cout<<"2\n";
			}else{
				cout<<"1\n";
			}
		}
	}
	return 0;
}