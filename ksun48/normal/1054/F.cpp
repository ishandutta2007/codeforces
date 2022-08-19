#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi match;
vector<bool> seen;
bool find(int j, const vector<vi>& g) {
	if (match[j] == -1) return 1;
	seen[j] = 1; int di = match[j];
	trav(e, g[di])
		if (!seen[e] && find(e, g)) {
			match[e] = di;
			return 1;
		}
	return 0;
}
int dfs_matching(const vector<vi>& g, int n, int m) {
	match.assign(m, -1);
	rep(i,0,n) {
		seen.assign(m, 0);
		trav(j,g[i])
			if (find(j, g)) {
				match[j] = i;
				break;
			}
	}
	return m - (int)count(all(match), -1);
}

vi cover(vector<vi>& g, int n, int m) {
	int res = dfs_matching(g, n, m);
	seen.assign(m, false);
	vector<bool> lfound(n, true);
	trav(it, match) if (it != -1) lfound[it] = false;
	vi q, cover;
	rep(i,0,n) if (lfound[i]) q.push_back(i);
	while (!q.empty()) {
		int i = q.back(); q.pop_back();
		lfound[i] = 1;
		trav(e, g[i]) if (!seen[e] && match[e] != -1) {
			seen[e] = true;
			q.push_back(match[e]);
		}
	}
	rep(i,0,n) if (!lfound[i]) cover.push_back(i);
	rep(i,0,m) if (seen[i]) cover.push_back(n+i);
	assert(sz(cover) == res);
	return cover;
}

struct step {
	int a, b, c, d;
	step (int a, int b, int c, int d): a(a), b(b), c(c), d(d){}
};


int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int,int> > pts(n);
	set<int> xr;
	set<int> yr;
	for(int i = 0; i < n; i++){
		cin >> pts[i].first >> pts[i].second;
		xr.insert(pts[i].first);
		yr.insert(pts[i].second);
	}
	map<int,int> xz;
	map<int,int> xinvz;
	for(int a : xr){
		int k = xz.size();
		xz[a] = k;
		xinvz[k] = a;
	}
	map<int,int> yz;
	map<int,int> yinvz;
	for(int a : yr){
		int k = yz.size();
		yz[a] = k;
		yinvz[k] = a;
	}

	int nrows = xr.size();
	int ncols = yr.size();

	vector<vector<int> > rownum(nrows, vector<int>(ncols, -1));
	vector<vector<int> > colnum(nrows, vector<int>(ncols, -1));

	vector<vector<int> > rows(nrows);
	vector<vector<int> > cols(ncols);

	for(int i = 0; i < n; i++){
		pts[i].first = xz[pts[i].first];
		pts[i].second = yz[pts[i].second];
		rows[pts[i].first].push_back(pts[i].second);
		cols[pts[i].second].push_back(pts[i].first);
	}
	vector<step> rsegs;
	for(int i = 0; i < nrows; i++){
		sort(rows[i].begin(), rows[i].end());
		for(int a = 0; a + 1 < rows[i].size(); a++){
			int id = rsegs.size();
			rsegs.push_back(step(i, rows[i][a], i, rows[i][a+1]));
			for(int b = rows[i][a] + 1; b <= rows[i][a+1] - 1; b++){
				rownum[i][b] = id;
			}
		}
	}

	vector<step> csegs;
	for(int i = 0; i < ncols; i++){
		sort(cols[i].begin(), cols[i].end());
		for(int a = 0; a + 1 < cols[i].size(); a++){
			int id = csegs.size();
			csegs.push_back(step(cols[i][a], i, cols[i][a+1], i));
			for(int b = cols[i][a] + 1; b <= cols[i][a+1] - 1; b++){
				colnum[b][i] = id;
			}
		}
	}

	vector<vector<int> > graph(rsegs.size());
	for(int i = 0; i < nrows; i++){
		for(int j = 0; j < ncols; j++){
			if(rownum[i][j] == -1) continue;
			if(colnum[i][j] == -1) continue;
			graph[rownum[i][j]].push_back(colnum[i][j]);
		}
	}
	vector<int> vc = cover(graph, rsegs.size(), csegs.size());
	vector<int> used(rsegs.size() + csegs.size(), 0);
	for(int a : vc){
		used[a] = 1;
	}
	set<pair<pair<int,int>, pair<int,int> > > rmerge, cmerge;
	for(int a = 0; a < rsegs.size(); a++){
		if(used[a] == 0){
			step x = rsegs[a];
			rmerge.insert({{x.a, x.b}, {x.c, x.d}});
		}
	}
	for(int a = 0; a < csegs.size(); a++){
		if(used[rsegs.size() + a] == 0){
			step x = csegs[a];
			cmerge.insert({{x.a, x.b}, {x.c, x.d}});
		}
	}
	vector<step> rowans;
	vector<step> colans;

	for(int i = 0; i < nrows; i++){
		int b = 0;
		while(b < rows[i].size()){
			int c = b;
			while(c + 1 < rows[i].size() && rmerge.find({{i, rows[i][c]}, {i, rows[i][c+1]}}) != rmerge.end()){
				c++;
			}
			rowans.push_back(step(i, rows[i][b], i, rows[i][c]));
			b = c + 1;
		}
	}
	for(int i = 0; i < ncols; i++){
		int b = 0;
		while(b < cols[i].size()){
			int c = b;
			while(c + 1 < cols[i].size() && cmerge.find({{cols[i][c], i}, {cols[i][c+1], i}}) != cmerge.end()){
				c++;
			}
			colans.push_back(step(cols[i][b], i, cols[i][c], i));
			b = c + 1;
		}
	}
	cout << colans.size() << endl;
	for(int a = 0; a < colans.size(); a++){
		step x = colans[a];
		cout << xinvz[x.a] << " " << yinvz[x.b] << " " << xinvz[x.c] << " " << yinvz[x.d] << '\n';
	}
	cout << rowans.size() << '\n';
	for(int a = 0; a < rowans.size(); a++){
		step x = rowans[a];
		cout << xinvz[x.a] << " " << yinvz[x.b] << " " << xinvz[x.c] << " " << yinvz[x.d] << '\n';
	}
}