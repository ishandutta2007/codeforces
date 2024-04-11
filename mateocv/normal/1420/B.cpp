#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

vector<ll> v[31];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		fore(i,0,n){
			fore(j,0,31){
				if((1ll<<(30-j))&a[i]){
					v[30-j].pb(a[i]);
					break;
				}
			}
		}
		ll res=0;
		fore(i,0,31)res+=SZ(v[i])*(SZ(v[i])-1)/2;
		cout<<res<<"\n";
		fore(i,0,31)v[i].clear();
	}
	
	return 0;
}