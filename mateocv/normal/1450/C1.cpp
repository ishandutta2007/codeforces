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

vector<pair<ll,ll>> v[3];

char c[303][303];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,3)v[i].clear();
		fore(i,0,n){
			fore(j,0,n){
				cin>>c[i][j];
			}
		}
		fore(i,0,n){
			fore(j,0,n){
				if(c[i][j]!='.')v[(i+j)%3].pb({i,j});
			}
		}
		ll mini=min({SZ(v[0]),SZ(v[1]),SZ(v[2])});
		fore(k,0,3){
			if(SZ(v[k])==mini){
				for(auto i:v[k]){
					c[i.fst][i.snd]='O';
				}
				break;
			}
		}
		fore(i,0,n){
			fore(j,0,n){
				cout<<c[i][j];
			}
			cout<<"\n";
		}
	}
	
	return 0;
}