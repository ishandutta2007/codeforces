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

char c[202][202];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			fore(j,0,n){
				cin>>c[i][j];
			}
		}
		vector<pair<ll,ll>> v={{0,1},{1,0},{n-2,n-1},{n-1,n-2}};
		vector<pair<ll,ll>> res[2];
		fore(i,0,SZ(v)){
			res[c[v[i].fst][v[i].snd]-'0'==(i<2)].pb(v[i]);
		}
		if(SZ(res[0])<SZ(res[1])){
			cout<<SZ(res[0])<<"\n";
			for(auto i:res[0])cout<<i.fst+1<<" "<<i.snd+1<<"\n";
		}else{
			cout<<SZ(res[1])<<"\n";
			for(auto i:res[1])cout<<i.fst+1<<" "<<i.snd+1<<"\n";
		}
	}
	
	return 0;
}