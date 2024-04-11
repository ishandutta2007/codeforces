#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200015;
const int nil = 100005;

int n;
set <ii> S;
set <ii> T;
int w[Maxn];
vector <ii> cand[Maxn];
ii res[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y; scanf("%d %d", &x, &y);
		S.insert(ii(x, y));
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	for (set <ii>::iterator it = S.begin(); it != S.end(); it++) {
		ii p = *it;
		if (S.find(ii(p.first + 1, p.second)) == S.end() &&
			S.find(ii(p.first, p.second + 1)) == S.end()) {
			cand[p.second - p.first + nil].push_back(p);
			T.insert(p);
		}
	}
	for (int i = n; i >= 1; i--) {
		int diag = w[i] + nil;
		if (cand[diag].empty()) { printf("NO\n"); return 0; }
		ii p = cand[diag].back(); cand[diag].pop_back();
		res[i] = p;
		ii u = ii(p.first - 1, p.second);
		if (S.find(u) != S.end() && T.find(u) == T.end()) {
			cand[u.second - u.first + nil].push_back(u);
			T.insert(u);
		}
		u = ii(p.first, p.second - 1);
		if (S.find(u) != S.end() && T.find(u) == T.end()) {
			cand[u.second - u.first + nil].push_back(u);
			T.insert(u);
		}
	}
	printf("YES\n");
	for (int i = 1; i <= n; i++)
		printf("%d %d\n", res[i].first, res[i].second);
	return 0;
}