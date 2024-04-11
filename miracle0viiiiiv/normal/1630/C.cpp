#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, a[300005], occ[300005], tor[300005];
void solve()
{
	scanf("%d", &n);
	rep1(i, n) scanf("%d", &a[i]);
	rep1(i, n) occ[i] = tor[i] = 0;
	for(int i = n; i >= 1; i --) {
		occ[a[i]] = max(occ[a[i]], i);
		tor[i] = max(tor[i], occ[a[i]]);
	}
	rep1(i, n) tor[i] = max(tor[i - 1], tor[i]);
	
	int ans = n;
	rep1(i, n) {
		ans --;
		for(; tor[i] != i; i = tor[i]) ans --;
	}
	printf("%d\n", ans);
}

int main()
{
	int T = 1;
	while(T --) solve();
	return 0;
}