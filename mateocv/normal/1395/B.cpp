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
	ll n,m,x,y; cin>>n>>m>>x>>y; x--; y--;
	vector<pair<ll,ll>> res={{x,y}};
	while(SZ(res)<n*m){
		if(SZ(res)%m==0){
			x=(x+1)%n;
		}else{
			y=(y+1)%m;
		}
		res.pb({x,y});
	}
	for(auto i:res)cout<<i.fst+1<<" "<<i.snd+1<<"\n";
	return 0;
}