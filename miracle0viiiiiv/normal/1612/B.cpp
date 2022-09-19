#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, a, b;
void solve()
{
	scanf("%d%d%d", &n, &a, &b);
	if(a == b || a > n / 2 + (b <= n / 2) || b < n / 2 + (a <= n / 2)) printf("-1\n");
	else {
		printf("%d", a);
		for(int i = n; i >= 1; i --) if(i != a && i != b) printf(" %d", i);
		printf(" %d\n", b);
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}