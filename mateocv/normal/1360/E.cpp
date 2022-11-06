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
		ll n; cin>>n;
		char a[n][n];
		fore(i,0,n){
			fore(j,0,n){
				cin>>a[i][j];
			}
		}
		ll br=0;
		vector<pair<ll,ll>> d={{1,0},{0,1}};
		fore(i,0,n){
			fore(j,0,n){
				if(a[i][j]=='1'){
					ll tot=0;
					for(auto ii:d){
						if(i<n-1&&j<n-1&&a[i+ii.fst][j+ii.snd]=='0'){
							tot++;
						}
					}
					if(tot==2){
						cout<<"NO\n";
						br++; break;
					}
				}
				if(br)break;
			}
			if(br)break;
		}
		if(br)continue;
		cout<<"YES\n";
	}
	
	return 0;
}