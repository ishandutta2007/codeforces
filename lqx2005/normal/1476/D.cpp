#include<bits/stdc++.h>

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define forgp(u, g, v) for(int iu = 0, v; iu < (int)g[u].size() && (v = g[u][iu], 1); iu++)
#define mp make_pair
#define siz(v) (int)(v).size()
#define x first
#define y second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef double db;
const int N = 3e5 + 10;
int n, cnt[N][2], ans[N];

char a[N];

void work() {
	scanf("%d", &n);
	scanf("%s", a + 1);
	for(int i = 0; i <= n; i++) ans[i] = 0;
	cnt[0][0] = cnt[0][1] = 1;
	for(int i = 1; i <= n; i++) {
		cnt[i][0] = cnt[i][1] = 1;
		if(a[i] == 'L') cnt[i][0] += cnt[i - 1][1];
		else cnt[i][1] += cnt[i - 1][0];
	}
	for(int i = 0; i <= n; i++) ans[i] += cnt[i][0];
	cnt[n][0] = cnt[n][1] = 1;
	for(int i = n - 1; i >= 0; i--) {
		cnt[i][0] = cnt[i][1] = 1;
		if(a[i + 1] == 'R') cnt[i][0] += cnt[i + 1][1];
		else cnt[i][1] += cnt[i + 1][0];
	}
	for(int i = 0; i <= n; i++) ans[i] += cnt[i][0];
	for(int i = 0; i <= n; i++) printf("%d ", ans[i] - 1);
	printf("\n");
	return;
}
int main() {
	int t;
	scanf("%d", &t);
	for(; t--; ) work();
	return 0;
}