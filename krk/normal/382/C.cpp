#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 100005;

int n;
int a[Maxn];
vector <int> res;

bool getStatus(int d)
{
	for (int i = 0; i + 1 < n; i++)
		if (a[i] + d != a[i + 1])
			if (a[i] + 2 * d == a[i + 1])
				res.push_back(a[i] + d);
			else return false;
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	if (n == 1) printf("-1\n");
	else {
		sort(a, a + n);
		int d = Inf;
		for (int i = 0; i + 1 < n; i++)
			d = min(d, a[i + 1] - a[i]);
		if (getStatus(d))
			if (res.size() > 1) printf("0\n");
			else {
				if (res.empty()) { res.push_back(a[0] - d); res.push_back(a[n - 1] + d); }
				if (n == 2 && (a[0] + a[1]) % 2 == 0) res.push_back((a[0] + a[1]) / 2);
				sort(res.begin(), res.end()); res.erase(unique(res.begin(), res.end()), res.end());
				printf("%d\n", res.size());
				for (int i = 0; i < res.size(); i++)
					printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
			}
		else printf("0\n");
	}
	return 0;
}