#include<bits/stdc++.h>
using namespace std;

bool DEBUG=0;

typedef long long ll;
typedef pair<int,int> ii;
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;i++)
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define SZ(a) ((int)(a).size())
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second
#define pb push_back

const int MAXN=128;
int n,k,d[MAXN],sz[MAXN],pa[MAXN],need;
vector<int>g[MAXN];
void dfs(int v) {
	sz[v]=1;
	for(int i:g[v]) {
		d[i]=d[v]+1;
		assert(pa[i]==v);
		dfs(i);
		sz[v]+=sz[i];
	}
}
void add(int v,vector<int> &res) {
	for(int i:g[v]) {
		if(!need)return;
		res.pb(i),need--;
		add(i,res);
		res.pb(v);
	}
}
void build(vector<int> &pth, int p,vector<int> &res) {
	int v=pth[p];
	assert(d[v]==p);
	res.pb(v);
	if(p+1==SZ(pth))assert(!need);
	if((d[v]+1==k) || (p+1==SZ(pth)))return;
	for(int i:g[v])if(i!=pth[p+1]) {
		if(need) {
			res.pb(i),need--;
			add(i,res);
			res.pb(v);
		}
	}
	build(pth,p+1,res);
}
void solve() {
	cin>>n>>k;
	fore(i,0,n)g[i].clear();
	fore(i,1,n) {
		cin>>pa[i];pa[i]--;
		g[pa[i]].pb(i);
	}
	dfs(0);
	if(DEBUG) {
		cout<<"d: ";fore(i,0,n)cout<<d[i]<<" ";cout<<endl;
		cout<<"sz: ";fore(i,0,n)cout<<sz[i]<<" ";cout<<endl;
	}
	int mx=-1;
	fore(i,0,n)mx=max(mx,d[i]);
	vector<int>pth;
	fore(i,0,n)if(d[i]==mx){
		pth.pb(i);
		while(i)i=pa[i],pth.pb(i);
		reverse(ALL(pth));
		break;
	}
	if(DEBUG) {
		cout<<"path: ";for(int i:pth)cout<<i+1<<" ";cout<<endl;
	}
	vector<int>res;
	need=max(0,k-SZ(pth));
	if(DEBUG)cout<<"need: "<<need<<endl;
	build(pth,0,res);
	cout<<SZ(res)-1<<"\n";
	fore(i,0,SZ(res))cout<<res[i]+1<<" \n"[i==SZ(res)-1];
	if(DEBUG)cout<<endl;
}
int main() {FIN;
	int q;cin>>q;
	while(q--)solve();
}