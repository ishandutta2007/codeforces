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
		vector<ll> b;
		fore(i,0,n-1)b.pb(a[i]==a[i+1]);
		ll l=n+1,r=-1;
		fore(i,0,n-1){
			if(b[i]){
				l=min(l,i);
				r=max(r,i);
			}
		}
		ll d=r-l;
		ll res=0;
		if(d==1)res=1;
		else if(d>1)res=d-1;
		cout<<res<<"\n";
	}
	
	return 0;
}