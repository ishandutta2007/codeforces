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
		ll m,k; cin>>m>>k;
		vector<ll> a(k);
		fore(i,0,k)cin>>a[i];
		pair<ll,ll> maxi={0,-1};
		fore(i,0,k){
			maxi=max(maxi,{a[i],i});
		}
		fore(n,1,m+20){
			ll pi=(n/2),te=(n+1)/2;
			if(maxi.fst<=te*te+pi*te&&m<=te*te+2ll*pi*te){
				vector<pair<ll,ll>> c[3];
				fore(i,0,n){
					fore(j,0,n){
						if(i%2==0&&j%2==1){
							c[0].pb({i,j});
						}else if(i%2==0&&j%2==0){
							c[1].pb({i,j});
						}else if(i%2==1&&j%2==0){
							c[2].pb({i,j});
						}
					}
				}
				vector<ll> v;
				fore(i,0,maxi.fst)v.pb(maxi.snd+1);
				fore(i,0,k){
					if(i!=maxi.snd){
						fore(j,0,a[i])v.pb(i+1);
					}
				}
				ll res[n][n];
				mset(res,0);
				reverse(ALL(v));
				fore(kk,0,3){
					while(SZ(c[kk])&&SZ(v)){
						auto pos=c[kk].back();
						c[kk].pop_back();
						auto val=v.back();
						v.pop_back();
						res[pos.fst][pos.snd]=val;
					}
				}
				cout<<n<<"\n";
				fore(i,0,n){
					fore(j,0,n){
						cout<<res[i][j]<<" ";
					}
					cout<<"\n";
				}
				break;
			}
		}
	}
	
	return 0;
}