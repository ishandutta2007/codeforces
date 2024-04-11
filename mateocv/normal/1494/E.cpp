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
typedef int ll;

map<pair<ll,ll>,char> ed;

ll sym=0,syme=0;

int main(){FIN;
	ll n,m; cin>>n>>m;
	while(m--){
		char ty; cin>>ty;
		if(ty=='+'){
			ll u[2]; cin>>u[0]>>u[1]; u[0]--; u[1]--;
			char c; cin>>c; c-='a';
			ed[{u[0],u[1]}]=c;
			if(ed.count({u[1],u[0]})){
				sym++;
				if(ed[{u[1],u[0]}]==c)syme++;
			}
		}else if(ty=='-'){
			ll u[2]; cin>>u[0]>>u[1]; u[0]--; u[1]--;
			char c=ed[{u[0],u[1]}];
			ed.erase({u[0],u[1]});
			if(ed.count({u[1],u[0]})){
				sym--;
				if(ed[{u[1],u[0]}]==c)syme--;
			}
		}else if(ty=='?'){
			ll k; cin>>k;
			bool res=false;
			res=(syme>=1);
			if(k&1)res=(res||sym);
			if(res)cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	
	return 0;
}