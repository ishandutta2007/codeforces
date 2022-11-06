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
		ll a,b,q; cin>>a>>b>>q;
		ll r[a*b];
		mset(r,0);
		fore(i,0,a*b){
			r[i]=((i%a)%b)!=((i%b)%a);
		}
		ll sump[a*b+1];
		sump[0]=0;
		fore(i,0,a*b){
			sump[i+1]=sump[i]+r[i];
		}
		while(q--){
			ll l, r; cin>>l>>r;
			cout<<sump[r%(a*b)+1]+(r/(a*b))*sump[a*b]-(sump[(l-1)%(a*b)+1]+((l-1)/(a*b))*sump[a*b])<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}