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

void rot(pair<ll,ll> &p, ll n){
	pair<ll,ll> res={n-1-p.snd,p.fst};
	p=res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll ex[2][2];
		mset(ex,0);
		vector<pair<ll,ll>> v;
		fore(k,0,3){
			ll x,y; cin>>x>>y; x--; y--;
			ex[x&1][y&1]++;
			v.pb({x,y});
		}
		sort(ALL(v));
		ll x,y; cin>>x>>y; x--; y--;
		pair<ll,ll> fp={x,y};
		ll br=0;
		fore(k,0,4){
			if(v==vector<pair<ll,ll>>({{0,0},{0,1},{1,0}})){
				cout<<((fp.fst==0||fp.snd==0)?"YES\n":"NO\n");
				br++;
				break;
			}
			for(auto &i:v){
				rot(i,n);
			}
			rot(fp,n);
			sort(ALL(v));
		}
		if(br)continue;
		cout<<(ex[fp.fst&1][fp.snd&1]?"YES\n":"NO\n");
	}
	return 0;
}