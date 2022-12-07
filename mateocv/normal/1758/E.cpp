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

ll h;
const ll MOD=1000000007;
const int MAXN=400005;
int pa[MAXN],sz[MAXN],c[MAXN],val[MAXN],br;
vector<ll> el[MAXN]; 
ll find_pa(ll pos){
	if(pa[pos]!=pos)pa[pos]=find_pa(pa[pos]);
	return pa[pos];
}
void join(int a, int b, ll s) {
	int x=find_pa(a),y=find_pa(b);
	if(x!=y) {
		if(sz[x]>=sz[y])swap(x,y),swap(a,b);
		if(c[a]==c[b]){
			for(auto i:el[x])c[i]^=1;
		}
		ll d=(s+h+h-val[a]-val[b])%h;
		for(auto i:el[x]){
			if(c[i]==c[a])val[i]=(val[i]+d)%h;
			else val[i]=(val[i]+h-d)%h;
		}
		for(auto i:el[x])el[y].pb(i);
		el[x].clear();
		sz[y]+=sz[x];
		pa[x]=y;
	}else{
		if((val[a]+val[b])%h!=s)br=1;
	}
}
void dsu_init(ll n){fore(i,0,n)pa[i]=i,sz[i]=1,c[i]=0,val[i]=0,el[i]={i};br=0;}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m>>h;
		dsu_init(n+m);
		fore(i,0,n){
			fore(j,0,m){
				ll x; cin>>x;
				if(x!=-1){
					join(i,n+j,x);
				}
			}
		}
		if(br){
			cout<<"0\n";
			continue;
		}
		ll cant=0;
		fore(i,0,n+m)cant+=(find_pa(i)==i);
		cant--;
		ll res=1;
		fore(i,0,cant)res=res*h%MOD;
		cout<<res<<"\n";
	}
	
	return 0;
}