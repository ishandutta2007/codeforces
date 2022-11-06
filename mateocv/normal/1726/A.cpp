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
		ll res=a.back()-a[0];
		fore(i,0,n-1)res=max(res,a[i]-a[i+1]);
		ll mini=1e9,maxi=0;
		fore(i,0,n-1)mini=min(mini,a[i]);
		fore(i,1,n)maxi=max(maxi,a[i]);
		res=max(res,maxi-a[0]);
		res=max(res,a.back()-mini);
		cout<<res<<"\n";
	}
	
	return 0;
}