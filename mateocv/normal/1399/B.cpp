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
		ll a[n],b[n];
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		ll mina=2e9,minb=2e9;
		fore(i,0,n)mina=min(mina,a[i]);
		fore(i,0,n)minb=min(minb,b[i]);
		ll res=0;
		fore(i,0,n){
			res+=a[i]+b[i]-mina-minb-min(a[i]-mina,b[i]-minb);
		}
		cout<<res<<"\n";
	}
	
	return 0;
}