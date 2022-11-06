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
		char c[n][n];
		vector<pair<ll,ll>> v;
		fore(i,0,n){
			fore(j,0,n){
				cin>>c[i][j];
				if(c[i][j]=='*')v.pb({i,j});
			}
		}
		if(v[0].fst!=v[1].fst&&v[0].snd!=v[1].snd){
			c[v[0].fst][v[1].snd]='*';
			c[v[1].fst][v[0].snd]='*';
		}else if(v[0].fst==v[1].fst){
			c[(v[0].fst+1)%n][v[1].snd]='*';
			c[(v[0].fst+1)%n][v[0].snd]='*';
		}else{
			c[v[0].fst][(v[0].snd+1)%n]='*';
			c[v[1].fst][(v[0].snd+1)%n]='*';
		}
		fore(i,0,n){
			fore(j,0,n){
				cout<<c[i][j];
			}
			cout<<"\n";
		}
	}
	
	
	return 0;
}