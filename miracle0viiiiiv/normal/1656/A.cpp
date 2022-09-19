#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

int n;
PII m, x;
void solve()
{
	m = MP(INF, -1); x = MP(-INF, -1);
	scanf("%d", &n);
	rep(i, n) {
		int a; scanf("%d", &a);
		m = min(m, MP(a, i));
		x = max(x, MP(a, i));
	}
	printf("%d %d\n", m.second + 1, x.second + 1);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}