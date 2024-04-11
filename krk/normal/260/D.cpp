#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

int n;
vector <ii> a, b;
vector <iii> res;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int c, s; scanf("%d %d", &c, &s);
		if (c == 0) a.push_back(ii(s, i));
		else b.push_back(ii(s, i));
	}
	sort(a.begin(), a.end()); sort(b.begin(), b.end());
	int j = 0;
	for (int i = 0; i < a.size(); i++)
		if (j == b.size()) res.push_back(iii(ii(a[i].second, b.back().second), 0));
		else while (j < b.size()) {
				int tk = min(a[i].first, b[j].first); res.push_back(iii(ii(a[i].second, b[j].second), tk));
				a[i].first -= tk; b[j].first -= tk;
				if (b[j].first == 0) j++;
				else break;
			}
	for (int i = 0; i < res.size(); i++)
		printf("%d %d %d\n", res[i].first.first, res[i].first.second, res[i].second);
	return 0;
}