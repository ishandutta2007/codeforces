#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


struct Flow{
	int n;
	vector<vector<int> > graph; //list of id's
	vector<int> st, en, back; //back = back edge id
	vector<LL> f, c;
	vector<int> par;
	Flow(int n): n(n), graph(n), par(n){}
	void add_edge(int u, int v, int cap){
		int id1 = st.size();
		int id2 = id1 + 1;
		st.push_back(u); st.push_back(v);
		en.push_back(v); en.push_back(u);
		back.push_back(id2); back.push_back(id1);
		f.push_back(0); f.push_back(0);
		c.push_back(cap); c.push_back(0);
		graph[u].push_back(id1);
		graph[v].push_back(id2);
	}

	void add(int id1, int v){
		f[id1] += v;
		c[id1] -= v;
		f[back[id1]] -= v;
		c[back[id1]] += v;
	}

	LL maxflow(int s, int t){
		LL ans = 0;
		vector<int> bfs;
		if(s == t) return ans;
		while(1){
			for(int i = 0; i < n; i++) par[i] = -1;
			bfs.clear();
			bfs.push_back(s); par[s] = -2;
			int cur = 0;
			while(cur < bfs.size()){
				int u = bfs[cur]; cur++;
				for(int i = 0; i < graph[u].size(); i++){
					int id = graph[u][i];
					if(c[id] == 0) continue;
					if(par[en[id]] != -1) continue;
					par[en[id]] = id;
					bfs.push_back(en[id]);
				}
			}
			if(par[t] == -1) break;
			LL send = 4e18;
			int curv = t;
			while(par[curv] != -2){
				send = min(send, c[par[curv]]);
				curv = st[par[curv]];
			}
			curv = t;
			while(par[curv] != -2){
				add(par[curv], send);
				curv = st[par[curv]];
			}
			ans += send;
		}
		return ans;
	}
};


int ok[110][110];
int r[110][110];
int fataleagle[110][110];
int main(){
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	s--; t--;
	vector<int> u, v, g;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ok[i][j] = 1e7;
			r[i][j] = 0;
			fataleagle[i][j] = -1;
		}
		ok[i][i] = 0;
	}
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		u.push_back(a);
		v.push_back(b);
		g.push_back(c);
		if(c) ok[a][b] = 1;
	}
	for(int a = 0; a < n; a++){
		fataleagle[a][a] = a;
		for(int i = 0; i < n; i++){
			for(int fuckthisproblem = 0; fuckthisproblem < m; fuckthisproblem++){
				if(g[fuckthisproblem] == 0) continue;
				int derpy1 = u[fuckthisproblem];
				int derpy2 = v[fuckthisproblem];
				if(ok[derpy1][derpy2] == 1 && fataleagle[a][derpy1] >= 0 && fataleagle[a][derpy2] == -1){
					fataleagle[a][derpy2] = derpy1;
				}
			}
		}
	}

	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				ok[i][j] = min(ok[i][j], ok[i][k] + ok[k][j]);
			}
		}
	}


	Flow codeforces(n);
	for(int i = 0; i < m; i++){
		if(g[i] == 1){
			codeforces.add_edge(u[i], v[i], 1);
			codeforces.add_edge(v[i], u[i], 1e8);
		} else {
			codeforces.add_edge(u[i], v[i], 1e8);
		}
	}
	LL ans = codeforces.maxflow(s,t);

	cout << ans << endl;

	Flow f2(n);

	for(int i = 0; i < m; i++){
		if(g[i] == 0){
		} else {
			if(codeforces.par[u[i]] != -1 && codeforces.par[v[i]] == -1){
				f2.add_edge(u[i], v[i], 1);
			} else {
				f2.add_edge(u[i], v[i], 1e8);
			}
		}
	}

	f2.maxflow(s,t);	



	for(int i = 0; i < f2.graph.size(); i++){
		for(int j = 0; j < f2.graph[i].size(); j++){
			int id = f2.graph[i][j];
			if(f2.f[id] + f2.c[id] == 0) continue;
			r[f2.st[id]][f2.en[id]] += f2.f[id];
		}
	}


	for(int i = 0; i < m; i++){
		if(g[i] == 0) continue;
		int a = u[i];
		int b = v[i];
		if(r[a][b] > 0) continue;
		r[a][b]++;
		if(fataleagle[s][a] >= 0 && fataleagle[b][t] >= 0){
			if(1){
				int yy = s;
				int zz = a;
				while(zz != yy){
					int nzz = fataleagle[yy][zz];
					r[nzz][zz]++;
					zz = nzz;
				}
			}
			if(1){
				int yy = b;
				int zz = t;
				while(zz != yy){
					int nzz = fataleagle[yy][zz];
					r[nzz][zz]++;
					zz = nzz;
				}
			}

		} else {
			if(1){
				int yy = b;
				int zz = a;
				while(zz != yy){
					int nzz = fataleagle[yy][zz];
					r[nzz][zz]++;
					zz = nzz;
				}
			}
		}
	}


	for(int i = 0; i < m; i++){
		if(g[i] == 0){
			cout << 0 << " " << 1 << endl;
		} else {
			if(codeforces.par[u[i]] != -1 && codeforces.par[v[i]] == -1){
				cout << r[u[i]][v[i]] << " " << r[u[i]][v[i]] << endl;
			} else {
				cout << r[u[i]][v[i]] << " " << r[u[i]][v[i]] + 1 << endl;
			}
		}
	}
}