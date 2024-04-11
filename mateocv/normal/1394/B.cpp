#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef int ll;

vector<pair<ll,ll>> g[200005];
vector<ll> gr[200005];
ll f[10];

ll vis[100][100];

int main(){FIN;
	ll n,m,k; cin>>n>>m>>k;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--; v--; w--;
		g[u].pb({w,v});
	}
	fore(i,0,n)sort(ALL(g[i]));
	f[0]=1;
	fore(i,1,10)f[i]=f[i-1]*i;
	fore(i,0,n){
		fore(j,0,SZ(g[i])){
			gr[g[i][j].snd].pb(10*SZ(g[i])+j);
		}
	}
	fore(i,0,n){
		if(SZ(gr[i])==0){
			cout<<0;
			return 0;
		}
		//sort(ALL(gr[i]));
		//cout<<i<<": ";
		//for(auto j:gr[i])cout<<j<<" "; cout<<"\n";
		set<ll> st[2];
		for(auto j:gr[i]){
			if(!st[0].count(j)){
				st[0].insert(j);
			}else if(!st[1].count(j)){
				st[1].insert(j);
			}
		}
		vector<ll> v;
		fore(k,0,2){
			for(auto i:st[k])v.pb(i);
		}
		sort(ALL(v));
		fore(j,0,SZ(v)){
			fore(jj,j+1,SZ(v)){
				vis[v[j]][v[jj]]=1;
			}
		}
	}
	ll res=0;
	fore(i,0,f[k]){
		ll v[k];
		ll va=i;
		fore(j,0,k){
			v[j]=(va/f[k-1-j]);
			va-=v[j]*f[k-1-j];
		}
		reverse(v,v+k);
		//auto u=v;
		fore(i,0,k){
			v[i]+=10*(i+1);
		}
		ll br=0;
		fore(j,0,k){
			fore(jj,j,k){
				if(vis[v[j]][v[jj]]){
					br++; break;
				}
			}
			if(br)break;
		}
		if(!br){
			res++;
			//for(auto j:u)cout<<j<<" "; cout<<"\n";
		}
	}
	cout<<res<<"\n";
	return 0;
}