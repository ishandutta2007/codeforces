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
		ll sum=0,mini=200,cant=0;
		fore(i,0,n){
			fore(j,0,m){
				cin>>a[i][j];
				sum+=abs(a[i][j]);
				mini=min(mini,abs(a[i][j]));
				cant+=(a[i][j]<0);
			}
		}
		if(cant&1){
			cout<<sum-2*mini<<"\n";
		}else{
			cout<<sum<<"\n";
		}
	}
	
	return 0;
}