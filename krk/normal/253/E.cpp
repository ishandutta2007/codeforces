#include <cstdio>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 50005;
const int lim = 1000000000;
const ll Inf = 1000000000000000000ll;

int n;
int t[Maxn], s[Maxn], p[Maxn];
ll T;
ii byt[Maxn];
set <int> P;
vector <int> cand;
int x;
int lft[Maxn];
int res;
ll fin[Maxn];

ll Get(int y)
{
	p[x] = y;
	for (int i = 0; i < n; i++) lft[i] = s[i];
	priority_queue <ii> Q;
	ll curt = 0, nxtt;
	int pnt = 0;
	while (pnt < n || !Q.empty()) {
		nxtt = pnt < n? byt[pnt].first: Inf;
		if (!Q.empty()) {
			int v = Q.top().second; nxtt = min(nxtt, curt + lft[v]);
			lft[v] -= nxtt - curt;
			if (lft[v] == 0) { fin[v] = nxtt; Q.pop(); }
		}
		curt = nxtt;
		while (pnt < n && byt[pnt].first == curt) {
			Q.push(ii(p[byt[pnt].second], byt[pnt].second));
			pnt++;
		}
	}
	return fin[x];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &t[i], &s[i], &p[i]);
		byt[i] = ii(t[i], i);
		P.insert(p[i]);
	}
	scanf("%I64d", &T);
	if (n == 1) { printf("1\n%I64d\n", T); return 0; }
	sort(byt, byt + n);
	for (int i = 0; i < n; i++) if (p[i] != -1) {
		if (p[i] > 1 && !P.count(p[i] - 1)) cand.push_back(p[i] - 1);
		if (p[i] < lim && !P.count(p[i] + 1)) cand.push_back(p[i] + 1);
	} else x = i;
	sort(cand.begin(), cand.end()); cand.erase(unique(cand.begin(), cand.end()), cand.end());
	int l = 0, r = cand.size() - 1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (Get(cand[mid]) <= T) { res = mid; r = mid - 1; }
		else l = mid + 1;
	}
	printf("%d\n", cand[res]);
	Get(cand[res]);
	for (int i = 0; i < n; i++)
		printf("%I64d%c", fin[i], i + 1 < n? ' ': '\n');
	return 0;
}