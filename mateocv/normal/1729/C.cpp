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
		vector<ll> oc[26];
		fore(i,1,SZ(s)-1){
			oc[s[i]-'a'].pb(i);
		}
		cout<<abs(s[0]-s.back())<<" ";
		vector<ll> res;
		res.pb(0);
		fore(i,min(s[0]-'a',s.back()-'a'),max(s[0]-'a',s.back()-'a')+1){
			for(auto j:oc[i])res.pb(j);
		}
		res.pb(SZ(s)-1);
		if(s.back()<s[0])reverse(ALL(res)),swap(res[0],res.back());
		cout<<SZ(res)<<"\n";
		for(auto i:res)cout<<i+1<<" ";
		cout<<"\n";
	}
	
	return 0;
}