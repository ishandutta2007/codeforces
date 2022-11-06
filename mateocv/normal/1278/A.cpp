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
		string s; cin>>s;
		string t; cin>>t;
		sort(ALL(s));
		if(SZ(t)<SZ(s)){
			cout<<"NO\n"; continue;
		}
		ll br=0;
		fore(j,0,SZ(t)-SZ(s)+1){
			string p;
			fore(i,0,SZ(s))p.pb(t[j+i]);
			sort(ALL(p));
			if(s==p){
				cout<<"YES\n"; br++; break;
			}
		}
		if(br)continue;
		cout<<"NO\n";
	}
	
	return 0;
}