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
		ll p; cin>>p;
		vector<ll> oc[26];
		ll val=0;
		fore(i,0,SZ(s)){
			val+=s[i]-'a'+1;
			oc[s[i]-'a'].pb(i);
		}
		ll pos=25;
		while(val>p){
			if(!SZ(oc[pos]))pos--;
			else{
				val-=pos+1;
				oc[pos].pop_back();
			}
		}
		vector<pair<ll,char>> vp;
		fore(i,0,26){
			for(auto j:oc[i])vp.pb({j,'a'+i});
		}
		sort(ALL(vp));
		string res;
		for(auto i:vp)res+=i.snd;
		cout<<res<<"\n";
	}
	
	return 0;
}