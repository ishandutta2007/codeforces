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
		char c[n][m];
		fore(i,0,n){
			fore(j,0,m){
				cin>>c[i][j];
			}
		}
		ll res=0;
		fore(i,0,n-1)res+=(c[i][m-1]!='D');
		fore(j,0,m-1)res+=(c[n-1][j]!='R');
		cout<<res<<"\n";
	}
	
	return 0;
}