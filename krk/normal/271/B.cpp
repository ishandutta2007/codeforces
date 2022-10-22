#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxp = 100100;
const int Maxn = 505;
const int Inf = 2000000000;

bool prime[Maxp];
vector <int> pr;
int n, m;
int inc[Maxn][Maxn];
int res = Inf;

int main()
{
	fill(prime + 2, prime + Maxp, true);
	for (int i = 2; i < Maxp; i++) if (prime[i]) {
		pr.push_back(i);
		for (int j = 2 * i; j < Maxp; j += i) prime[j] = false;
	}
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int a; scanf("%d", &a);
			inc[i][j] = pr[lower_bound(pr.begin(), pr.end(), a) - pr.begin()] - a;
		}
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++)
			sum += inc[i][j];
		res = min(res, sum);
	}
	for (int j = 0; j < m; j++) {
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += inc[i][j];
		res = min(res, sum);
	}
	printf("%d\n", res);
	return 0;
}