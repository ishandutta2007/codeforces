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

ll ask(ll x){
	cout<<"? "<<x+1<<endl;
	ll resp; cin>>resp;
	resp--;
	return resp;
}

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
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> d(n);
		fore(i,0,n)cin>>d[i];
		dsu_init(n);
		vector<pair<ll,ll>> vp;
		fore(i,0,n)vp.pb({d[i],i});
		sort(ALL(vp));
		reverse(ALL(vp));
		for(auto i:vp){
			fore(j,0,i.fst){
				if(sz[find_pa(i.snd)]>j+1)break;
				auto a=ask(i.snd);
				join(a,i.snd);
			}
		}
		cout<<"! ";
		fore(i,0,n)cout<<find_pa(i)+1<<" ";
		cout<<endl;
	}
	
	return 0;
}