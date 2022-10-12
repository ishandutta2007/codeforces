#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;

#define i64 long long int
#define ran 111111
vector<i64> A,B;

int MCP(vector<i64> s) {
	int n = s.size();
	int i, j, x, y, u, v;
	for (x = 0, y = 1;y<n;y++)if (s[y] <= s[x]) {
		i = u = x;j = v = y;
		while (s[i] == s[j]) {
			++u;if (++i == n)i = 0;++v;
			if (++j == n)j = 0;if (i == x)break;
		}
		if (s[i] <= s[j])y = v;else { x = y;if (u>y)y = u; }
	}
	return x;
}

i64 ax[ran], ay[ran];
i64 cross(i64 ax, i64 ay, i64 bx, i64 by, i64 cx, i64 cy) {
	return (ax - cx)*(by - cy) - (ay - cy)*(bx - cx);
}
i64 sqr(i64 x) { return x * x; }
int s[ran], top;
void convex(int n,vector<i64>&res) {
	vector<pair<i64, i64> > A;
	top = 0;
	s[top++] = 0;
	for (int i = 1; i<n; i++) {
		while (top>1 && cross(ax[i], ay[i], ax[s[top - 1]], ay[s[top - 1]], ax[s[top - 2]], ay[s[top - 2]]) >= 0)
			top--;
		s[top++] = i;
	}
	for (int i = 0; i < top - 1; i++) {
		A.push_back(make_pair(ax[s[i]], ay[s[i]]));
	}
	top = 0;
	s[top++] = n - 1;
	for (int i = n - 2; i >= 0; i--) {
		while (top>1 && cross(ax[i], ay[i], ax[s[top - 1]], ay[s[top - 1]], ax[s[top - 2]], ay[s[top - 2]]) >= 0)
			top--;
		s[top++] = i;
	}
	for (int i = 0; i < top - 1; i++) {
		A.push_back(make_pair(ax[s[i]], ay[s[i]]));
	}

	n = A.size();
	res.clear();
	for (int i = 0; i < n; i++) {
		res.push_back(sqr(A[i].first - A[(i + 1) % n].first) + sqr(A[i].second - A[(i + 1) % n].second));
		res.push_back(
			(A[(i + 1) % n].first - A[i].first) * (A[(i + 2) % n].second - A[i].second) -
			(A[(i + 1) % n].second - A[i].second) * (A[(i + 2) % n].first - A[i].first)
		);
	}
	int id = MCP(res);
	vector<i64> res2;
	for (int i = id; i < res.size(); i++)res2.push_back(res[i]);
	for (int i = 0; i < id; i++)res2.push_back(res[i]);
	res = res2;
}

int n, m;
pair<i64, i64> w[ran];
int main() {
	scanf("%d%d", &n,&m);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		w[i] = make_pair((i64)x, (i64)y);
	}
	sort(w, w + n);
	for (int i = 0; i < n; i++) {
		ax[i] = w[i].first;
		ay[i] = w[i].second;
	}
	convex(n, A);

	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		w[i] = make_pair((i64)x, (i64)y);
	}
	sort(w, w + m);
	for (int i = 0; i < m; i++) {
		ax[i] = w[i].first;
		ay[i] = w[i].second;
	}
	convex(m, B);
	puts(A == B ? "YES" : "NO");
	return 0;
}