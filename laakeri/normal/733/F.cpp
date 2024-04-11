#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

struct HLD {
	vector<int> aps, pRoot, pLI, pRI, nPath, nPathId, p;
	int index;
	void dfs1(vector<int>* g, int x) {
		aps[x]=1;
		for (int nx:g[x]) {
			if (nx!=p[x]) {
				p[nx]=x;dfs1(g, nx);
				aps[x]+=aps[nx];
			}
		}
	}
	void dfs2(vector<int>* g, int x, int path, int pi) {
		if (path==-1) {
			path=pRoot.size();
			pRoot.push_back(x);
			pLI.push_back(index);
			pRI.push_back(index);
		}
		nPath[x]=path;
		nPathId[x]=pi;
		pRI[path]=index++;
		int ma=0;
		for (int nx:g[x]){
			if (nx!=p[x]&&aps[nx]>aps[ma]) ma=nx;
		}
		if (ma) dfs2(g, ma, path, pi+1);
		for (int nx:g[x]){
			if (nx!=p[x]&&nx!=ma) dfs2(g, nx, -1, 0);
		}
	}
	HLD(vector<int>* g, int n) : aps(n+1), nPath(n+1), nPathId(n+1), p(n+1) {
		index=0;dfs1(g, 1);
		dfs2(g, 1, -1, 0);
	}
	vector<pair<pair<int, int>, pair<int, int> > > getPath(int a, int b) {
		vector<pair<pair<int, int>, pair<int, int> > > ret;
		while (nPath[a]!=nPath[b]) {
			int pa=nPath[a];
			int pb=nPath[b];
			if (pa>pb) {
				ret.push_back({{pRoot[pa], a}, {pLI[pa], pLI[pa]+nPathId[a]}});
				a=p[pRoot[pa]];
			}
			else {
				ret.push_back({{pRoot[pb], b}, {pLI[pb], pLI[pb]+nPathId[b]}});
				b=p[pRoot[pb]];
			}
		}
		int pa=nPath[a];
		if (nPathId[a]>nPathId[b]) swap(a, b);
		ret.push_back({{a, b}, {pLI[pa]+nPathId[a], pLI[pa]+nPathId[b]}});
		return ret;
	}
};

ll w[202020];
ll c[202020];
int ea[202020];
int eb[202020];
int is[202020];

vector<int> tg[202020];
vector<pair<int, int> > tgg[202020];

const int N=1<<19;
pair<ll, int> st[2*N];

void setv(int i, pair<ll, int> v){
	st[i+N]=v;
	for (i=(i+N)/2;i;i/=2){
		st[i]=max(st[i*2], st[i*2+1]);
	}
}

pair<ll, int> getmax(int a, int b){
	a+=N;
	b+=N;
	pair<ll, int> ma={-1, -1};
	while (a<=b){
		if (a%2) ma=max(ma, st[a++]);
		if (!(b%2)) ma=max(ma, st[b--]);
		a/=2;
		b/=2;
	}
	return ma;
}

void dfs0(int x, int p, HLD& hld){
	for (auto nx:tgg[x]){
		if (nx.F!=p){
			auto pa=hld.getPath(nx.F, nx.F);
			setv(pa[0].S.F, {w[nx.S], nx.S});
			dfs0(nx.F, x, hld);
		}
	}
}

int u[202020];
int getu(int x){
	if (u[x]==x) return x;
	return u[x]=getu(u[x]);
}
void un(int a, int b){
	a=getu(a);
	b=getu(b);
	if (a==b) return;
	u[a]=b;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=m;i++){
		cin>>c[i];
	}
	vector<pair<ll, int> > es;
	for (int i=1;i<=m;i++){
		cin>>ea[i]>>eb[i];
		es.push_back({w[i], i});
	}
	for (int i=1;i<=n;i++){
		u[i]=i;
	}
	sort(es.begin(), es.end());
	for (int i=0;i<m;i++){
		int a=ea[es[i].S];
		int b=eb[es[i].S];
		if (getu(a)!=getu(b)){
			un(a, b);
			is[es[i].S]=1;
			tg[a].push_back(b);
			tg[b].push_back(a);
			tgg[a].push_back({b, es[i].S});
			tgg[b].push_back({a, es[i].S});
		}
	}
	HLD hld(tg, n);
	dfs0(1, 0, hld);
	ll s;
	cin>>s;
	ll minC=1e10;
	ll ans=0;
	int adde=0;
	int rme=0;
	ll su=0;
	for (int i=1;i<=m;i++){
		if (is[i]){
			su+=w[i];
			ans+=w[i];
			minC=min(minC, c[i]);
		}
	}
	ans=ans-s/minC;
	for (int i=1;i<=m;i++){
		if (is[i]==0&&c[i]<minC){
			auto pa=hld.getPath(ea[i], eb[i]);
			pair<ll, int> ma={-1, -1};
			for (int j=0;j<(int)pa.size();j++){
				if (j+1<(int)pa.size()){
					ma=max(ma, getmax(pa[j].S.F, pa[j].S.S));
				}
				else{
					ma=max(ma, getmax(pa[j].S.F+1, pa[j].S.S));
				}
			}
			ll tans=su-ma.F+w[i]-s/c[i];
			if (tans<ans){
				ans=tans;
				adde=i;
				rme=ma.S;
			}
		}
	}
	cout<<ans<<'\n';
	for (int i=1;i<=m;i++){
		if (adde==0){
			if (is[i]){
				if (c[i]==minC){
					w[i]-=s/minC;
					minC=1e10;
				}
				cout<<i<<" "<<w[i]<<"\n";
			}
		}
		else{
			if (is[i]&&i!=rme){
				cout<<i<<" "<<w[i]<<"\n";
			}
			if (i==adde){
				cout<<i<<" "<<w[i]-s/c[i]<<"\n";
			}
		}
	}
}