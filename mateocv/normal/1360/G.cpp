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
		ll n,m,a,b; cin>>n>>m>>a>>b;
		if(b*m!=a*n){
			cout<<"NO\n";
		}else{
			cout<<"YES\n";
			ll res[n][m];
			mset(res,0);
			ll pos=0;
			fore(i,0,n){
				fore(j,0,a){
					res[i][pos]=1;
					pos=(pos+1)%m;
				}
			}
			fore(i,0,n){
				fore(j,0,m){
					cout<<res[i][j];
				}
				cout<<"\n";
			}
		}
	}
	
	return 0;
}