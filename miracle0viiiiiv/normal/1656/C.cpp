#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, x[100005];
void solve()
{
	scanf("%d", &n);
	bool hv = false, hvd = false;
	rep(i, n) {
		scanf("%d", &x[i]);
		if(x[i] == 1) hv = true;
	}
	sort(x, x + n);
	rep(i, n - 1) if(x[i + 1] - x[i] == 1) hvd = true;
	if(hv && hvd) printf("NO\n");
	else printf("YES\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}