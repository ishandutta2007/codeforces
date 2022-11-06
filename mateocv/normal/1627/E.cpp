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

struct str{
	pair<ll,ll> a,b;
	ll h,id;
};

ll n,m,k;

vector<ll> c;

vector<str> v;

vector<pair<ll,ll>> oc[100005];

ll INF=8e18;

bool vis[100005][2][2];

ll dp[100005][2][2];

ll f(ll x, ll y, ll z){
	auto &res=dp[x][y][z];
	if(vis[x][y][z])return res;
	vis[x][y][z]=1;
	if(y&&v[x].b.fst==n-1)return res=(m-1-v[x].b.snd)*c[n-1];
	res=INF;
	if(!y){
		res=min(res,f(x,1,0)-v[x].h);
		res=min(res,f(x,1,1)-v[x].h);
		ll ubx=v[x].a.fst,uby=v[x].a.snd;
		auto pos=lower_bound(ALL(oc[ubx]),pair<ll,ll>({uby,v[x].id}))-oc[ubx].begin();
		if(z&&pos+1<SZ(oc[ubx])){
			res=min(res,f(oc[ubx][pos+1].snd,0,z)+abs(uby-oc[ubx][pos+1].fst)*c[ubx]);
		}
		if(!z&&pos-1>=0){
			res=min(res,f(oc[ubx][pos-1].snd,0,z)+abs(uby-oc[ubx][pos-1].fst)*c[ubx]);
		}
	}else{
		ll ubx=v[x].b.fst,uby=v[x].b.snd;
		auto pos=lower_bound(ALL(oc[ubx]),pair<ll,ll>({uby,-1}))-oc[ubx].begin();
		if(z&&pos<SZ(oc[ubx])){
			res=min(res,f(oc[ubx][pos].snd,0,z)+abs(uby-oc[ubx][pos].fst)*c[ubx]);
		}
		if(!z&&pos-1>=0){
			res=min(res,f(oc[ubx][pos-1].snd,0,z)+abs(uby-oc[ubx][pos-1].fst)*c[ubx]);
		}
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m>>k;
		c.clear();
		c.resize(n);
		fore(i,0,n)cin>>c[i];
		v.clear();
		fore(i,0,k){
			ll a,b,c,d,e; 
			cin>>a>>b>>c>>d>>e;
			a--; b--; c--; d--;
			str s={{a,b},{c,d},e,i};
			v.pb(s);
		}
		fore(i,0,n)oc[i].clear();
		for(auto i:v){
			oc[i.a.fst].pb({i.a.snd,i.id});
		}
		fore(i,0,n)sort(ALL(oc[i]));
		fore(i,0,k){
			fore(j,0,2){
				fore(k,0,2){
					vis[i][j][k]=0;
				}
			}
		}
		/*
		fore(i,0,n){
			fore(j,0,2){
				fore(k,0,2){
					cout<<i<<" "<<j<<" "<<k<<" -> "<<f(i,j,k)<<"\n";
				}
			}
		}
		*/
		auto res=INF;
		for(auto i:v){
			if(i.a.fst==0)res=min(res,f(i.id,0,1)+c[0]*i.a.snd);
		}
		if(res>=1e18)cout<<"NO ESCAPE\n";
		else cout<<res<<"\n";
	}
	
	return 0;
}