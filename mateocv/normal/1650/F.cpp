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

const int MAXN=100005;

vector<pair<pair<ll,ll>,ll>> v[MAXN];

ll dp[MAXN][102];

ll INF=1e18;

ll pos;

ll f(ll x, ll y){
	ll &res=dp[x][y];
	if(res>=0)return res;
	if(x==SZ(v[pos]))return res=(y?INF:0);
	res=f(x+1,y);
	res=min(res,f(x+1,max(0ll,y-v[pos][x].fst.snd))+v[pos][x].fst.fst);
	return res;
}

vector<ll> ans;

void build(ll x, ll y){
	auto res=f(x,y);
	if(x==SZ(v[pos]))return;
	if(res==f(x+1,y)){
		build(x+1,y);
	}else{
		ans.pb(v[pos][x].snd);
		build(x+1,max(0ll,y-v[pos][x].fst.snd));
	}
}

vector<ll> solve(ll x){
	pos=x;
	fore(i,0,SZ(v[x])+1){
		fore(j,0,101){
			dp[i][j]=-1;
		}
	}
	ans.clear();
	if(f(0,100)==INF)return {};
	build(0,100);
	return ans;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)v[i].clear();
		vector<ll> ti;
		fore(i,0,m){
			ll x,y,z; cin>>x>>y>>z; x--;
			v[x].pb({{y,z},i});
			ti.pb(y);
		}
		vector<ll> res;
		ll va=0,br=0;
		fore(i,0,n){
			auto s=solve(i);
			for(auto i:s){
				res.pb(i);
				va+=ti[i];
			}
			if(va>a[i]||SZ(s)==0){
				br++; break;
			}
		}
		if(br)cout<<"-1\n";
		else{
			cout<<SZ(res)<<"\n";
			for(auto i:res)cout<<i+1<<" ";
			cout<<"\n";
		}
	}
	
	return 0;
}