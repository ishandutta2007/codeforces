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
		ll n,m; cin>>n>>m;
		ll a[n][m];
		fore(i,0,n){
			fore(j,0,m){
				cin>>a[i][j];
			}
		}
		ll tot[n+m][2];
		mset(tot,0);
		fore(i,0,n){
			fore(j,0,m){
				tot[i+j][a[i][j]]++;
			}
		}
		ll res=0;
		fore(i,0,n+m-1){
			if(i<n+m-2-i){
				res+=min(tot[i][0]+tot[n+m-2-i][0],tot[i][1]+tot[n+m-2-i][1]);
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}