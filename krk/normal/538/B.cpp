#include <cstdio>
#include <vector>
using namespace std;

const int Maxn = 1000005;

vector <int> tr;
int n;
int dp[Maxn], par[Maxn];

bool Ok(int x)
{
	while (x) {
		if (x % 10 > 1) return false;
		x /= 10;
	}
	return true;
}

int main()
{
	for (int i = 1; i < Maxn; i++)
		if (Ok(i)) tr.push_back(i);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		dp[i] = 1000000000; par[i] = i;
		for (int j = 0; j < tr.size() && tr[j] <= i; j++) {
			int cand = dp[i - tr[j]] + 1;
			if (cand < dp[i]) { dp[i] = cand; par[i] = tr[j]; }
		}
	}
	printf("%d\n", dp[n]);
	while (n) {
		printf("%d", par[n]);
		n -= par[n];
		printf("%c", n? ' ': '\n');
	}
	return 0;
}