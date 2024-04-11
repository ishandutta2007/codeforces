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
		vector<ll> a(n+1),b(n+1);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i+1];
		reverse(ALL(a));
		fore(i,1,n+1)a[i]=a[i-1]+a[i];
		fore(i,1,n+1)b[i]=b[i-1]+b[i];
		ll res=1e18;
		fore(i,0,n){
			res=min(res,max(a[n-1-i],b[i]));
		}
		cout<<res<<"\n";
	}
	
	return 0;
}