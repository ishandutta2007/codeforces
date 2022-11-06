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
		string t="2020";
		ll br=0;
		fore(i,0,5){
			ll tot=0;
			fore(j,0,4){
				if(j>=i)tot+=(s[n-4+j]==t[j]);
				else tot+=(s[j]==t[j]);
			}
			if(tot==4){
				br++; break;
			}
		}
		if(br)cout<<"Yes\n";
		else cout<<"No\n";
	}
	
	return 0;
}