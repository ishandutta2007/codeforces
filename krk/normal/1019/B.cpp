#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int Inf = 2000000007;

int n;
int dp[Maxn];

int Ask(int ind)
{
	ind++;
	if (dp[ind] == Inf) {
		printf("? %d\n", ind); fflush(stdout);
		scanf("%d", &dp[ind]);
	}
	return dp[ind];
}

void Answer(int ans)
{
	if (ans != -1) ans++;
	printf("! %d\n", ans); fflush(stdout);
}

int main()
{
	fill(dp, dp + Maxn, Inf);
	scanf("%d", &n);
	if (n % 4) { Answer(-1); return 0; }
	if (Ask(0) == Ask(n / 2)) { Answer(0); return 0; }
	if (Ask(n / 4) == Ask(n / 4 + n / 2)) { Answer(n / 4); return 0; }
	int lef, rig;
	bool indic;
	if ((Ask(0) > Ask(n / 2)) != (Ask(n / 4) > Ask(n / 4 + n / 2))) {
		lef = 0, rig = n / 4 - 1, indic = Ask(0) > Ask(n / 2); 
	} else {
		lef = n / 4, rig = n / 2 - 1, indic = Ask(n / 4) > Ask(n / 4 + n / 2);
	}
	while (lef <= rig) {
		int mid = lef + rig >> 1;
		if (Ask(mid) == Ask(mid + n / 2)) { Answer(mid); return 0; }
		if (indic == (Ask(mid) > Ask(mid + n / 2))) lef = mid + 1;
		else rig = mid - 1;
	}
	assert(false);
	return 0;
}