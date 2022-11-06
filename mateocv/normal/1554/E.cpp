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

const int MAXN=100005;

short mu[MAXN] = {0,1};
void mobius(){
	fore(i,1,MAXN)if(mu[i])for(int j=i+i;j<MAXN;j+=i)mu[j]-=mu[i];
}

vector<ll> g[MAXN];

ll n;

ll can(ll m){
	vector<ll> vis(n),val(n),vp(n),u;
	fore(i,0,n){
		if(SZ(g[i])==1)u.pb(i),vis[i]=1;
	}
	while(SZ(u)>1){
		auto b=u.back();
		u.pop_back();
		if(val[b]%m==0){
			for(auto i:g[b]){
				if(!vis[i])val[i]++;
			}
		}else if((val[b]+1)%m==0){
			val[b]++;
		}else return 0;
		for(auto i:g[b]){
			vp[i]++;
			if(vp[i]+1==SZ(g[i])){
				u.pb(i);
				vis[i]=1;
			}
		}
	}
	fore(i,0,n){
		if(val[i]%m)return 0;
	}
	return 1;
}

int main(){FIN;
	mobius();
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n)g[i].clear();
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--; v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		vector<ll> c(n+1);
		c[1]=1;
		fore(i,0,n-1)c[1]=c[1]*2%MOD;
		fore(i,2,n){
			if((n-1)%i==0){
				c[i]=can(i);
			}
		}
		//fore(i,1,n+1)cout<<c[i]<<" ";
		//cout<<"\n";
		fore(i,1,n){
			for(ll j=i+i;j<n;j+=i){
				c[i]=(c[i]+c[j]*mu[j/i]+MOD)%MOD;
			}
		}
		fore(i,1,n+1)cout<<c[i]<<" ";
		cout<<"\n";
	}
	
	return 0;
}