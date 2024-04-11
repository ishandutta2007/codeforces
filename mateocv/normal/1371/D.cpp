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
		ll n,k; cin>>n>>k;
		ll res[n][n];
		fore(i,0,n){
			fore(j,0,n){
				if(n*i+j<k){
					res[(i+j)%n][j]=1;
				}else{
					res[(i+j)%n][j]=0;
				}
			}
		}
		ll rmin=n,rmax=0,cmin=n,cmax=0;
		fore(i,0,n){
			ll va=0;
			fore(j,0,n){
				va+=res[i][j];
			}
			rmin=min(rmin,va);
			rmax=max(rmax,va);
		}
		fore(j,0,n){
			ll va=0;
			fore(i,0,n){
				va+=res[i][j];
			}
			cmin=min(cmin,va);
			cmax=max(cmax,va);
		}
		cout<<(rmax-rmin)*(rmax-rmin)+(cmax-cmin)*(cmax-cmin)<<"\n";
		fore(i,0,n){
			fore(j,0,n){
				cout<<res[i][j];
			}
			cout<<"\n";
		}
	}
	
	return 0;
}