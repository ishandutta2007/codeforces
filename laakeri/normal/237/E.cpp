#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

const ll inf=1e18;

struct minCostFlow {
	vector<vector<ll> > f;
	vector<vector<int> > g;
	vector<vector<ll> > c;
	vector<ll> d;
	vector<int> from;
	vector<int> inq;
	queue<int> spfa;
	int cc;
	
	void relax(int x, ll di, int p) {
		if (di>=d[x]) return;
		d[x]=di;
		from[x]=p;
		if (!inq[x]) {
			spfa.push(x);
			inq[x]=1;
		}
	}
	
	ll augment(ll x, ll s, ll fl) {
		if (x==s) return fl;
		ll r=augment(from[x], s, min(fl, f[from[x]][x]));
		f[from[x]][x]-=r;
		f[x][from[x]]+=r;
		return r;
	}
	
	pair<ll, ll> flow(int s, int t, ll miv, ll kf) {
		int n=g.size()-1;
		for (int i=1;i<=n;i++) {
			d[i]=inf;
			inq[i]=0;
		}
		relax(s, 0, 0);
		while (!spfa.empty()) {
			int x=spfa.front();
			spfa.pop();
			inq[x]=0;
			for (int nx:g[x]) {
				if (f[x][nx]>=miv) {
					relax(nx, d[x]+c[x][nx], x);
				}
			}
		}
		if (d[t]<inf) {
			ll fl=augment(t, s, kf);
			return {fl, fl*d[t]};
		}
		return {0, 0};
	}
	
	// maxv is maximum possible flow on a single augmenting path
	// kf is inteded flow, set infinite for maxflow
	// returns {flow, cost}
	pair<ll, ll> getKFlow(int source, int sink, ll maxv, ll kf) {
		int n=g.size()-1;
		for (int i=1;i<=n;i++) {
			g[i].clear();
			for (int ii=1;ii<=n;ii++) {
				if (f[i][ii]!=0||f[ii][i]!=0) {
					g[i].push_back(ii);
				}
			}
		}
		cc=1;
		ll r=0;
		ll k=1;
		ll co=0;
		while (k*2<=maxv) k*=2;
		for (;k>0&&kf>0;k/=2) {
			while (1) {
				pair<ll, ll> t=flow(source, sink, k, kf);
				r+=t.F;
				kf-=t.F;
				co+=t.S;
				cc++;
				if (kf==0||t.F==0) break;
			}
			cc++;
		}
		return {r, co};
	}
	
	void addEdge(int a, int b, ll capa, ll cost) {
		f[a][b]=capa;
		c[a][b]=cost;
		c[b][a]=-cost;
	}
	
	minCostFlow(int n) : f(n+1), g(n+1), c(n+1), d(n+1), from(n+1), inq(n+1) {
		for (int i=1;i<=n;i++) {
			f[i]=vector<ll>(n+1);
			c[i]=vector<ll>(n+1);
		}
	}
};

string ss[111];
int ct[30];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	for (char c:s){
		ct[c-'a']++;
	}
	int n;
	cin>>n;
	minCostFlow mf(n+100);
	for (int i=0;i<30;i++){
		if (ct[i]>0){
			mf.addEdge(n+10+i, n+40, ct[i], 0);
		}
	}
	for (int i=1;i<=n;i++){
		cin>>ss[i];
		int a;
		cin>>a;
		mf.addEdge(n+4, i, min(a, (int)ss[i].size()), i);
		vector<int> cc(30);
		for (char c:ss[i]){
			cc[c-'a']++;
		}
		for (int ii=0;ii<30;ii++){
			if (cc[ii]>0){
				mf.addEdge(i, n+10+ii, cc[ii], 0);
			}
		}
	}
	pair<ll, ll> t=mf.getKFlow(n+4, n+40, 1, (int)s.size());
	if (t.F<(int)s.size()){
		cout<<-1<<endl;
	}
	else{
		cout<<t.S<<endl;
	}
}