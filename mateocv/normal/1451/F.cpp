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

ll a[110][110];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n){
			fore(j,0,m)cin>>a[i][j];
		}
		ll x[n+m];
		mset(x,0);
		fore(i,0,n){
			fore(j,0,m)x[i+j]^=a[i][j];
		}
		ll br=0;
		fore(i,0,n+m){
			if(x[i]){
				br++; break;
			}
		}
		if(br)cout<<"Ashish\n";
		else cout<<"Jeel\n";
	}
	
	return 0;
}