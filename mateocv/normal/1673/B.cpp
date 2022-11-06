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
		set<char> st;
		for(auto i:s)st.insert(i);
		ll c=SZ(st);
		ll br=0;
		fore(i,c,SZ(s)){
			if(s[i]!=s[i-c])br++;
		}
		if(br)cout<<"NO\n";
		else cout<<"YES\n";
	}
	
	return 0;
}