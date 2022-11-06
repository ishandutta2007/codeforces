#include <bits/stdc++.h>
#define pb push_back
#define mpair make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

vector<ll> g[2010];
ll vis[2010];
ll vist[2010];
vector<ll> v;
ll res[2010];
map<ll,ll> mp;

void dfs(ll i){
	if(vis[i])return;
	vis[i]=1;
	for(auto j:g[i])dfs(j);
	v.pb(i);
}

/*---------------- Union Find (DSU) ------------------*/
const ll N=3e5+10;
int pa[N],sz[N];
ll find_pa(ll pos){
	if(pa[pos]!=pos)pa[pos]=find_pa(pa[pos]);
	return pa[pos];
}
void join(int a, int b) {
	int x=find_pa(a),y=find_pa(b);
	if (x!=y) {
		if(sz[x]>=sz[y]) sz[x]+=sz[y],pa[y]=x;
		else sz[y]+=sz[x],pa[x]=y;
	}
}
void dsu_init(ll n){fore(i,0,n)pa[i]=i,sz[i]=1;}

ll solve(ll i){
	if(res[i]>=0)return res[i];
	if(find_pa(i)!=i){
		res[i]=solve(find_pa(i));return res[i];	
	}
	ll maxi=-1;
	for(auto j:g[i])maxi=max(maxi,solve(j));	
	if(maxi==-1){
		res[i]=1; return res[i];
	}
	res[i]=maxi+1; return res[i];
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	char c[n][m];
	fore(i,0,n){
		fore(j,0,m){
			cin>>c[i][j];
		}
	}
	dsu_init(n+m);
	fore(i,0,n){
		fore(j,0,m){
			if(c[i][j]=='=')join(i,n+j);
		}
	}
	fore(i,0,n+m){
		vist[find_pa(i)]=1;
	}
	fore(i,0,n){
		fore(j,0,m){
			if(c[i][j]=='>')g[find_pa(i)].pb(find_pa(n+j));
			if(c[i][j]=='<')g[find_pa(n+j)].pb(find_pa(i));
		}
	}
	fore(i,0,n+m){
		if(vist[i])dfs(i);
	}
	reverse(ALL(v));
//	fore(i,0,SZ(v))cout<<v[i]<<" "; cout<<"\n";
	fore(i,0,SZ(v)){
		mp[v[i]]=i;
	}
	fore(i,0,n+m){
		if(vist[i]){
			for(auto j:g[i]){
				if(mp[i]>=mp[j]){
					cout<<"No"/*<<" "<<i<<" "<<j<<" "<<mp[i]<<" "<<mp[j]*/; return 0;
				}
			}
		}
	}
	mset(res,-1);
//	res[SZ(v)-1]=1;
	/*fore(i,0,n+m){
		res[i]=solve(i);
	}*/
	cout<<"Yes\n";
	fore(i,0,n)cout<<solve(i)<<" "; cout<<"\n";
	fore(i,0,m)cout<<solve(n+i)<<" "; cout<<"\n";
	return 0;
}