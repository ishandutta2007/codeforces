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
		ll n,m; cin>>n>>m;
		vector<vector<ll>> v(n);
		fore(i,0,n){
			v[i].resize(m);
			fore(j,0,m)cin>>v[i][j];
		}
		ll l=0,r=1000000009;
		while(l<=r){
			ll mid=(l+r)/2;
			vector<ll> cf(n),cc(m);
			fore(i,0,n){
				fore(j,0,m){
					if(v[i][j]>=mid){
						cf[i]++;
						cc[j]++;
					}
				}
			}
			ll br=0,br2=0;
			fore(i,0,n)br+=(cf[i]>=2);
			fore(i,0,m)br2+=(!cc[i]);
			if(br&&!br2)l=mid+1;
			else r=mid-1;
		}
		cout<<r<<"\n";
	}
	
	return 0;
}