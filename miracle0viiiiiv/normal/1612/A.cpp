#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int main()
{
	int T, x, y;
	scanf("%d", &T);
	while(T --) {
		scanf("%d%d", &x, &y);
		if((x + y) % 2 == 1) printf("-1 -1\n");
		else printf("%d %d\n", x / 2, (y + 1) / 2);
	}
	return 0;
}