#include<bits/stdc++.h>
using namespace std;

const int N = 10000 + 100;

struct tree {
	int l, r;
	vector <int> g;
}p[N << 2];

bitset <N> f[32], ans;
vector <int> Ans;

int n, m;

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r;
	if(l == r) return;
	int mid = (l + r) >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}
void change(int u, int l, int r, int x) {
	if(p[u].l >= l && p[u].r <= r) {
		p[u].g.push_back(x);
		return;
	}
	int mid = (p[u].l + p[u].r) >> 1;
	if(mid >= l) change(u << 1, l, r, x);
	if(mid + 1 <= r) change(u << 1 | 1, l, r, x);
}
int t = 0;
void query(int u) {
	f[t + 1] = f[t], t++;
	for(int i = 0; i < p[u].g.size(); i++) {
		f[t] |= f[t] << p[u].g[i];
		//printf("p[%d].g[%d] = %d\n", u, i, p[u].g[i]);
	}
	if(p[u].l == p[u].r) {
		ans |= f[t];
		t--;
		return;
	}
	int mid = (p[u].l + p[u].r) >> 1;
	query(u << 1), query(u << 1 | 1); 
	t--;
}

int main() {
	scanf("%d %d", &n, &m);
	f[0][0] = 1;
	build(1, 1, n);
	for(int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		change(1, a, b, c);
	}
	query(1);
	for(int i = 1; i <= n; i++) {
		if(ans[i] == 1) {
			Ans.push_back(i);
		}
	}
	printf("%d\n", Ans.size());
	for(int i = 0; i < Ans.size(); i++) printf("%d ", Ans[i]);
	return 0;
}