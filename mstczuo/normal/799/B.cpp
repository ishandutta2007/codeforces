# include <bits/stdc++.h>

using namespace std;

int n, m;

int p[200010];

priority_queue< pair<int,int> > c[3];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &p[i]);
		p[i] = -p[i];
	}
	for(int i = 1; i <= n; ++i) {
		int x; scanf("%d", &x);
		c[x].push({p[i], i});
	}
	for(int i = 1; i <= n; ++i) {
		int x; scanf("%d", &x);
		c[x].push({p[i], i});
	}
	scanf("%d", &m);
	for(int i = 1; i <= m; ++i) {
		int x; scanf("%d", &x);
		int price, id = -1;
		while(!c[x].empty()) {
			tie(price, id) = c[x].top();
			c[x].pop();
			if (p[id] == 0) continue;
			else break;
		}
		if(id == -1 || p[id] == 0) {
			printf("%d ", -1);
		} else {
			printf("%d ", -price);
			p[id] = 0;
		}
	}
	return 0;
}