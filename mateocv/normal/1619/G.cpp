#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const int MAXN=200005;
ll pa[MAXN],sz[MAXN],mini[MAXN];
ll find_pa(ll pos){
	if(pa[pos]!=pos)pa[pos]=find_pa(pa[pos]);
	return pa[pos];
}
void join(int a, int b) {
	int x=find_pa(a),y=find_pa(b);
	if (x!=y) {
		if(sz[x]>=sz[y]) swap(x,y);
		sz[y]+=sz[x],pa[x]=y,mini[y]=min(mini[y],mini[x]);
	}
}
void dsu_init(ll n){fore(i,0,n)pa[i]=i,sz[i]=1;}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vector<pair<pair<ll,ll>,ll>> a(n);
		vector<ll> ti(n);
		fore(i,0,n)cin>>a[i].fst.fst>>a[i].fst.snd>>ti[i],a[i].snd=i;
		dsu_init(n);
		fore(i,0,n)mini[i]=ti[i];
		sort(ALL(a));
		fore(i,0,n-1){
			if(a[i].fst.fst==a[i+1].fst.fst&&abs(a[i].fst.snd-a[i+1].fst.snd)<=k){
				join(a[i].snd,a[i+1].snd);
			}
		}
		fore(i,0,n)swap(a[i].fst.fst,a[i].fst.snd);
		sort(ALL(a));
		fore(i,0,n-1){
			if(a[i].fst.fst==a[i+1].fst.fst&&abs(a[i].fst.snd-a[i+1].fst.snd)<=k){
				join(a[i].snd,a[i+1].snd);
			}
		}
		vector<ll> v;
		fore(i,0,n){
			if(find_pa(i)==i){
				v.pb(mini[i]);
			}
		}
		sort(ALL(v));
		ll res=SZ(v)-1;
		fore(i,0,SZ(v)){
			res=min(res,max(v[i],SZ(v)-i-2));
		}
		cout<<res<<"\n";
	}
	
	return 0;
}