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

ll res[110][110];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		if(n==2){
			cout<<"-1\n";
		}else{
			vector<pair<ll,ll>> v[2];
			fore(i,0,n){
				fore(j,0,n){
					v[(i+j)&1].pb({i,j});
				}
			}
			fore(k,0,2)sort(ALL(v[k]));
			ll va=1;
			for(auto i:v[0]){
				res[i.fst][i.snd]=va++;
			}
			for(auto i:v[1]){
				res[i.fst][i.snd]=va++;
			}
			fore(i,0,n){
				fore(j,0,n){
					cout<<res[i][j]<<" ";
				}
				cout<<"\n";
			}
		}
	}
	
	return 0;
}