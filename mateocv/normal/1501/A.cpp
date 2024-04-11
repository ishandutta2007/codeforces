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
		vector<ll> a(n),b(n),t(n);
		fore(i,0,n)cin>>a[i]>>b[i];
		fore(i,0,n)cin>>t[i];
		ll res=0;
		fore(i,0,n){
			res+=a[i]+t[i];
			if(i>0)res-=b[i-1];
			if(i<n-1){
				res+=(b[i]-a[i]+1)/2;
				res=max(res,b[i]);
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}