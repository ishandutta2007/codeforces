# include <cstdio>
# include <cstring>
# include <utility>
# include <vector>

using namespace std;

const int P[] = {2, 4, 8, 16, 32, 3, 9, 27, 5, 25, 7, 11, 13, 17, 19, 23, 29, 31, 37, 39};
const int pn = 20;

int a[pn], b[pn];

void init() {
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
}

const int maxn = 100010;

vector< pair<int, int> > c[maxn];
typedef pair<int, int> pii;
int cnt[maxn];

bool valid(int k, int cur) {
	int n = cnt[c[cur][k].first];
	int v = c[cur][k].second;
	for(int i = 0; i < pn; ++i) {
		if(n % P[i] == 0) {
			if(b[i] && a[i] != v % P[i]) {
				return false;
			}
		}
	}
	return true;
}

void add(int k,int cur,int val) {
	int n = cnt[c[cur][k].first];
	int v = c[cur][k].second;
	for(int i = 0; i < pn; ++i) if(n % P[i] == 0) {
		a[i] = v % P[i];
		b[i] += val;
	}
}

int n, m;
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		int sz; scanf("%d", &sz);
		cnt[i] = sz;
		for(int j = 1; j <= sz; ++j) {
			int x; scanf("%d", &x);
			c[x].push_back(pii(i, j));
		}
	}
	for(int i = 1; i <= m; ++i) {
		init();
		int sz = c[i].size(), ans = 0;
		for(int j = 0, k = 0; j < sz; ++j) {
			if(j > 0 && c[i][j].first - c[i][j - 1].first > 1) {
				init();
				k = j;
			}
			while(!valid(j, i)) add(k++, i, -1);
			add(j, i, 1);
			ans = max(ans, j - k + 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}