#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int rm[30303];

struct Bridges {
	vector<int> c, h;
	void dfs(vector<pair<int, int> >* g, int x, int pe, int d, vector<int>& ns){
		if (h[x]) return;
		h[x]=d;ns.push_back(x);
		for (auto nx:g[x]) {
			if (rm[nx.S]) continue;
			if (nx.S!=pe) {
				dfs(g, nx.F, nx.S, d+1, ns);
				h[x]=min(h[x], h[nx.F]);
			}
		}
		if (h[x]==d) {
			while (ns.size()>0) {
				int t=ns.back();c[t]=x;
				ns.pop_back();
				if (t==x) break;
			}
		}
	}
	Bridges(vector<pair<int, int> >* g, int n) : c(n+1), h(n+1) {
		vector<int> ns;
		for (int i=1;i<=n;i++) dfs(g, i, -1, 1, ns);
	}
};

int w[30303];
vector<pair<int, int> > g[1010];

int u[1010];

vector<int> dfs(int x, int t, int pe){
	if (x==t) return {pe};
	if (u[x]) return {};
	u[x]=1;
	for (auto nx:g[x]){
		auto r=dfs(nx.F, t, nx.S);
		if (r.size()){
			r.push_back(pe);
			return r;
		}
	}
	return {};
}

vector<pair<int, int> > g2[1010];

pair<int, int> getm(int x, int p, int t){
	if (x==t) return {1, -1};
	pair<int, int> r={0, -1};
	for (auto nx:g2[x]){
		if (nx.F!=p){
			auto asd=getm(nx.F, x, t);
			if (asd.F==1){
				if (r.F==0){
					r=asd;
				}
				else if(asd.S!=-1){
					if (r.S==-1||w[asd.S]<w[r.S]){
						r=asd;
					}
				}
				if (r.S==-1||w[nx.S]<w[r.S]){
					r={1, nx.S};
				}
			}
		}
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int s,t;
	cin>>s>>t;
	for (int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b>>w[i];
		if (a==b) continue;
		g[a].push_back({b, i});
		g[b].push_back({a, i});
	}
	vector<int> p=dfs(s, t, 0);
	if (p.size()==0){
		cout<<0<<endl<<0<<endl;
		return 0;
	}
	p.pop_back();
	int v=2e9+1;
	vector<int> ve;
	for (int e:p){
		rm[e]=1;
		Bridges br(g, n);
		rm[e]=0;
		if (br.c[s]==br.c[t]) continue;
		for (int i=1;i<=n;i++){
			g2[i].clear();
		}
		for (int i=1;i<=n;i++){
			for (auto nx:g[i]){
				if (nx.S==e) continue;
				if (br.c[i]!=br.c[nx.F]){
					g2[br.c[i]].push_back({br.c[nx.F], nx.S});
				}
			}
		}
		auto lol=getm(br.c[s], 0, br.c[t]);
		if (lol.F==0){
			if (w[e]<v){
				v=w[e];
				ve={e};
			}
		}
		else if(w[lol.S]+w[e]<v){
			v=w[lol.S]+w[e];
			ve={lol.S, e};
		}
	}
	if (v==2e9+1){
		cout<<-1<<endl;
		return 0;
	}
	cout<<v<<endl;
	cout<<ve.size()<<endl;
	for (int tt:ve){
		cout<<tt<<" ";
	}
	cout<<endl;
}