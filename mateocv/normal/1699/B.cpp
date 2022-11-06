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
		ll res[n][m];
		mset(res,0);
		fore(i,0,n/2){
			fore(j,0,m/2){
				if((i+j)&1){
					res[2*i][2*j]=1;
					res[2*i+1][2*j+1]=1;
				}else{
					res[2*i][2*j+1]=1;
					res[2*i+1][2*j]=1;
				}
			}
		}
		fore(i,0,n){
			fore(j,0,m){
				cout<<res[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	
	return 0;
}