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

pair<ll,ll> ub[300000];

ll res[505][505];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n*m)ub[i]={-1,-1};
		fore(i,0,n){
			fore(j,0,m){
				ll lle; cin>>lle; lle--;
				ub[lle].snd=j;
			}
		}
		fore(j,0,m){
			fore(i,0,n){
				ll lle; cin>>lle; lle--;
				ub[lle].fst=i;
			}
		}
		fore(i,0,n*m){
			res[ub[i].fst][ub[i].snd]=i;
		}
		fore(i,0,n){
			fore(j,0,m){
				cout<<res[i][j]+1<<" ";
			}
			cout<<"\n";
		}
	}
	
	return 0;
}