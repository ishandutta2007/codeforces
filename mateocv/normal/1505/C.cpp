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
	string s; cin>>s;
	vector<ll> v;
	for(auto i:s)v.pb(i-'A');
	ll br=0;
	fore(i,2,SZ(v)){
		if((v[i-2]+v[i-1])%26!=v[i]){
			br++; break;
		}
	}
	if(!br){
		cout<<"YES\n";
	}else{
		cout<<"NO\n";
	}
	
	return 0;
}