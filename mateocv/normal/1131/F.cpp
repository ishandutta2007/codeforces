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
/*---------------- Union Find (DSU) ------------------*/
/* Sets up array parent where parent[i] is a member of its
	disjoint set. See DSU file for an example*/
const int N=2e5;
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
	cin>>n;
	vector<ll> v[n];
	ll a,b;
	dsu_init();
	fore(i,0,n)v[i].pb(i);
	fore(i,0,n-1){
		cin>>a>>b;
		a--; b--;
		ll p=find_pa(a),q=find_pa(b);
		join(a,b);
		if(find_pa(a)==p){
			fore(j,0,SZ(v[q])){
				v[p].pb(v[q][j]);
			}
		}else{
			fore(j,0,SZ(v[p])){
				v[q].pb(v[p][j]);
			}
		}
	}
	ll t=find_pa(0);
	/*fore(i,0,n){
		fore(j,0,SZ(v[i])){
			cout<<v[i][j]+1<<" ";
		}
		cout<<"\n";
	}*/
	fore(j,0,SZ(v[t])){
			cout<<v[t][j]+1<<" ";
		}
	
	return 0;
}