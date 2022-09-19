#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, k, a[200005];
void solve()
{
	scanf("%d%d", &n, &k);
	rep(i, n) scanf("%d", &a[i]);
	sort(a, a + n);
	int j = 0;
	rep(i, n) {
		while(a[j] < a[i] - k) j ++;
		if(a[j] == a[i] - k) {
			printf("YES\n"); return;
		}
	}
	printf("NO\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}