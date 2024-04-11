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
		ll cant=(n*k)/2;
		if(cant%k!=0){
			cout<<"NO\n";
			continue;
		}
		else cout<<"YES\n";
		vector<ll> v[2];
		fore(i,1,n*k+1)v[i&1].pb(i);
		fore(b,0,2){
			fore(i,0,SZ(v[b])){
				cout<<v[b][i]<<" ";
				if(i%k==k-1)cout<<"\n";
			}
		}
	}
	
	return 0;
}