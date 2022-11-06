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

bool esp(ll n){
	if(n==1)return 0;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		vector<ll> p;
		fore(i,2,100){
			if(SZ(p)==11)break;
			if(esp(i))p.pb(i);
		}
		set<ll> us;
		fore(i,0,n){
			fore(j,0,11){
				if(a[i]%p[j]==0){
					us.insert(p[j]);
					break;
				}
			}
		}
		map<ll,ll> comp;
		ll va=1;
		for(auto i:us){
			comp[i]=va++;
		}
		cout<<SZ(comp)<<"\n";
		fore(i,0,n){
			fore(j,0,11){
				if(a[i]%p[j]==0){
					cout<<comp[p[j]]<<" ";
					break;
				}
			}
		}
		cout<<"\n";
	}
	
	return 0;
}