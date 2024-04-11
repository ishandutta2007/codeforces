#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

int g[10101010][2];
int gs=0;

struct AhoCorasick {
	vector<int> link;
	vector<int> tlink;
	vector<int> te;
	
	void addString(const string& s, int id) {
		int tn=0;
		for (int i=0;i<(int)s.size();i++) {
			if (g[tn][s[i]-'a']==0) {
				g[tn][s[i]-'a']=gs++;
				link.push_back(0);
				tlink.push_back(0);
				te.push_back(0);
			}
			tn=g[tn][s[i]-'a'];
		}
		te[tn]=id;
	}
	
	void pushLinks() {
		queue<int> bfs;
		bfs.push(0);
		while (!bfs.empty()) {
			int x=bfs.front();
			bfs.pop();
			for (int i=0;i<2;i++) {
				if (g[x][i]==0) continue;
				pair<int, int> nx={i, g[x][i]};
				int l=link[x];
				while (l!=-1&&g[l][nx.F]==0) l=link[l];
				if (l!=-1) link[nx.S]=g[l][nx.F];
				bfs.push(nx.S);
				if (te[link[nx.S]]) {
					tlink[nx.S]=link[nx.S];
				}
				else{
					tlink[nx.S]=tlink[link[nx.S]];
				}
			}
		}
	}
	
	vector<int> match(const string& s) {
		int tn=0;
		vector<int> re;
		for (int i=0;i<(int)s.size();i++) {
			while (tn!=-1&&g[tn][s[i]-'a']==0) tn=link[tn];
			if (tn==-1) tn=0;
			tn=g[tn][s[i]-'a'];
			int f=tlink[tn];
			if (te[tn]) re.push_back(te[tn]);
			if (f) {
				re.push_back(te[f]);
			}
		}
		return re;
	}
	
	AhoCorasick() {
		gs=1;
		link.push_back(-1);
		tlink.push_back(0);
		te.push_back(0);
	}
};

struct MaxFlow {
	// Use vector<map<int, ll> > for sparse graphs
	vector<vector<int> > f;
	vector<vector<int> > g;
	vector<int> used;
	int cc;
	
	int flow(int x, int t, int fl, int miv) {
		if (x==t) return fl;
		used[x]=cc;
		for (int nx:g[x]) {
			if (used[nx]!=cc&&f[x][nx]>=miv) {
				int r=flow(nx, t, min(fl, f[x][nx]), miv);
				if (r>0) {
					f[x][nx]-=r;
					f[nx][x]+=r;
					return r;
				}
			}
		}
		return 0;
	}
	
	// maxv is maximum expected maxflow
	int getMaxFlow(int source, int sink, int maxv) {
		cc=1;
		int r=0;
		int k=1;
		while (k*2<=maxv) k*=2;
		for (;k>0;k/=2) {
			while (int t=flow(source, sink, maxv, k)) {
				r+=t;
				cc++;
			}
			cc++;
		}
		return r;
	}
	
	void addEdge(int a, int b, int c) {
		if (f[a][b]==0&&f[b][a]==0) {
			g[a].push_back(b);
			g[b].push_back(a);
		}
		f[a][b]+=c;
	}
	
	MaxFlow(int n) : f(n+1), g(n+1), used(n+1) {
		for (int i=1;i<=n;i++) {
			f[i]=vector<int>(n+1);
		}
	}
};

string s[800];

int o[800][800];
int rm[800];

int n;

int u[800];

void tc(int x, int so){
	if (u[x]==so) return;
	u[x]=so;
	o[so][x]=1;
	for (int i=1;i<=n;i++){
		if (o[x][i]) tc(i, so);
	}
}

int uu[1600];
int vc[800];

void go(int x, MaxFlow& mf){
	if (uu[x]) return;
	uu[x]=1;
	vc[x/2]^=1;
	for (int nx:mf.g[x]){
		if (mf.f[x][nx]>0){
			go(nx, mf);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	AhoCorasick ac;
	for (int i=1;i<=n;i++){
		cin>>s[i];
		ac.addString(s[i], i);
	}
	ac.pushLinks();
	for (int i=1;i<=n;i++){
		auto t=ac.match(s[i]);
		for (int j:t){
			o[i][j]=1;
		}
	}
	for (int i=1;i<=n;i++){
		tc(i, i);
	}
	for (int i=1;i<=n;i++){
		o[i][i]=0;
	}
	int rd=0;
	for (int i=1;i<=n;i++){
		for (int ii=1;ii<=n;ii++){
			if (o[i][ii]==1&&o[ii][i]==1){
				rm[ii]=1;
				rd++;
				for (int j=1;j<=n;j++){
					o[j][ii]=0;
					o[ii][j]=0;
				}
			}
		}
	}
	MaxFlow mf(2*n+4);
	int so=2*n+3;
	int si=2*n+4;
	for (int i=1;i<=n;i++){
		if (rm[i]==0){
			mf.addEdge(so, i*2, 1);
			mf.addEdge(i*2+1, si, 1);
		}
		for (int ii=1;ii<=n;ii++){
			if (o[i][ii]){
				mf.addEdge(i*2, ii*2+1, n);
			}
		}
	}
	int fl=mf.getMaxFlow(so, si, 1);
	cout<<n-rd-fl<<endl;
	go(so, mf);
	for (int i=1;i<=n;i++){
		if (rm[i]==0&&vc[i]==1){
			cout<<i<<" ";
		}
	}
	cout<<endl;
}