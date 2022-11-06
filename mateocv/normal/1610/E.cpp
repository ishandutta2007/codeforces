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
		ll res=0;
		fore(i,0,n){
			if(i&&a[i-1]==a[i])continue;
			ll va=1,pos=i;
			while(1){
				auto npos=lower_bound(a.begin()+pos+1,a.end(),2ll*a[pos]-a[i])-a.begin();
				if(npos==n)break;
				va++;
				pos=npos;
			}
			res=max(res,va);
		}
		cout<<n-res<<"\n";
	}
	
	return 0;
}