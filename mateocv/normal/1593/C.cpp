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
		vector<ll> a(k);
		fore(i,0,k)cin>>a[i];
		sort(ALL(a));
		reverse(ALL(a));
		ll res=0,va=0;
		fore(i,0,k){
			if(va+(n-a[i])<n){
				va+=n-a[i];
				res++;
			}else break;
		}
		cout<<res<<"\n";
	}
	
	return 0;
}