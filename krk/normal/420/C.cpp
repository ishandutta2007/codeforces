#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

typedef long long ll;
const int Maxn = 300005;

int n, p;
map <ii, int> W;
vector <int> neigh[Maxn];
int my[Maxn];
int cnt[Maxn];
ll tres;

void addEdge(int a, int b)
{
	my[a]++; my[b]++;
	cnt[a - 1]++; cnt[b - 1]++;
	W[ii(a, b)]++; W[ii(b, a)]++;
}

bool Less(const int &a, const int &b) { return a > b; }

int main()
{
	scanf("%d %d", &n, &p);
	for (int i = 0; i < n; i++) {
		int a, b; scanf("%d %d", &a, &b);
		addEdge(a, b);
	}
	for (map <ii, int>::iterator it = W.begin(); it != W.end(); it++)
		neigh[it->first.first].push_back(it->first.second);
	sort(cnt, cnt + n, Less);
	for (int i = 1; i <= n; i++) {
		int res = 0;
		int l = 1, r = n;
		while (l <= r) {
			int mid = l + r >> 1;
			if (my[i] + cnt[mid - 1] >= p) { res = mid; l = mid + 1; }
			else r = mid - 1;
		}
		if (my[i] + my[i] >= p) res--;
		for (int j = 0; j < neigh[i].size(); j++) {
			int u = neigh[i][j];
			if (my[i] + my[u] >= p) res--;
			if (my[i] + my[u] - W[ii(i, u)] >= p) res++;
		}
		tres += res;
	}
	printf("%I64d\n", tres / 2ll);
	return 0;
}