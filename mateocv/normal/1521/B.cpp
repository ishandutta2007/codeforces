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
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		pair<ll,ll> mini={(1ll<<30),-1};
		fore(i,0,n)mini=min(mini,{a[i],i});
		cout<<n-1<<"\n";
		fore(i,0,n){
			if(i!=mini.snd){
				if(i%2==mini.snd%2){
					cout<<i+1<<" "<<mini.snd+1<<" "<<mini.fst<<" "<<mini.fst<<"\n";
				}else{
					cout<<i+1<<" "<<mini.snd+1<<" "<<mini.fst+1<<" "<<mini.fst<<"\n";
				}
			}
		}
	}
	
	return 0;
}