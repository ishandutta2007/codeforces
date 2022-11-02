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
				p[nx]=x;
				dfs1(g, nx);
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
		index=0;
		dfs1(g, 1);
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

vector<int> g[101010];
const int N=1<<17;

ll st0[4*N];
int dl[101010];
int dr[101010];
int i2=0;
void dfs0(int x, int p){
	dl[x]=i2++;
	for (int nx:g[x]){
		if (nx!=p){
			dfs0(nx, x);
		}
	}
	dr[x]=i2++;
}

void add0(int a, int b, ll x){
	a+=2*N;
	b+=2*N;
	while (a<=b){
		if (a%2) st0[a++]+=x;
		if (!(b%2)) st0[b--]+=x;
		a/=2;
		b/=2;
	}
}

ll sum0(int i){
	ll s=0;
	for (i+=2*N;i;i/=2){
		s+=st0[i];
	}
	return s;
}

pair<ll, int> st[2*N];
ll sisu[2*N];
vector<pair<ll, int> > vc[N];

void add(int i, int stl, int str, int l, int r, ll x){
	if (str<l||stl>r) return;
	if (l<=stl&&str<=r){
		st[i].F+=x;
		sisu[i]+=x;
	}
	else{
		int m=(stl+str)/2;
		add(i*2, stl, m, l, r, x);
		add(i*2+1, m+1, str, l, r, x);
		st[i]=min(st[i*2], st[i*2+1]);
		st[i].F+=sisu[i];
	}
}

pair<ll, int> getmin(int i, int stl, int str, int l, int r){
	if (str<l||stl>r) return {1e18, 0};
	if (l<=stl&&str<=r){
		return st[i];
	}
	else{
		int m=(stl+str)/2;
		auto ret=min(getmin(i*2, stl, m, l, r), getmin(i*2+1, m+1, str, l, r));
		ret.F+=sisu[i];
		return ret;
	}
}

void popele(int i, int stl, int str, int k){
	if (k<stl||k>str) return;
	if (stl==str){
		vc[i-N].pop_back();
		if (vc[i-N].size()==0) st[i]={1e18, 0};
		else st[i]=vc[i-N].back();
		st[i].F+=sisu[i];
	}
	else{
		int m=(stl+str)/2;
		popele(i*2, stl, m, k);
		popele(i*2+1, m+1, str, k);
		st[i]=min(st[i*2], st[i*2+1]);
		st[i].F+=sisu[i];
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,q;
	cin>>n>>m>>q;
	for (int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs0(1, 0);
	HLD hld(g, n);
	for (int i=1;i<=m;i++){
		int a;
		cin>>a;
		auto p=hld.getPath(a, a);
		int id=p[0].S.F;
		vc[id].push_back({i, a});
	}
	for (int i=0;i<n;i++){
		sort(vc[i].rbegin(), vc[i].rend());
	}
	for (int i=0;i<N;i++){
		if (vc[i].size()==0) st[i+N]={1e18, 0};
		else st[i+N]=vc[i].back();
	}
	for (int i=N-1;i;i--){
		st[i]=min(st[i*2], st[i*2+1]);
	}
	for (int qq=0;qq<q;qq++){
		int ty;
		cin>>ty;
		if (ty==1){
			int v,u,k;
			cin>>v>>u>>k;
			auto p=hld.getPath(v, u);
			int f=1;
			vector<int> vv;
			while (f==1&&k>0){
				f=0;
				k--;
				pair<ll, int> best={1e18, 0};
				for (auto pp:p){
					int pi=hld.nPath[pp.F.F];
					ll ad=sum0(dl[hld.pRoot[pi]]);
					auto t=getmin(1, 0, N-1, pp.S.F, pp.S.S);
					t.F+=ad;
					best=min(best, t);
				}
				if (best.S>0){
					f=1;
					auto tp=hld.getPath(best.S, best.S);
					int id=tp[0].S.F;
					int gid=vc[id].back().F;
					vv.push_back(gid);
					popele(1, 0, N-1, id);
				}
			}
			cout<<vv.size()<<" ";
			for (int vvv:vv){
				cout<<vvv<<" ";
			}
			cout<<"\n";
		}
		else{
			int v;
			ll k;
			cin>>v>>k;
			add0(dl[v], dr[v], k);
			auto p=hld.getPath(v, v);
			int pi=hld.nPath[p[0].F.F];
			if (hld.pRoot[pi]!=v){
				add(1, 0, N-1, p[0].S.F, hld.pRI[pi], k);
			}
		}
	}
}