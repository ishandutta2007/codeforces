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

const int MAXN=200005;

vector<ll> g[MAXN];

ll ex[MAXN];

ll fib[50];

ll vis[MAXN],h[MAXN],p[MAXN];

void dfs(ll u){
	vis[u]=1;
	for(auto i:g[u]){
		if(ex[i]&&!vis[i]){
			dfs(i);
			h[u]+=h[i];
			p[i]=u;
		}
	}
	h[u]++;
}

bool solve(vector<ll> v){
	//cout<<"solve de: ";
	//for(auto i:v)cout<<i<<" ";
	//cout<<endl;
	if(SZ(v)==1)return true;
	ll pos=-1;
	fore(i,0,30){
		if(SZ(v)==fib[i]){
			pos=i;
			break;
		}
	}
	if(pos==-1)return false;
	for(auto i:v)ex[i]=1,vis[i]=0,h[i]=0,p[i]=-1;
	dfs(v[0]);
	//fore(i,0,3)cout<<h[i]<<" ";
	//cout<<endl;
	for(auto i:v){
		if(h[i]==fib[pos-1]||h[i]==fib[pos-2]){
			for(auto j:v)vis[j]=0,h[j]=0;
			assert(p[i]!=-1);
			vis[p[i]]=1;
			dfs(i);
			vis[p[i]]=0;
			vector<ll> l,r;
			for(auto j:v){
				if(vis[j])l.pb(j);
				else r.pb(j);
			}
			for(auto i:v)ex[i]=0;
			assert(SZ(l)&&SZ(r));
			return solve(l)&&solve(r);
		}
	}
	return false;
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	vector<ll> v;
	fore(i,0,n)v.pb(i);
	fib[0]=1;
	fib[1]=1;
	fore(i,2,30)fib[i]=fib[i-1]+fib[i-2];
	//fore(i,0,30)cout<<i<<" "<<fib[i]<<"\n";
	auto res=solve(v);
	if(res)cout<<"YES\n";
	else cout<<"NO\n";
	
	return 0;
}