#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

bool prime[Maxn];
vector <int> pr;
int n;
int a[Maxn];
int isin[Maxn];
vector <ii> res;

int main()
{
	fill(prime + 2, prime + Maxn, true);
	for (int i = 2; i < Maxn; i++) if (prime[i]) {
		pr.push_back(i);
		for (int j = i + i; j < Maxn; j += i)
			prime[j] = false;
	}

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]); isin[a[i]] = i;
	}
	for (int i = 1; i <= n; i++)
		if (isin[i] != i) {
			int nd = isin[i] - i + 1;
			while (nd > 1) {
				int ind = upper_bound(pr.begin(), pr.end(), nd) - 1 - pr.begin();
				int j = isin[i] - pr[ind] + 1;
				res.push_back(ii(j, isin[i]));
				int wh = a[j];
				swap(a[j], a[isin[i]]); swap(isin[wh], isin[i]);
				nd = isin[i] - i + 1;
			}
		}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d %d\n", res[i].first, res[i].second);
	return 0;
}