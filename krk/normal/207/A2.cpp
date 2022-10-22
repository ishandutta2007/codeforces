#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 5005;

int n;
vector <int> pr[Maxn];
int pnt[Maxn];
int lst;
set <ii> S;
int res;
vector <ii> seq;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int k, a, x, y, m; scanf("%d %d %d %d %d", &k, &a, &x, &y, &m); 
		pr[i].push_back(a);
		for (int j = 2; j <= k; j++) {
			a = (ll(a) * ll(x) + ll(y)) % ll(m);
			pr[i].push_back(a);
		}
		S.insert(ii(pr[i][0], i)); pnt[i] = 1;
	}
	while (!S.empty()) {
		set <ii>::iterator it = S.lower_bound(ii(lst, 0));
		if (it == S.end()) { res++; it = S.begin(); }
		ii p = *it; S.erase(it);
		seq.push_back(p); lst = p.first;
		if (pnt[p.second] < pr[p.second].size()) S.insert(ii(pr[p.second][pnt[p.second]++], p.second));
	}
	printf("%d\n", res);
	if (seq.size() <= 200000)
		for (int i = 0; i < seq.size(); i++)
			printf("%d %d\n", seq[i].first, seq[i].second);
	return 0;
}