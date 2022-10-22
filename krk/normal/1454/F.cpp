#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
map <int, ii> L, R;
int lef[Maxn], rig[Maxn];

bool Intersect(int lef1, int rig1, int lef2, int rig2)
{
	return max(lef1, lef2) <= min(rig1, rig2);
}

void Solve()
{
	for (int i = 0; i < n; i++) {
		auto it = L.find(a[i]);
		int rlef, rrig;
		if (it == L.end() || !Intersect(it->second.first, it->second.second, lef[i], i)) continue;
		rlef = max(it->second.first, lef[i]);
		it = R.find(a[i]);
		if (it == R.end() || !Intersect(it->second.first, it->second.second, i, rig[i])) continue;
		rrig = max(it->second.first, i);
		printf("YES\n");
		printf("%d %d %d\n", rlef, rrig - rlef + 1, n - 1 - rrig);
		return;
	}
	printf("NO\n");
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		L.clear(); R.clear();
		int mx = 0;
		for (int i = 0; i < n; i++) {
			mx = max(mx, a[i]);
			auto it = L.find(mx);
			if (it == L.end()) L.insert(make_pair(mx, ii(i + 1, i + 1)));
			else it->second.second = i + 1;
		}
		mx = 0;
		for (int i = n - 1; i >= 0; i--) {
			mx = max(mx, a[i]);
			auto it = R.find(mx);
			if (it == R.end()) R.insert(make_pair(mx, ii(i - 1, i - 1)));
			else it->second.first = i - 1;
		}
		for (int i = 0; i < n; i++) {
			lef[i] = i;
			while (lef[i] > 0 && a[lef[i] - 1] >= a[i])
				lef[i] = lef[lef[i] - 1];
		}
		for (int i = n - 1; i >= 0; i--) {
			rig[i] = i;
			while (rig[i] + 1 < n && a[rig[i] + 1] >= a[i])
				rig[i] = rig[rig[i] + 1];
		}
		Solve();
	}
    return 0;
}