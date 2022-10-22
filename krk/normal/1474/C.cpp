#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 2005;

int T;
int n;
int a[Maxn];
multiset <int> S;
vector <ii> seq;

bool Solve(int a, int b)
{
	multiset <int> cur = S;
	cur.erase(cur.find(a));
	cur.erase(cur.find(b));
	int nd = b;
	while (!cur.empty()) {
		int en = *cur.rbegin(); cur.erase(cur.find(en));
		int oth = nd - en;
		if (cur.find(oth) == cur.end()) return false;
		seq.push_back(ii(oth, en));
		cur.erase(cur.find(oth));
		nd = en;
	}
	return true;
}

void Solve()
{
	if (n % 2 != 0) { printf("NO\n"); return; }
	for (int i = 0; i + 1 < n; i++) {
		seq.clear();
		seq.push_back(ii(a[i], a[n - 1]));
		if (Solve(a[i], a[n - 1])) {
			printf("YES\n");
			printf("%d\n", a[i] + a[n - 1]);
			for (int i = 0; i < seq.size(); i++)
				printf("%d %d\n", seq[i].first, seq[i].second);
			return;
		}
	}
	printf("NO\n");
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n); n *= 2;
		S.clear();
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			S.insert(a[i]);
		}
		sort(a, a + n);
		Solve();
	}
    return 0;
}