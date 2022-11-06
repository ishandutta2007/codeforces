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
		ll res=n-1;
		fore(l,0,n){
			fore(r,l+1,n){
				ll cant=0;
				fore(i,0,n){
					if((r-l)*(a[i]-a[l])!=(a[r]-a[l])*(i-l))cant++;
				}
				res=min(res,cant);
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}