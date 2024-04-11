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
			fore(j,0,m)cin>>a[i][j];
		}
		fore(i,0,n){
			fore(j,0,m){
				if((a[i][j]&1)==((i+j)&1)){
					a[i][j]++;
				}
			}
		}
		fore(i,0,n){
			fore(j,0,m){
				cout<<a[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	
	return 0;
}