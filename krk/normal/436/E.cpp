#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 300005;
const ll Inf = 1000000000000000000ll;

int n, w;
int a[Maxn], b[Maxn];
int seq[Maxn];
set <ii> best, worse;
ll cur, res = Inf;
int wth;
int col[Maxn];

bool Less(const int &i, const int &j)
{
	if (b[i] != b[j]) return b[i] < b[j];
	if (a[i] != a[j]) return a[i] < a[j];
	return i < j;
}

ii getLast(set <ii> &S)
{
	set <ii>::iterator it = S.end(); it--;
	return *it;
}

int main()
{
	scanf("%d %d", &n, &w);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i], &b[i]);
		seq[i] = i;
	}
	sort(seq, seq + n, Less);
	for (int i = 0; i < n; i++)
		worse.insert(ii(a[seq[i]], seq[i]));
	for (int i = 0; i <= n; i++) {
		int need = w - i;
		while (!best.empty() && best.size() > need) {
			ii p = getLast(best);
			cur -= p.first;
			worse.insert(p);
			best.erase(p);
		}
		while (best.size() < need && !worse.empty() || !best.empty() && !worse.empty() && worse.begin()->first < getLast(best).first) {
			cur += worse.begin()->first; best.insert(*worse.begin()); worse.erase(worse.begin());
			if (best.size() > need) { 
				ii p = getLast(best);
				cur -= p.first; best.erase(p); worse.insert(p);
			}
		}
		if (best.size() == need && cur < res) {
			res = cur; wth = i;
		}
		if (i < n) {
			ii p = ii(a[seq[i]], seq[i]);
			if (best.count(p)) { best.erase(p); cur -= p.first; }
			else worse.erase(p);
			cur += a[seq[i]]; worse.insert(ii(b[seq[i]] - a[seq[i]], seq[i]));
		}
	}
	printf("%I64d\n", res);
	best.clear(); worse.clear();
	for (int i = 0; i < wth; i++) {
		col[seq[i]]++; worse.insert(ii(b[seq[i]] - a[seq[i]], seq[i]));
	}
	for (int i = wth; i < n; i++)
		worse.insert(ii(a[seq[i]], seq[i]));
	int need = w - wth;
	while (need--) {
		col[worse.begin()->second]++; worse.erase(worse.begin());
	}
	for (int i = 0; i < n; i++)
		printf("%d", col[i]);
	printf("\n");
	return 0;
}