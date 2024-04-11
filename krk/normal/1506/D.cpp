#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

int T;
int n;
map <int, int> M;

int Solve()
{
	priority_queue <ii> Q;
	for (auto it: M)
		Q.push(ii(it.second, it.first));
	while (!Q.empty()) {
		ii v = Q.top(); Q.pop();
		if (Q.empty()) return v.first;
		ii u = Q.top(); Q.pop();
		if (v.first > 1) Q.push(ii(v.first - 1, v.second));
		if (u.first > 1) Q.push(ii(u.first - 1, u.second));
	}
	return 0;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		M.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			M[a]++;
		}
		printf("%d\n", Solve());
	}
    return 0;
}