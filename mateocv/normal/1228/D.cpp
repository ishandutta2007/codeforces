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

set<ll> g[100005];
ll vis[100005];

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll u,v; 
	fore(i,0,m){
		cin>>u>>v; u--; v--;
		g[u].insert(v);
		g[v].insert(u);
	}
	set<ll> s[3];
	ll va=0;
	fore(i,0,n){
		if(vis[i]==0){
			s[va].insert(i);
			vis[i]=1;
			fore(j,0,n){
				if(!g[j].count(i)&&i!=j){
					if(vis[j]==1){
						cout<<-1; return 0;
					}
					s[va].insert(j); vis[j]=1;
				}
			}
			va++;	
		}
		if(va==3)break;
	}
	if(va!=3){
		cout<<-1; return 0;
	}
	fore(i,0,n){
		if(!vis[i]){
			cout<<-1;
			return 0;
		}
	}
	if(SZ(s[0])*SZ(s[1])+SZ(s[1])*SZ(s[2])+SZ(s[2])*SZ(s[0])!=m){
		cout<<-1; return 0;
	}
	fore(k,0,3){
		for(auto i:s[k]){
			for(auto j:s[(k+1)%3]){
				if(!g[i].count(j)){
					cout<<-1; return 0;
				}
			}
			for(auto j:s[(k+2)%3]){
				if(!g[i].count(j)){
					cout<<-1; return 0;
				}
			}
		}
	}
	ll res[n];
	fore(k,0,3){
		for(auto i:s[k]){
			res[i]=k+1;
		}
	}
	fore(i,0,n)cout<<res[i]<<" ";
	return 0;
}