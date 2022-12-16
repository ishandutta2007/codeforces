#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
using namespace std;

const int maxn = 1e6 + 10;
int T,n,m,a[maxn],ans;

struct vec {
	int v[maxn],len;
	void push_back(int val) { v[++len] = val; }
	int back() { return v[len]; }
	void pop_back() { --len; }
	void clear() { len = 0; }
	bool empty() { return len == 0; }
}ed[2],v,ne;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				scanf("%1d", &a[(i - 1) * m + j - 1]);
		ed[0].clear();
		ed[1].clear();
		ans = 0;
		for(int s = 2; s <= n + m; ++s) {
			v.clear();
			for(int i = max(1, s - m); i <= min(n, s - 1); ++i) {
				int j = s - i;
				if(a[(i - 1) * m + j - 1]) v.push_back(i - j);
			}
			if(v.empty()) continue;
			ne.clear();
			for(int p = 1; p <= ed[s & 1].len; ++p) {
				int lt = ed[s & 1].v[p];
				if(v.empty() || v.back() < lt) { ne.push_back(lt); continue; }
				ne.push_back(v.back());
				while(!v.empty() && v.back() >= lt) v.pop_back();
			}
			if(!v.empty()) ans++, ne.push_back(v.back());
			ed[s & 1].clear();
			for(int i = 1; i <= ne.len; ++i) {
				int x = ne.v[i];
				if((x + s) / 2 >= n) continue;
				ed[s & 1].push_back(x);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}