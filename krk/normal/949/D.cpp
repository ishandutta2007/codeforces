#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;
typedef long long ll;

const int Maxn = 100005;

int n, d, b;
int a[Maxn];
vector <iii> seq;

bool Left(int x) { return x < (n + 1) / 2; }

int getLeft(int x)
{
	int lef = 0, rig = x - 1;
	while (lef <= rig) {
		int mid = lef + rig >> 1;
		if (!Left(mid) || x - mid <= ll(d) * (mid + 1)) rig = mid - 1;
		else lef = mid + 1;
	}
	return rig + 1;
}

int getRight(int x)
{
	int lef = x + 1, rig = n - 1;
	while (lef <= rig) {
		int mid = lef + rig >> 1;
		if (Left(mid) || mid - x <= ll(d) * (n - mid)) lef = mid + 1;
		else rig = mid - 1;
	}
	return lef - 1;
}

bool Check(int x)
{
	int lef = x, rig = n - 1 - x;
	priority_queue <ii> Q;
	int pnt = 0;
	for (int i = lef; i <= rig; i++) {
		while (pnt < seq.size() && seq[pnt].first.first <= i) {
			Q.push(ii(-seq[pnt].first.second, seq[pnt].second));
			pnt++;
		}
		int nd = b;
		while (nd > 0 && !Q.empty()) {
			ii v = Q.top(); Q.pop();
			v.first = -v.first;
			if (v.first < i) continue;
			int tk = min(nd, v.second);
			nd -= tk; v.second -= tk;
			if (v.second > 0) Q.push(ii(-v.first, v.second));
		}
		if (nd > 0) return false;
	}
	return true;
}

int main()
{
	scanf("%d %d %d", &n, &d, &b);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		seq.push_back(iii(ii(getLeft(i), getRight(i)), a[i]));
	}
	sort(seq.begin(), seq.end());
	int lef = 0, rig = (n - 1) / 2;
	while (lef <= rig) {
		int mid = lef + rig >> 1;
		if (Check(mid)) rig = mid - 1;
		else lef = mid + 1;
	}
	printf("%d\n", rig + 1);
	return 0;
}