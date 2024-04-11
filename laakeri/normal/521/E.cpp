// Finds cutvertices and 2-vertex-connected components of graph
// Uses 1-indexing
#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

struct Biconnected{
	vector<int> cut;
	vector<int> h;
	vector<int> d;
	vector<map<int, vector<int> > > bg;
	vector<pair<int, int> > es;
	vector<int> used;
	int cc;
	void dfs1(vector<int>* g, int x, int p) {
		h[x]=d[x];
		int f=0;
		for (int nx:g[x]) {
			if (nx!=p) {
				if (!used[nx]) es.push_back({x, nx});
				if (d[nx]==0) {
					f++;
					d[nx]=d[x]+1;
					int ts=es.size();
					dfs1(g, nx, x);
					h[x]=min(h[x], h[nx]);
					if (h[nx]>=d[x]) {
						cut[x]=1;
						while ((int)es.size()>=ts) {
							auto e=es.back();
							bg[e.F][cc].push_back(e.S);
							bg[e.S][cc].push_back(e.F);
							used[e.S]=1;
							used[e.F]=1;
							es.pop_back();
						}
						used[x]=0;
						cc++;
					}
				}
				h[x]=min(h[x], d[nx]);
			}
		}
		if (p==0) {
			if (f>1) cut[x]=1;
			else cut[x]=0;
		}
	}
	
	Biconnected(vector<int>* g, int n) : cut(n+1), h(n+1), d(n+1), bg(n+1), used(n+1) {
		cc=1;
		for (int i=1;i<=n;i++) {
			if (d[i]==0) {
				d[i]=1;
				dfs1(g, i, 0);
			}
		}
	}
};

int fr[200001];
int used4[200001];
int used5[200001];
int okk[200001];
int ff=0;
vector<int> vv;
void pr(){
	cout<<vv.size()<<" ";
	for (int x:vv){
		cout<<x<<" ";
	}
	cout<<'\n';
	vv.clear();
}
int dfs5(int x, int c, int sx, vector<map<int, vector<int> > >&g){
	if (used5[x]) return 0;
	used5[x]=1;
	vv.push_back(x);
	if (okk[x]==c) return x;
	for (int nx:g[x][c]){
		if (nx!=sx){
			int asd=dfs5(nx, c, sx, g);
			if (asd>0) return asd;
		}
	}
	vv.pop_back();
	return 0;
}

void dfs4(int x, int p, int c, vector<map<int, vector<int> > >&g){
	fr[x]=p;
	used4[x]=c;
	//cout<<x<<" "<<c<<endl;
	for (int nx:g[x][c]){
		if (nx!=p){
			if (used4[nx]==c){
				ff=1;
				vector<int> lol;
				lol.push_back(nx);
				okk[nx]=c;
				int xx=x;
				while (1){
					okk[xx]=c;
					lol.push_back(xx);
					xx=fr[xx];
					if (xx==nx) break;
				}
				fr[nx]=x;
				for (int i=0;i<(int)lol.size();i++){
					for (int nxx:g[lol[i]][c]){
						if (okk[nxx]!=c){
							cout<<"YES\n";
							vv.push_back(lol[i]);
							int asd=dfs5(nxx, c, lol[i], g);
							pr();
							for (int ii=i;;ii++){
								vv.push_back(lol[ii%(int)lol.size()]);
								if (lol[ii%(int)lol.size()]==asd) break;
							}
							pr();
							for (int ii=i;;ii--){
								vv.push_back(lol[(ii+(int)lol.size())%(int)lol.size()]);
								if (lol[(ii+(int)lol.size())%(int)lol.size()]==asd) break;
							}
							pr();
							exit(0);
						}
						else if(nxx!=fr[lol[i]]&&fr[nxx]!=lol[i]){
							cout<<"YES\n";
							cout<<"2 "<<lol[i]<<" "<<nxx<<'\n';
							for (int ii=i;;ii++){
								vv.push_back(lol[ii%(int)lol.size()]);
								if (lol[ii%(int)lol.size()]==nxx) break;
							}
							pr();
							for (int ii=i;;ii--){
								vv.push_back(lol[(ii+(int)lol.size())%(int)lol.size()]);
								if (lol[(ii+(int)lol.size())%(int)lol.size()]==nxx) break;
							}
							pr();
							exit(0);
						}
					}
				}
				return;
			}
			else{
				dfs4(nx, x, c, g);
				if (ff) return;
			}
		}
	}
}

vector<int> g[202020];

int uc[202020];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	Biconnected b(g, n);
	for (int i=1;i<=n;i++){
		for (auto&c:b.bg[i]){
			if (!uc[c.F]){
				uc[c.F]=1;
				dfs4(i, 0, c.F, b.bg);
			}
		}
	}
	cout<<"NO\n";
}