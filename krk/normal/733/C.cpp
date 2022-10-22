#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef pair <int, char> ic;

const int Maxn = 505;

int n;
vector <int> cur;
int k;
int b[Maxn];
vector <ic> res;

bool Solve(int l, int r)
{
	if (l == r) return true;
	int mx = 0;
	for (int i = l; i <= r; i++)
		mx = max(mx, cur[i]);
	for (int i = l; i <= r; i++) if (cur[i] == mx) {
		if (i > l && cur[i] > cur[i - 1]) {
			res.push_back(ic(i, 'L'));
			cur[i - 1] += cur[i]; cur.erase(cur.begin() + i);
			return Solve(l, r - 1);
		}
		if (i < r && cur[i] > cur[i + 1]) {
			res.push_back(ic(i, 'R'));
			cur[i + 1] += cur[i]; cur.erase(cur.begin() + i);
			return Solve(l, r - 1);
		}
	}
	return false;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		cur.push_back(a);
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &b[i]);
		int pnt = i, sum = 0;
		while (pnt < cur.size() && sum < b[i]) {
			sum += cur[pnt]; pnt++;
		}
		if (sum != b[i]) { printf("NO\n"); return 0; }
		if (!Solve(i, pnt - 1)) { printf("NO\n"); return 0; }
	}
	if (cur.size() > k) { printf("NO\n"); return 0; }
	printf("YES\n");
	for (int i = 0; i < res.size(); i++)
		printf("%d %c\n", res[i].first + 1, res[i].second);
	return 0;
}