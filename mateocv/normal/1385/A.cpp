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
		ll a[3];
		fore(i,0,3)cin>>a[i];
		ll maxi=max({a[0],a[1],a[2]});
		ll tot=0;
		fore(i,0,3)tot+=(maxi==a[i]);
		if(tot<2){
			cout<<"NO\n";
		}else{
			cout<<"YES\n";
			fore(i,0,3){
				if(a[i]==a[(i+1)%3]){
					cout<<a[i]<<" "<<a[(i+2)%3]<<" "<<a[(i+2)%3]<<"\n";
					break;
				}
			}
		}
	}
	
	return 0;
}