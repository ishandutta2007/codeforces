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

const int MAXN=1000006;

ll n;

ll a[MAXN];

vector<ll> g[MAXN];

vector<pair<pair<ll,ll>,ll>> v;

vector<pair<ll,ll>> gt[MAXN];

ll dp[MAXN];

ll f(ll x){
	ll &res=dp[x];
	if(res>=0)return res;
	if(x==0)return res=0;
	res=f(x-1);
	for(auto i:gt[x]){
		res=max(res,i.snd+f(i.fst-1));
	}
	//cout<<x<<" "<<res<<"\n";
	return res;
}

int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)g[a[i]].pb(i);
	fore(i,0,n+1){
		if(SZ(g[i])){
			v.pb({{g[i].back()+1,g[i][0]+1},SZ(g[i])});
		}
	}
	//for(auto i:v)cout<<i.fst.fst<<" "<<i.fst.snd<<" "<<i.snd<<"\n";
	sort(ALL(v));
	for(auto i:v){
		gt[i.fst.fst].pb({i.fst.snd,i.snd});
	}
	mset(dp,-1);
	ll res=n-f(n);
	fore(i,0,n+1){
		if(SZ(g[i])){
			fore(j,0,SZ(g[i])){
				ll va=n-f(g[i][j])-(SZ(g[i])-j);
				res=min(res,va);
			}
		}
	}
	cout<<res<<"\n";
	
	return 0;
}