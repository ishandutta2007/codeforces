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

vector<pair<ll,ll>> v[3][2];

char c[303][303];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,3){
			fore(k,0,2)v[i][k].clear();
		}
		fore(i,0,n){
			fore(j,0,n){
				cin>>c[i][j];
			}
		}
		ll tot=0;
		fore(i,0,n){
			fore(j,0,n){
				if(c[i][j]!='.'){
					v[(i+j)%3][c[i][j]=='O'].pb({i,j});
					tot++;
				}
			}
		}
		ll mini=n*n;
		pair<ll,ll> conf={-1,-1};
		char f='.';
		fore(i,0,3){
			fore(j,i+1,3){
				fore(k,0,2){
					if(SZ(v[i][k])+SZ(v[j][k^1])<mini){
						mini=SZ(v[i][k])+SZ(v[j][k^1]);
						conf={i,j};
						if(k==0)f='O';
						else f='X';
					}
				}
			}
		}
		assert(mini<=tot/3);
		fore(k,0,2){
			for(auto i:v[conf.fst][k]){
				c[i.fst][i.snd]=f;
			}
			for(auto i:v[conf.snd][k]){
				c[i.fst][i.snd]=f^'O'^'X';
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