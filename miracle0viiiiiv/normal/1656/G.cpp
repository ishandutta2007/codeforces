#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;

int n, a[200005], cnt[200005], ra[200005], ans[200005];
vector<int> G[400005];
int ptr[400005], pre;
void dfs(int v)
{
	for(; ptr[v] < G[v].size(); ) {
		int u = G[v][ptr[v] ++];
		dfs(u);
		if(v <= n) {
			ans[v] = pre; pre = v;
		}
	}
}

void solve()
{
	scanf("%d", &n);
	rep1(i, n) scanf("%d", &a[i]);
	rep1(i, n) cnt[i] = 0;
	rep1(i, n) cnt[a[i]] ++;
	int g = -1;
	rep1(i, n) if(cnt[i] % 2 == 1) {
		if(g == -1) g = i;
		else {
			printf("NO\n"); return;
		}
	}
	if(cnt[g] == 1 && a[(n + 1) / 2] == g) {
		printf("NO\n"); return;
	}
	
	rep1(i, n / 2) ra[i] = 0;
	for(int i = n / 2 - 1; i >= 1; i --) {
		if(cnt[a[i]] >= 2) {
			cnt[a[i]] -= 2; ra[i + 1] = a[i];
		} else if(cnt[a[n + 1 - i]] >= 2) {
			cnt[a[n + 1 - i]] -= 2; ra[i + 1] = a[n + 1 - i];
		}
	}
	int pos = 1;
	rep1(i, n / 2) if(ra[i] == 0) {
		while(cnt[pos] < 2) pos ++;
		cnt[pos] -= 2; ra[i] = pos;
	}
	rep1(i, n / 2) ra[n + 1 - i] = ra[i];
	if(g != -1) ra[(n + 1) / 2] = g;
	
	rep1(i, n * 2) G[i].clear();
	rep1(i, n) {
		G[i].push_back(ra[i] + n); G[a[i] + n].push_back(i);
	}
	pre = 1;
	rep1(i, n * 2) ptr[i] = 0;
	dfs(1);
	printf("YES\n");
	rep1(i, n) printf("%d ", ans[i]); printf("\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}