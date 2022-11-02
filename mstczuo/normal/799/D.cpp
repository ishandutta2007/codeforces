# include <bits/stdc++.h>

using namespace std;

int a, b, h, w, n;

int c[100010];

const int C = 100010;

int main() {
	scanf("%d%d%d%d%d", &a, &b, &h, &w, &n);

	for(int i = 0; i < n; ++i) scanf("%d", &c[i]);

	if (max(h, w) >= max(a, b) && min(h, w) >= min(a, b)) { puts("0"); return 0; }

	sort(c, c + n, greater<int>());

	queue< pair<int, int> > q;
	q.push({h, w});

	int cnt = 0;
	bool flag = false;
	for(int i = 0; i < n; ++i) {
		++cnt;
		set< pair<int,int> > s;
		int sz = q.size();
		while(sz--) {
			tie(h, w) = q.front(), q.pop();
			if (h < C) {
				int x = min(1ll * C, 1ll * h * c[i]), y = w;
				if (max(x, y) >= max(a, b) && min(x, y) >= min(a, b)) flag = true;
				if(!s.count({x,y})) {
					s.insert({x,y});
					q.push({x,y});
				}
			}
			if (w < C) {
				int x = h, y = min(1ll * C, 1ll * w * c[i]);
				if (max(x, y) >= max(a, b) && min(x, y) >= min(a, b)) flag = true;
				if(!s.count({x,y})) {
					s.insert({x,y});
					q.push({x,y});
				}
			}
		}
		if(flag) break;
	}

	if(flag) {
		printf("%d\n", cnt);
	} else {
		printf("%d\n", -1);
	}

	return 0;
}