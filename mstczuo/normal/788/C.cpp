# include <cstdio>
# include <cstring>
# include <algorithm>
# include <vector>
# include <bitset>
using namespace std;

int v[1200];
int n, m;

vector<int> b;

int calc() {
	bitset<1000001> s;
	bitset<1000001> g;
	s.set(0);
	int step = 1;
	while(step <= 1000) {
		for(auto v: b) g |= s << v;
		if(g.test(n * step)) return step;
		s = g;
		g.reset();
		step += 1;
	}
	return -1;
}

int main() {
	scanf("%d%d", &n, &m);
	int mx = -1;
	int mi = 1001;
	for(int i = 0; i < m; ++i) {
		int x; scanf("%d", &x);
		v[x] = true;
		mx = max(mx, x);
		mi = min(mi, x);
	}
	if(mx < n || mi > n) {
		puts("-1");
		return 0;
	}
	for(int i = 0; i <= 1000; ++i)
		if(v[i]) b.push_back(i - mi);
	n -= mi;
	printf("%d\n", calc());
	return 0;
}