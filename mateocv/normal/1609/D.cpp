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
const int MAXN=1010;
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

int main(){FIN;
	ll n,d; cin>>n>>d;
	dsu_init(n);
	ll ex=0;
	while(d--){
		ll x,y; cin>>x>>y; x--; y--;
		if(find_pa(x)!=find_pa(y)){
			join(x,y);
		}else{
			ex++;
		}
		vector<ll> cs;
		fore(i,0,n){
			if(find_pa(i)==i)cs.pb(sz[i]);
		}
		sort(ALL(cs));
		reverse(ALL(cs));
		ll res=0;
		fore(i,0,ex+1)res+=cs[i];
		cout<<res-1<<"\n";
	}
	
	return 0;
}