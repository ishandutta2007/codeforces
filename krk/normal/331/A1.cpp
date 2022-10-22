#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 300005;
const ll Inf = 1000000000000000000ll;

int n;
map <int, vector <int> > pos;
int a[Maxn];
ll psum[Maxn];
ll best = -Inf;
int bi;
vector <int> res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); pos[a[i]].push_back(i);
		psum[i] = (i? psum[i - 1]: 0ll) + max(0, a[i]);
	}
	for (map <int, vector <int> >::iterator it = pos.begin(); it != pos.end(); it++) if (it->second.size() > 1) {
		int l = it->second[0], r = it->second.back();
		ll cand = 2ll * ll(it->first) + psum[r - 1] - psum[l];
		if (cand > best) { best = cand; bi = it->first; }
	}
	printf("%I64d ", best);
	int l = pos[bi][0], r = pos[bi].back();
	for (int i = 0; i < l; i++) res.push_back(i);
	for (int i = l + 1; i < r; i++) if (a[i] < 0) res.push_back(i);
	for (int i = r + 1; i < n; i++) res.push_back(i);
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i] + 1, i + 1 < res.size()? ' ': '\n');
	return 0;
}