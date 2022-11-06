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

const int MAXN=1010;

ll sump[MAXN][MAXN];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		mset(sump,0);
		fore(i,0,n){
			ll x,y; cin>>x>>y;
			sump[x][y]+=x*y;
		}
		fore(i,0,MAXN){
			fore(j,1,MAXN){
				sump[i][j]+=sump[i][j-1];
			}
		}
		fore(j,0,MAXN){
			fore(i,1,MAXN){
				sump[i][j]+=sump[i-1][j];
			}
		}
		while(q--){
			ll xl,yl,xr,yr; cin>>xl>>yl>>xr>>yr;
			cout<<sump[xr-1][yr-1]-sump[xr-1][yl]-sump[xl][yr-1]+sump[xl][yl]<<"\n";
		}
	}
	
	return 0;
}