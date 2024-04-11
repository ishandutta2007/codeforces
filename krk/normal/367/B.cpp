#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 200005;

int n, m, p;
int a[Maxn];
map <int, int> M;
vector <int> res;

int main()
{
	scanf("%d %d %d", &n, &m, &p);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) {
		int b; scanf("%d", &b);
		M[b]++;
	}
	for (int i = 1; i <= p && i + (m - 1) * p <= n; i++) {
		int l = i, r = i;
		while (r < i + m * p) {
			if (--M[a[r]] == 0) M.erase(a[r]);
			r += p;
		}
		if (M.empty()) res.push_back(l);
		while (r <= n) {
			if (--M[a[r]] == 0) M.erase(a[r]);
			if (++M[a[l]] == 0) M.erase(a[l]);
			l += p; r += p;
			if (M.empty()) res.push_back(l);
		}
		while (l <= n) {
			if (++M[a[l]] == 0) M.erase(a[l]);
			l += p;
		}
	}
	sort(res.begin(), res.end());
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}