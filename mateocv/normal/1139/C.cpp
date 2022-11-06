#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll n;
ll MOD=1ll*1e9+7;
ll be(ll b, ll e, ll mod){
  ll r=1;
  while(e)if(e&1)r=(r*b)%mod,e^=1; else b=(b*b)%mod,e/=2;
  return r;
}

/*---------------- Union Find (DSU) ------------------*/
/* Sets up array parent where parent[i] is a member of its
	disjoint set. See DSU file for an example*/
const int N=3e5+10;
int pa[N],sz[N];
int find_pa(int pos){
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
void dsu_init(){fore(i,0,n)pa[i]=i,sz[i]=1;}

int main(){FIN;
	ll k; cin>>n>>k;
	ll a,b,c;
	dsu_init();
	fore(i,0,n-1){
		cin>>a>>b>>c;
		if(!c){
			join(a-1,b-1);
		}
		
	}
	ll res=be(n,k,MOD);
	ll vis[n];
	memset(vis,0,sizeof vis);
	fore(i,0,n){
		if(!vis[find_pa(i)]){
			res-=be(sz[find_pa(i)],k,MOD);
			res+=MOD;
			res%=MOD;
			vis[find_pa(i)]=1;
		}
	}
	cout<<res;
	
	return 0;
}