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
		string res;
		fore(i,0,SZ(s)){
			res+=s[i];
			if(i+1<SZ(s)&&s[i]<s[i+1])break;
		}
		auto rc=res;
		reverse(ALL(rc));
		res+=rc;
		if(res[0]==res[1])cout<<res[0]<<res[1]<<"\n";
		else cout<<res<<"\n";
	}
	
	return 0;
}