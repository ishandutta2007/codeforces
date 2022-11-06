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
ll F[K][1<<K],D[1<<K],sa[1<<K],sb[1<<K];
void lca_dfs(int x){
	fore(i,0,g[x].size()){
		int y=g[x][i];if(y==F[0][x])continue;
		F[0][y]=x;D[y]=D[x]+1;
		sa[y]+=sa[x]; sb[y]+=sb[x];
		lca_dfs(y);
	}
}

void lca_init(){
	D[0]=0;F[0][0]=-1;
	lca_dfs(0);
	fore(k,1,K)fore(x,0,n)
		if(F[k-1][x]<0)F[k][x]=-1;
		else F[k][x]=F[k-1][F[k-1][x]];
}

int getp(int x, int k){
	fore(i,0,K){
		if((1ll<<i)&k)x=F[i][x];
	}
	return x;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n)g[i].clear();
		fore(i,1,n){
			ll p,a,b; cin>>p>>a>>b; p--;
			g[p].pb(i);
			g[i].pb(p);
			sa[i]=a;
			sb[i]=b;
		}
		lca_init();
		fore(i,1,n){
			ll l=0,r=D[i];
			while(l<=r){
				ll m=(l+r)/2;
				if(sb[getp(i,D[i]-m)]<=sa[i])l=m+1;
				else r=m-1;
			}
			cout<<r<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}