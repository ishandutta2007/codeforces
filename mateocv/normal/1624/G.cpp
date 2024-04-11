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

vector<pair<ll,pair<ll,ll>>> filt(vector<pair<ll,pair<ll,ll>>> v, ll b){
	vector<pair<ll,pair<ll,ll>>> res;
	for(auto i:v){
		if(!(i.fst&(1ll<<b)))res.pb(i);
	}
	return res;
}

const int MAXN=200005;
int pa[MAXN],sz[MAXN];
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

bool cc(vector<pair<ll,pair<ll,ll>>> v, ll n){
	dsu_init(n);
	for(auto i:v)join(i.snd.fst,i.snd.snd);
	ll cant=0;
	fore(i,0,n)cant+=(find_pa(i)==i);
	return cant==1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<pair<ll,pair<ll,ll>>> ed;
		fore(i,0,m){
			ll x,y,w; cin>>x>>y>>w; x--; y--;
			ed.pb({w,{x,y}});
		}
		for(ll i=30;i>=0;i--){
			auto ned=filt(ed,i);
			if(cc(ned,n))ed=ned;
		}
		ll res=0;
		for(auto i:ed)res=(res|i.fst);
		cout<<res<<"\n";
	}
	
	return 0;
}