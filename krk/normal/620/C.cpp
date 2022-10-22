#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 300005;

vector <ii> res;
set <int> S;
int n;
int a[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1, j; i <= n; i = j) {
		S.clear();
		bool cond = false;
		j = i; S.insert(a[j]); j++;
		while (j <= n && !cond) {
			cond = S.find(a[j]) != S.end();
			S.insert(a[j]);
			j++;
		}
		if (cond) res.push_back(ii(i, j - 1));
		else if (res.empty()) { printf("-1\n"); return 0; }
			 else res.back().second = n;
	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d %d\n", res[i].first, res[i].second);
	return 0;
}