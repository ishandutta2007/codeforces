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

const int K=19;

vector<int> g[1<<K];int n;  // K such that 2^K>=n
int F[K][1<<K],D[1<<K];
void lca_dfs(int x){
	fore(i,0,g[x].size()){
		int y=g[x][i];if(y==F[0][x])continue;
		F[0][y]=x;D[y]=D[x]+1;lca_dfs(y);
	}
}
void lca_init(){
	D[0]=0;F[0][0]=-1;
	lca_dfs(0);
	fore(k,1,K)fore(x,0,n)
		if(F[k-1][x]<0)F[k][x]=-1;
		else F[k][x]=F[k-1][F[k-1][x]];
}
int lca(int x, int y){
	//cout<<"lca "<<x<<" "<<y<<" ";
	if(D[x]<D[y])swap(x,y);
	for(int k=K-1;k>=0;--k)if(D[x]-(1<<k)>=D[y])x=F[k][x];
	if(x==y)return x;
	for(int k=K-1;k>=0;--k)if(F[k][x]!=F[k][y])x=F[k][x],y=F[k][y];
	//cout<<F[0][x]<<"\n";
	return F[0][x];
}


int main(){FIN;
	cin>>n;
	fore(i,0,n-1){
		ll x,y; cin>>x>>y; x--; y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	lca_init();
	ll q; cin>>q;
	while(q--){
		ll k; cin>>k;
		vector<pair<ll,ll>> v(k);
		fore(i,0,k){
			cin>>v[i].snd;
			v[i].snd--;
			v[i].fst=D[v[i].snd];
		}
		sort(ALL(v));
		reverse(ALL(v));
		ll br=0;
		fore(i,0,k-1){
			if(lca(v[i].snd,v[i+1].snd)!=v[i+1].snd)br++;
		}
		if(!br)cout<<"YES\n";
		else{
			br=0;
			ll mini1=v[0].snd,mini2=-1;
			for(auto i:v){
				if(lca(mini1,i.snd)!=i.snd&&(mini2==-1||lca(mini2,i.snd)!=i.snd)){
					if(mini2==-1)mini2=i.snd;
					else br++;
				}
			}
			if(br){
				cout<<"NO\n";
				continue;
			}
			ll maxi=lca(mini1,mini2);
			//cout<<"mx "<<maxi<<"\n";
			for(auto i:v){
				if(lca(maxi,i.snd)!=maxi){
					//cout<<maxi<<" "<<i.snd<<" "<<lca(maxi,i.snd)<<"\n";
					br++;
				}
			}
			if(br)cout<<"NO\n";
			else cout<<"YES\n";
		}
	}
	
	return 0;
}