#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

vector<string> gen(string s){
	vector<string> res;
	fore(i,0,SZ(s)){
		string t;
		fore(j,i,SZ(s)){
			t+=s[j];
			res.pb(t);
		}
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string a,b; cin>>a>>b;
		set<string> sb;
		auto vb=gen(b);
		for(auto i:vb)sb.insert(i);
		auto va=gen(a);
		ll res=0;
		for(auto i:va){
			if(sb.count(i)){
				res=max(res,SZ(i));
			}
		}
		res=SZ(a)+SZ(b)-2*res;
		cout<<res<<"\n";
	}
	
	return 0;
}