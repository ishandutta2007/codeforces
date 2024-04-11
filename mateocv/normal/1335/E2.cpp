#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef int ll;

ll a[200005];
ll sump[200005][200];

ll maxi(ll l, ll r){
	ll res=0;
	fore(j,0,200){
		res=max(res,sump[r][j]-sump[l][j]);
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)cin>>a[i],a[i]--;
		vector<ll> v[200];
		fore(i,0,n){
			fore(j,0,200){
				sump[i+1][j]=sump[i][j]+(a[i]==j);
			}
		}
		fore(i,0,n){
			v[a[i]].pb(i);
		}
		ll res=0;
		fore(j,0,200){
			fore(i,0,SZ(v[j])/2){
				res=max(res,2*(i+1)+maxi(v[j][i]+1,v[j][SZ(v[j])-1-i]));
			}
		}
		fore(j,0,200)res=max(res,SZ(v[j]));
		cout<<res<<"\n";
	}
	
	return 0;
}