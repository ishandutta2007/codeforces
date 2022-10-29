#include <bits/stdc++.h>
using namespace std;

int tc, n, q;
vector<int> a;
vector<pair<int, int> > b;
vector<int> st;
vector<int> flag;
char s1[200050], s2[200050];


void update(int p, int l, int r, int x, int y, int v) {
	//printf("%d\n", p);
	if (l == r && l >= x && l <= y) {
		flag[p] = -1;
		st[p] = v;
	}
	else if (r < x || l > y) return;
	else if (x <= l && r <= y) {
		flag[p] = v;
		st[p] = v*(r-l+1);
	}
	else {
		int m = (l+r)/2;
		if (flag[p] != -1) {
			flag[2*p] = flag[p];
			st[2*p] = flag[p] * (m - l + 1);
			flag[2*p+1] = flag[p];
			st[2*p+1] = flag[p] * (r - m);
			flag[p] = -1;
		}
		update(2*p, l, m, x, y, v);
		update(2*p+1, m+1, r, x, y, v);
		st[p] = st[2*p] + st[2*p+1];// + flag[2*p]*(m - l + 1) + flag[2*p+1]*(m - l + 1);
	}
}

int query(int p, int l, int r, int x, int y) {
	//printf("%d\n", p);
	if (x <= l && r <= y) {
		return st[p];
	}
	else if (r < x || l > y) return 0;
	else {
		int m = (l+r)/2;
		if (flag[p] != -1) {
			flag[2*p] = flag[p];
			st[2*p] = flag[p] * (m - l + 1);
			flag[2*p+1] = flag[p];
			st[2*p+1] = flag[p] * (r - m);
			flag[p] = -1;
		}
		return query(2*p, l, m, x, y) + query(2*p+1, m+1, r, x, y);
	}
}

void build(int p, int l, int r) {
	if (l == r) {
		st[p] = a[l];
	}
	else {
		int m = (l+r)/2;
		build(2*p, l, m);
		build(2*p+1, m+1, r);
		st[p] = st[2*p] + st[2*p+1];
	}
}

void init() {
	st.resize(4*n+5, 0);
	flag.resize(4*n+5, -1);
	
	build(1, 0, n-1);
}

int main() {
	scanf("%d", &tc);
	while (tc--) {
		a.clear(); b.clear(); st.clear(); flag.clear();
		scanf("%d %d", &n, &q);
		scanf("%s", s1);
		scanf("%s", s2);
		int i1, i2;
		for (int i = 0; i < n; i++) {
			a.push_back(s2[i] - '0');
		}
		init();
		for (int i = 0; i < q; i++) {
			scanf("%d %d", &i1, &i2);
			b.push_back(make_pair(i1-1, i2-1));
		}
		reverse(b.begin(), b.end());
		bool valid = true;
		for (int i = 0; i < q; i++) {
			int val = query(1, 0, n-1, b[i].first, b[i].second);
			int sz = b[i].second - b[i].first + 1;
			//printf("%d %d\n", val, sz);
			if (val > sz / 2) {
				update(1, 0, n-1, b[i].first, b[i].second, 1);
			}
			else if (val < (sz + 1) / 2) {
				update(1, 0, n-1, b[i].first, b[i].second, 0);
			}
			else {
				valid = false;
				break;
			}
		}
		if (valid)
		for (int i = 0; i < n; i++) {
			//printf("%d ", query(1, 0, n-1, i, i));
			if (query(1, 0, n-1, i, i) != s1[i] - '0') {
				valid = false; 
				break;
			}
		}
		if (valid) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}