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

const ll MAXN=2019;
int uf[MAXN];
void uf_init(){memset(uf,-1,sizeof(uf));}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
vector<pair<ll,pair<int,int> > > es; // edges (cost,(u,v))
vector<pair<ll,pair<int,int> > > mst;
ll kruskal(){  // assumes graph is connected
	sort(es.begin(),es.end());uf_init();
	ll r=0;
	fore(i,0,es.size()){
		int x=es[i].snd.fst,y=es[i].snd.snd;
		if(uf_join(x,y)){ // (x,y,c) belongs to mst
			r+=es[i].fst;
			mst.pb(es[i]);
		}
	}
	return r; // total cost
}

int main(){FIN;
	ll n; cin>>n;
	ll x[n][2];
	ll c[n],k[n];
	fore(i,0,n)cin>>x[i][0]>>x[i][1];
	fore(i,0,n)cin>>c[i];
	fore(i,0,n)cin>>k[i];
	fore(i,0,n){
		fore(j,i+1,n){
			es.pb({(k[i]+k[j])*(abs(x[i][0]-x[j][0])+abs(x[i][1]-x[j][1])),{i,j}});
		}
	}
	fore(i,0,n){
		es.pb({c[i],{i,n}});
	}
	cout<<kruskal()<<"\n";
	vector<ll> v;
	for(auto i:mst){
		if(i.snd.snd==n){
			v.pb(i.snd.fst);
		}
	}
	cout<<SZ(v)<<"\n";
	for(auto i:v)cout<<i+1<<" "; cout<<"\n";
	cout<<SZ(mst)-SZ(v)<<"\n";
	for(auto i:mst){
		if(i.snd.snd!=n){
			cout<<i.snd.fst+1<<" "<<i.snd.snd+1<<"\n";
		}
	}
	return 0;
}