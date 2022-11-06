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
		ll n,m,x; cin>>n>>x>>m;
		pair<ll,ll> a[m];
		fore(i,0,m)cin>>a[i].fst>>a[i].snd,a[i].snd++;
		ll l=x,r=x+1;
		fore(i,0,m){
			if(max(l,a[i].fst)<min(r,a[i].snd)){
				l=min(l,a[i].fst);
				r=max(r,a[i].snd);
			}
		}
		cout<<r-l<<"\n";
	}
	
	return 0;
}