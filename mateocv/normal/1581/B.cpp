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
		ll n,m,k; cin>>n>>m>>k;
		bool res=0;
		if(k==2){
			res=(n==1);
		}else if(k==3){
			res=(m>=n*(n-1)/2);
		}else if(k>3){
			res=(m>=n-1);
		}
		res=(res&&m<=n*(n-1)/2);
		if(res)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}