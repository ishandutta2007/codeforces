#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct pt {
	long long x, y; int i;
	bool operator <(const pt &t) const {
		if (y * t.x == t.y * x) {
			return x * x + y * y > t.x * t.x + t.y * t.y;
		}
		return y * t.x < t.y * x;
	}
};

bool cmp(const pt &a, const pt &b){
	return a.y * b.x < b.y * a.x;
}

bool cmp2(const pt &a, const pt &b) {
	if (a.y * b.x == b.y * a.x) {
		return a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y;
	}
	return a.y * b.x < b.y * a.x;
}

int N, W, X[100100],Y[100100],B[100100];

int main()
{
	scanf("%d %d", &N, &W);
	for (int i = 0; i < N; i++) scanf("%d %d", &X[i], &Y[i]);

	long long ans = 0;
	for (int k = 0; k < 2; k++) {
		vector<pt> a,b,c;
		if (k == 0) {
			for (int i = 0; i < N; i++) if (X[i] > 0) a.push_back({ X[i],Y[i],0 });
		}
		else {
			for (int i = 0; i < N; i++) if (X[i] < 0) a.push_back({ -X[i],-Y[i],0 });
		}
		if (a.empty()) continue;

		for (int i=0;i<a.size();i++){
			auto &p = a[i];
			b.push_back({ p.x,p.y + W,i });
			c.push_back({ p.x,p.y - W,i });
		}
		sort(b.begin(), b.end());
		sort(c.begin(), c.end(), cmp2);

		vector<int > u(a.size());
		vector<int > x(a.size());
		vector<int > y(a.size());
		for (int i = 0; i < a.size(); i++) x[b[i].i] = i, y[c[i].i] = i;
		for (int i = 0; i < a.size(); i++) u[x[i]] = y[i];

		for (int i = 1; i <= a.size(); i++) B[i] = 0;
		for (int i = a.size() - 1; i >= 0; i--) {
			for (int x = u[i] + 1; x; x -= x&(-x)) ans += B[x];
			for (int x = u[i] + 1; x <= a.size(); x += x&(-x)) B[x]++;
		}
	}

	vector<pt> a, b, c;
	for (int i = 0; i < N; i++) {
		if (X[i] > 0) a.push_back({ -X[i],-Y[i],0 });
		else {
			b.push_back({ X[i],Y[i] - W,0 });
			c.push_back({ X[i],Y[i] + W,0 });
		}
	}
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	for (auto &p : a) {
		auto q = p; q.y -= W;
		auto r = p; r.y += W;
		int U = upper_bound(c.begin(), c.end(), q, cmp) - c.begin();
		int L = lower_bound(b.begin(), b.end(), r, cmp) - b.begin();
		ans += U - L;
	}

	printf("%lld\n", ans);

	return 0;
}