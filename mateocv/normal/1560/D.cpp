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

vector<string> pw;

ll dist(string a, string b){
	ll va=0;
	fore(i,0,SZ(a)){
		if(a[i]==b[va]){
			va++;
			if(va==SZ(b))break;
		}
	}
	ll res=SZ(a)-va+SZ(b)-va;
	return res;
}

int main(){FIN;
	fore(i,0,63){
		pw.pb(to_string(1ll<<i));
	}
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		ll res=1e18;
		for(auto i:pw)res=min(res,dist(s,i));
		cout<<res<<"\n";
	}
	
	return 0;
}