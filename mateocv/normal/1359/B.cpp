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
		ll n,m,x,y; cin>>n>>m>>x>>y;
		ll res=0;
		char c[n][m];
		fore(i,0,n){
			fore(j,0,m){
				cin>>c[i][j];
			}
		}
		fore(i,0,n){
			vector<ll> v;
			fore(j,0,m){
				if(c[i][j]=='.'){
					if(SZ(v)==0||c[i][j-1]=='*'){
						v.pb(1);
					}else{
						v[SZ(v)-1]++;
					}	
				}
			}
			for(auto i:v){
				res+=min(i*x,(i/2)*y+(i%2)*x);
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}