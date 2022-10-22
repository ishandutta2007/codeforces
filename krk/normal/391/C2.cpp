#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;
const ll Inf = 9000000000000000000ll;

int n, k;
ii pe[Maxn];
int l, r;
set <ii> all_small, all_big, fig_small, fig_big;
ll cur;
ll res = Inf;
bool tk[Maxn];

ll Solve(int my)
{
	// to fight
	while (r < n && my == pe[r].first) {
		fig_big.insert(ii(pe[r].second, r)); r++;
	}
	// infer
	while (l < n && pe[l].first + 1 < my) {
		if (fig_small.count(ii(pe[l].second, l))) {
			cur -= pe[l].second; fig_small.erase(ii(pe[l].second, l));
			all_big.insert(ii(pe[l].second, l));
		} else fig_big.erase(ii(pe[l].second, l));
		l++;
	}
	int notreach = n - r;
	if (notreach >= k) return Inf;
	int lft = k - 1 - notreach;
	int destr = max(0, int(fig_small.size() + fig_big.size()) - lft);
	while (fig_small.size() > destr) {
		ii p = *fig_small.rbegin();
		cur -= p.first; fig_small.erase(p);
		all_big.insert(p); fig_big.insert(p);
	}
	while (fig_small.size() < destr) {
		ii p = *fig_big.begin();
		cur += p.first; fig_big.erase(p);
		if (all_big.count(p)) all_big.erase(p);
		else { all_small.erase(p); cur -= p.first; }
		fig_small.insert(p);
	}
	while (fig_small.size() && fig_big.size() && *fig_big.begin() < *fig_small.rbegin()) {
		ii p = *fig_small.rbegin();
		cur -= p.first; fig_small.erase(p);
		all_big.insert(p); fig_big.insert(p);
		p = *fig_big.begin();
		cur += p.first; fig_big.erase(p);
		if (all_big.count(p)) all_big.erase(p);
		else { all_small.erase(p); cur -= p.first; }
		fig_small.insert(p);
	} 
	destr = max(0, my - destr);
	while (all_small.size() > destr) {
		ii p = *all_small.rbegin();
		cur -= p.first; all_small.erase(p);
		all_big.insert(p);
	}
	while (all_small.size() < destr) {
		ii p = *all_big.begin();
		cur += p.first; all_big.erase(p);
		all_small.insert(p);
	}
	while (all_small.size() && all_big.size() && *all_big.begin() < *all_small.rbegin()) {
		ii p = *all_small.rbegin();
		cur -= p.first; all_small.erase(p);
		all_big.insert(p);
		p = *all_big.begin();
		cur += p.first; all_big.erase(p);
		all_small.insert(p);
	}
	return cur;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &pe[i].first, &pe[i].second);
	sort(pe, pe + n);
	for (int i = 0; i < n; i++)
		all_big.insert(ii(pe[i].second, i));
	for (int i = 0; i <= n; i++)
		res = min(res, Solve(i));
	printf("%I64d\n", res == Inf? -1ll: res);
	return 0;
}