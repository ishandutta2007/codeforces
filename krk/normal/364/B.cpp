#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxm = 500005;

int n, d;
bool dp[Maxm];

int main()
{
	dp[0] = true;
	scanf("%d %d", &n, &d);
	for (int i = 0; i < n; i++) {
		int c; scanf("%d", &c);
		for (int i = Maxm - c; i >= 0; i--)
			dp[i + c] |= dp[i]; 
	}
	int cur = 0, pnt = 0, nxt = 0, days = -1;
	do {
		cur = nxt;
		while (pnt < Maxm && pnt - cur <= d) {
			if (dp[pnt]) nxt = pnt;
			pnt++;
		}
		days++;
	} while (cur != nxt);
	printf("%d %d\n", cur, days);
	return 0;
}