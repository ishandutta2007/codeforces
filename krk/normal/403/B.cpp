#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int Maxn = 5005;
const int Maxm = 100005;

bool nprime[Maxm];
vector <int> pr;
bool bad[Maxm];
set <int> B;
int n, m;
int a[Maxn];
int g[Maxn], best[Maxn];
int delt[Maxn];
int sum, bdelt;

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main()
{	
	for (int i = 2; i < Maxm; i++) if (!nprime[i]) {
		pr.push_back(i);
		for (int j = i + i; j < Maxm; j += i)
			nprime[j] = true;
	}
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) {
		int b; scanf("%d", &b);
		if (b < Maxm) bad[b] = true;
		else B.insert(b);
	}
	for (int i = 1; i <= n; i++) {
		int num = a[i];
		for (int j = 0; pr[j] * pr[j] <= num; j++)
			if (num % pr[j] == 0)
				if (bad[pr[j]])
					do { sum--; num /= pr[j]; }
					while (num % pr[j] == 0);
				else do { sum++; num /= pr[j]; }
					 while (num % pr[j] == 0);
		if (num > 1)
			if (num < Maxm) sum += bad[num]? -1: 1;
		 	else sum += B.count(num)? -1: 1;
		g[i] = gcd(g[i - 1], a[i]);
	}
	for (int i = n; i >= 1; i--) {
		int num = g[i];
		delt[i] = 0;
		for (int j = 0; pr[j] * pr[j] <= num; j++)
			if (num % pr[j] == 0)
				if (bad[pr[j]])
					do { delt[i]++; num /= pr[j]; }
					while (num % pr[j] == 0);
				else do { delt[i]--; num /= pr[j]; }
					 while (num % pr[j] == 0);
		if (num > 1)
			if (num < Maxm) delt[i] += bad[num]? 1: -1;
			else delt[i] += B.count(num)? 1: -1;
		best[i] = delt[i] * i;
		for (int j = i + 1; j <= n; j++)
			best[i] = max(best[i], (delt[i] - delt[j]) * i + best[j]);
		bdelt = max(bdelt, best[i]);
	}
	printf("%d\n", sum + bdelt);
	return 0;
}