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

vector<vector<ll>> v;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		ll m; cin>>m;
		ll b[m];
		fore(i,0,m)cin>>b[i];
		vector<ll> may;
		ll vis[m];
		mset(vis,0);
		while(SZ(may)<m){
			vector<ll> vv;
			fore(i,0,m){
				if(vis[i])continue;
				ll d=0;
				for(auto j:may)d+=abs(i-j);
				if(d==b[i]){
					vv.pb(i);
					vis[i]++;
				}
			}
			v.pb(vv);
			for(auto i:vv)may.pb(i);
		}
		/*
		for(auto i:v){
			for(auto j:i)cout<<j<<" ";
			cout<<"\n";
		}
		*/
		ll cant[26];
		mset(cant,0);
		for(auto i:s)cant[i-'a']++;
		//fore(i,0,26)cout<<cant[i]<<" "; cout<<"\n";
		ll pos=0;
		string res(m,'0');
		fore(i,0,26){
			if(cant[25-i]>=SZ(v[pos])){
				for(auto j:v[pos])res[j]='a'+25-i;
				pos++;
			}
			if(pos==SZ(v))break;
		}
		cout<<res<<"\n";
		v.clear();
	}
	
	return 0;
}