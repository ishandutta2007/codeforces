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

const ll MOD=998244353;

const int MAXN=1010;

vector<ll> g[MAXN];

bool vis[MAXN];

vector<ll> ord;

void dfs(ll x){
	vis[x]=1;
	for(auto i:g[x]){
		if(!vis[i])dfs(i);
	}
	ord.pb(x);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)g[i].clear();
		fore(i,0,m){
			ll x,y; cin>>x>>y; x--; y--;
			g[x].pb(y);
		}
		ll c=0;
		fore(i,0,n)c+=(a[i]==0);
		if(c==n){
			cout<<"0\n";
			continue;
		}
		fore(i,0,n)vis[i]=0;
		ord.clear();
		fore(i,0,n)if(!vis[i])dfs(i);
		reverse(ALL(ord));
		ll br=0;
		fore(_,0,n){
			vector<ll> b(n);
			for(auto i:ord){
				if(a[i]){
					a[i]--;
					for(auto j:g[i])b[j]++;
				}
			}
			fore(i,0,n)a[i]+=b[i];
			ll c=0;
			fore(i,0,n)c+=(a[i]==0);
			if(c==n){
				cout<<_+1<<"\n";
				br++; break;
			}
		}
		if(br)continue;
		fore(i,0,n)a[i]%=MOD;
		for(auto i:ord){
			for(auto j:g[i])a[j]=(a[j]+a[i])%MOD;
		}
		cout<<(a[ord.back()]+n)%MOD<<"\n";
	}
	
	return 0;
}