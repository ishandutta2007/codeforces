#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 100005;

int n, p, k;
iii ba[Maxn];
set <ii> S;

bool Less(const iii &a, const iii &b)
{
	if (a.first.first != b.first.first) return a.first.first < b.first.first;
	if (a.first.second != b.first.second) return a.first.second > b.first.second;
	return a.second < b.second;
}

int main()
{
	scanf("%d %d %d", &n, &p, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &ba[i].first.second, &ba[i].first.first);
		ba[i].second = i + 1;
	}
	sort(ba, ba + n, Less);
	for (int i = p - k; i < p; i++)
		S.insert(ii(ba[i].first.second, i));
	for (int i = p; i < n; i++)
		if (S.begin()->first <= ba[i].first.second) {
			S.erase(S.begin());
			S.insert(ii(ba[i].first.second, i));
		}
	int i = p;
	int mn = n;
	for (set <ii>::iterator it = S.begin(); it != S.end(); it++) {
		printf("%d%c", ba[it->second].second, --i? ' ': '\n');
		mn = min(mn, it->second);
	}
	for (int j = mn - 1; i > 0; j--)
		printf("%d%c", ba[j].second, --i? ' ': '\n');
	return 0;
}