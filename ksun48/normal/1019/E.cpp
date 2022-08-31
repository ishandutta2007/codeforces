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

bool Q;
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const {
		return Q ? p < o.p : k < o.k;
	}
};

struct LineContainer : multiset<Line> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		Q = 1; auto l = *lower_bound({0,0,x}); Q = 0;
		return l.k * x + l.m;
	}
};

vector<int> edges[110000];
vector<LL> A[110000];
vector<LL> B[110000];
int sz[110000];
int vis[110000];
int cent = -1;

int dfs(int v, int p){
	if(vis[v]) return 0;
	sz[v] = 1;
	for(int a : edges[v]){
		if(a != p) sz[v] += dfs(a, v);
	}
	return sz[v];
}

void find_c(int v, int p, int tsz){
	if(vis[v]) return;
	if(sz[v] >= tsz/2){
		cent = v;
	}
	for(int a : edges[v]){
		if(a != p) find_c(a, v, tsz);
	}
}

int get_c(int v){
	cent = -1;
	int tsz = dfs(v, -1);
	find_c(v, -1, tsz);
	return cent;
}

void dfs_line(int v, int p, LL asum, LL bsum, LineContainer &lc){
	if(vis[v]) return;
	lc.add(asum, bsum);
	for(int i = 0; i < edges[v].size(); i++){
		int a = edges[v][i];
		if(a != p) dfs_line(a, v, asum + A[v][i], bsum + B[v][i], lc);
	}
}

LineContainer ans;
vector<pair<LL,LL> > candidates;

void pr(const LineContainer &lc){	
	for(Line r : lc){
		cout << r.k << "x + " << r.m << " ";
	}
}
void add_sum(const LineContainer &a, const LineContainer &b){
	/*pr(a);
	cout << " plus ";
	pr(b);
	cout<< endl;*/
	// do something
	vector<pair<LL,LL> > linea;
	vector<pair<LL,LL> > lineb;
	for(Line x : a){
		if(linea.size() > 0 && linea[linea.size()-1].first == x.k){
			linea[linea.size()-1].second = max(linea[linea.size()-1].second, x.m);
			continue;
		}
		linea.push_back({x.k, x.m});
	}
	for(Line x : b){
		if(lineb.size() > 0 && lineb[lineb.size()-1].first == x.k){
			lineb[lineb.size()-1].second = max(lineb[lineb.size()-1].second, x.m);
			continue;
		}
		lineb.push_back({x.k, x.m});
	}
	/*for(auto r : linea){
		cout << r.first << "x + " << r.second << " ";
	}
	cout << " plus ";
	for(auto r : lineb){
		cout << r.first << "x + " << r.second << " ";
	}
	cout << endl;*/
	int i = 0;
	int j = 0;
	while(i < linea.size() && j < lineb.size()){
		candidates.push_back({linea[i].first + lineb[j].first, linea[i].second + lineb[j].second});
		if(i + 1 == linea.size()){
			j++;
		} else if(j + 1 == lineb.size()){
			i++;
		} else {
			double x1 = -(double)(linea[i+1].second - linea[i].second) / (double)(linea[i+1].first - linea[i].first);
			double x2 = -(double)(lineb[j+1].second - lineb[j].second) / (double)(lineb[j+1].first - lineb[j].first);
			if(x1 < x2){
				i++;
			} else {
				j++;
			}
		}
	}
}

LineContainer dnc(int s, int e, vector<LineContainer> &lcs){
	if(s < e){
		int m = (s + e) / 2;
		LineContainer l1 = dnc(s, m, lcs);
		LineContainer l2 = dnc(m+1, e, lcs);
		add_sum(l1, l2);
		// merge l1 and l2 into same one
		for(Line r : l1){
			l2.add(r.k, r.m);
		}
		return l2;
	} else {
		LineContainer l0;
		l0.add(0,0);
		add_sum(l0, lcs[s]);
		return lcs[s];
	}
}


void solve(int v){
	int centroid = get_c(v);
	vector<LineContainer> s;
	for(int i = 0; i < edges[centroid].size(); i++){
		int a = edges[centroid][i];
		if(vis[a]) continue;
		LineContainer lc;
		lc.add(0,0);
		dfs_line(a, centroid, A[centroid][i], B[centroid][i], lc);
		s.push_back(lc);
	}
	if(s.size() > 0){
		dnc(0, (int)(s.size())-1, s);
	}

	vis[centroid] = 1;
	for(int a : edges[centroid]){
		if(vis[a]) continue;
		solve(a);
	}
}
void test(){
	LineContainer lc;
	pr(lc); cout << endl;
	lc.add(0,0);
	pr(lc); cout << endl;
	lc.add(0,10);
	pr(lc); cout << endl;
	lc.add(0,5);
	pr(lc); cout << endl;
	lc.add(1,5);
	pr(lc); cout << endl;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	//test();
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n-1; i++){
		int u, v, a, b;
		cin >> u >> v >> a >> b;
		u--; v--;
		edges[u].push_back(v);
		A[u].push_back(a);
		B[u].push_back(b);

		edges[v].push_back(u);
		A[v].push_back(a);
		B[v].push_back(b);
	}
	solve(0);
	ans.add(0,0);
	sort(candidates.begin(), candidates.end());
	for(auto r : candidates){
		ans.add(r.first, r.second);
	}
	for(int i = 0; i < m; i++){
		cout << ans.query(i) << " ";
	}
	cout << '\n';
}