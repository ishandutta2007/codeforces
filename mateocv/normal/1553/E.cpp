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

/*----------------DSU------------------*/
const int MAXN=300005;
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

bool solve(vector<ll> a, ll k, ll m){
	//cout<<k<<":\n";
	ll n=SZ(a);
	vector<ll> u(n);
	fore(i,0,n)u[i]=(i+k)%n;
	fore(i,0,n)a[i]=u[a[i]];
	//for(auto i:a)cout<<i<<" ";
	//cout<<"\n";
	dsu_init(n);
	fore(i,0,n)join(i,a[i]);
	ll tot=0;
	fore(i,0,n){
		if(find_pa(i)==i){
			tot+=sz[find_pa(i)]-1;
		}
	}
	return m>=tot;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		map<ll,ll> mp;
		fore(i,0,n){
			mp[(i-a[i]+n)%n]++;
		}
		vector<ll> res;
		for(auto i:mp){
			if(i.snd>=n/3){
				if(solve(a,i.fst,m))res.pb(i.fst);
			}
		}
		sort(ALL(res));
		cout<<SZ(res)<<" ";
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";
	}
	
	return 0;
}