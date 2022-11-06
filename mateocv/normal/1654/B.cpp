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
		vector<ll> c(26);
		for(auto i:s)c[i-'a']++;
		reverse(ALL(s));
		while(SZ(s)){
			auto b=s.back();
			if(c[b-'a']>1){
				s.pop_back();
				c[b-'a']--;
			}else break;
		}
		reverse(ALL(s));
		cout<<s<<"\n";
	}
	
	return 0;
}