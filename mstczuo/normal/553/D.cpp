# include <iostream>
# include <cstdio>
# include <vector>
# include <cmath>
# include <set>
using namespace std;

const int maxn = 100010;

struct Double {
    double val;
    Double(){}
    Double(double v):val(v){}
    bool operator<(const Double&e) const{
        if(fabs(val - e.val) < 1e-9) return 0;
        return val < e.val;
        //return val < e.val;
    }
};

int c[maxn], d[maxn];
vector<int> g[maxn];
multiset< pair<Double,int> > e;
int v[maxn];

set<int> nodes;
vector<int> vec;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int x, y, cnt = 0;
	for(int i = 0; i < k; ++i) {
		scanf("%d", &x);
		v[x] = 1;
	}
	for(int i = 0; i < m; ++i) {
		scanf("%d%d", &x, &y);
		if(!v[x] && !v[y]) {
			g[x].push_back(y);
			g[y].push_back(x);
		}
		c[x]++, d[x]++, c[y]++, d[y]++;
		if(!v[x] && v[y]) --c[x];
		if(v[x] && !v[y]) --c[y];
	}
	for(int i = 1; i <= n; ++i) if(!v[i]){
		if(d[i] == 0) while(1);
		//cout << c[i] << ' ' << d[i] << ' ' << i << endl;
		e.insert(pair<Double,int>(c[i]*1./d[i],i));
		nodes.insert(i); ++cnt;
	}
	Double ans = 0; 
	int ans_k = 0, cur;
	vec.resize(cnt);
	for(int i = 0; i < cnt; ++i) {
		vec[i] = cur = e.begin()->second;
		//cout << cur << ' ' << e.begin()->first << endl;
		if(ans < e.begin()->first) {
			ans = e.begin()->first; 
			ans_k = i;
		}
		v[cur] = 1; e.erase(e.begin());
		//cout << "v = " << cur << endl;
		for(size_t k = 0; k < g[cur].size(); ++k) {
			int u = g[cur][k];
			//cout << "  u = " << u << endl;
			if (v[u]) continue;
			e.erase(e.find(pair<Double,int>(c[u]*1./d[u],u)));
			c[u] -= 1;
			e.insert(pair<Double,int>(c[u]*1./d[u],u));
		}
	}
	for(int i = 0; i < ans_k; ++i) {
		nodes.erase(vec[i]);
	}
	printf("%d\n", (int)nodes.size());
	for(set<int>::iterator i=nodes.begin(); i!=nodes.end(); ++i) {
		printf("%d ", *i);
	}
	puts("");
}