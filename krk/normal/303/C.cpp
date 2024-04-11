#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 5005;
const int Maxm = 1000001;

int n, k;
int a[Maxn];
vector <int> p[Maxm];
int lst[Maxn];

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			int dif = a[j] - a[i];
			if (p[dif].size() <= k) p[dif].push_back(i);
		}
	for (int i = 1; i < Maxm; i++) {
		int tot = 0;
		for (int j = i; j < Maxm && tot <= k; j += i)
			for (int l = 0; l < p[j].size() && tot <= k; l++)
				if (lst[p[j][l]] != i) { lst[p[j][l]] = i; tot++; }
		if (tot <= k) { printf("%d\n", i); return 0; }
	}
	printf("%d\n", Maxm);
	return 0;
}