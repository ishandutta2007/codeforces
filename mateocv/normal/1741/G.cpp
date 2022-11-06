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

const int MAXN=10004;

vector<ll> g[MAXN];

ll d[10][MAXN],vis[10][MAXN];

void bfs(ll id, ll x) {
	//cout<<"bfs "<<id<<" "<<x<<"\n";
	queue<int>q;
	vis[id][x]=1;
	q.push(x);
	while(q.size()) {
		int t=q.front(); q.pop();
		for(int i:g[t]) {
			if(!vis[id][i]) {
				vis[id][i]=1;
				q.push(i);
				d[id][i]=d[id][t]+1;
			}
		}
	}
}

ll dp[MAXN][64];

ll val[MAXN][64];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n)g[i].clear();
		fore(i,0,m){
			ll x,y; cin>>x>>y; x--; y--;
			g[x].pb(y);
			g[y].pb(x);
		}
		fore(i,0,10){
			fore(j,0,n){
				d[i][j]=0;
				vis[i][j]=0;
			}
		}
		bfs(0,0);
		ll f; cin>>f;
		vector<ll> vf(f);
		fore(i,0,f)cin>>vf[i],vf[i]--;
		ll k; cin>>k;
		vector<ll> vk(k);
		fore(i,0,k)cin>>vk[i],vk[i]--;
		set<ll> sk(ALL(vk));
		fore(i,0,k)vk[i]=vf[vk[i]];
		vector<ll> rf;
		fore(i,0,f){
			if(!sk.count(i))rf.pb(vf[i]);
		}
		//cout<<"rf\n";
		//for(auto i:rf)cout<<i<<" ";
		//cout<<"\n";
		//cout<<"vk\n";
		//for(auto i:vk)cout<<i<<" ";
		//cout<<"\n";
		fore(i,0,k){
			bfs(i+1,vk[i]);
		}
		/*
		fore(i,0,k+1){
			cout<<"d "<<i<<"\n";
			fore(j,0,n){
				cout<<d[i][j]<<" ";
			}
			cout<<"\n";
		}
		*/
		fore(i,0,SZ(rf)){
			fore(mk,1,(1ll<<k)){
				vector<pair<ll,ll>> v={{0,0}};
				fore(j,0,k){
					if((1ll<<j)&mk)v.pb({d[0][vk[j]],j+1});
				}
				sort(ALL(v));
				val[i][mk]=1;
				fore(j,0,SZ(v)-1){
					if(v[j+1].fst-v[j].fst!=d[v[j].snd][vk[v[j+1].snd-1]]){
						val[i][mk]=0;
					}
				}
				if(d[0][rf[i]]-v.back().fst!=d[v.back().snd][rf[i]]){
					val[i][mk]=0;
				}
			}
		}
		for(ll i=SZ(rf);i>=0;i--){
			fore(j,0,(1ll<<k)){
				ll &res=dp[i][j];
				if(i==SZ(rf)){
					res=__builtin_popcount(j);
				}else{
					res=dp[i+1][j];
					fore(mk,0,(1ll<<k)){
						if(val[i][mk]&&((mk&j)==mk)){
							res=min(res,dp[i+1][j^mk]);
						}
					}
				}
			}
		}
		cout<<dp[0][(1ll<<k)-1]<<"\n";
	}
	
	return 0;
}