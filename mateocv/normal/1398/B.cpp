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
		vector<ll> v;
		ll va=0;
		fore(i,0,SZ(s)){
			va+=(s[i]=='1');
			if(i==SZ(s)-1||(s[i]=='1'&&s[i+1]=='0'))v.pb(va),va=0;
		}
		sort(ALL(v));
		reverse(ALL(v));
		ll res=0;
		fore(i,0,SZ(v)){
			if(!(i&1))res+=v[i];
		}
		cout<<res<<"\n";
	}
	
	return 0;
}