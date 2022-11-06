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

void ask(ll b, ll x, ll y){
	cout<<b+1<<" "<<x+1<<" "<<y+1<<endl;
}

int main(){FIN;
	ll n; cin>>n;
	vector<pair<ll,ll>> v[2];
	fore(i,0,n){
		fore(j,0,n){
			v[(i+j)&1].pb({i,j});
		}
	}
	ll ya=0;
	ll vi=-1;
	while(SZ(v[0])||SZ(v[1])){
		if(ya==0){
			ll a; cin>>a; a--;
			if(a==0){
				auto b=v[1].back();
				v[1].pop_back();
				ask(1,b.fst,b.snd);
			}else{
				auto b=v[0].back();
				v[0].pop_back();
				ask(0,b.fst,b.snd);
			}
			if(SZ(v[0])==0){
				ya++; vi=1;
			}
			if(SZ(v[1])==0){
				ya++; vi=0;
			}
		}else{
			ll a; cin>>a; a--;
			auto b=v[vi].back();
			v[vi].pop_back();
			if(a==vi)ask(2,b.fst,b.snd);
			else ask(vi,b.fst,b.snd);
		}
	}
	
	
	return 0;
}