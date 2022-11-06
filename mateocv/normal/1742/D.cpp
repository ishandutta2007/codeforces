#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
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
		vector<ll> oc(1010,0);
		fore(i,0,n){
			oc[a[i]]=max(oc[a[i]],i+1);
		}
		ll res=-1;
		fore(i,1,SZ(oc)){
			fore(j,1,SZ(oc)){
				if(__gcd(i,j)==1&&oc[i]&&oc[j]){
					res=max(res,oc[i]+oc[j]);
				}
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}