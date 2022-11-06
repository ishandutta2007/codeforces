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
	vector<string> res[55];
	res[0]={"()"};
	fore(i,1,55){
		for(auto j:res[i-1]){
			res[i].pb("()"+j);
		}
		string s;
		fore(_,0,i+1)s+="(";
		fore(_,0,i+1)s+=")";
		res[i].pb(s);
	}
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		for(auto i:res[n-1]){
			cout<<i<<"\n";
		}
	}
	
	return 0;
}