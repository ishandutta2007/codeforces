#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> ii;

const int Maxn = 100005;

int n;
int a, b, c, d;
ii p[Maxn];
vector <ll> seq;

bool Less(const ii &a, const ii &b)
{
	if (a.first != b.first) return a.first < b.first;
	return a.second > b.second;
}

int main()
{
	scanf("%d", &n);
	scanf("%d/%d %d/%d", &a, &b, &c, &d);
	for (int i = 0; i < n; i++) {
		int x, y; scanf("%d %d", &x, &y);
		p[i] = ii(ll(x) * ll(c) - ll(y) * ll(d), -ll(x) * ll(a) + ll(y) * ll(b));
	}
	sort(p, p + n, Less);
	for (int i = 0; i < n; i++) if (p[i].first > 0 && p[i].second > 0) {
		int ind = lower_bound(seq.begin(), seq.end(), p[i].second) - seq.begin();
		if (ind == seq.size()) seq.push_back(p[i].second);
		else seq[ind] = p[i].second;
	}
	printf("%d\n", seq.size());
	return 0;
}