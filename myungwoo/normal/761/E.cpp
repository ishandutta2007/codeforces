#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
typedef long long lld;
typedef pair<int, int> pii;

#define MAXN 31

int yy[] = {-1, 0, 1, 0}, xx[] = {0, 1, 0, -1};
int N;
lld X[MAXN], Y[MAXN];
vector <int> con[MAXN];

bool dfs(int n, int d, int from, int step)
{
	if (sz(con[n]) > 4) return 0;
	vector <int> arr, dirs;
	for (int t: con[n]) if (t != from) arr.pb(t);
	for (int i=0;i<4;i++) if (i != d) dirs.pb(i);
	lld far = 1LL << step;
	for (int i=0;i<sz(arr);i++){
		int t = arr[i], d = dirs[i];
		X[t] = X[n] + far * xx[d];
		Y[t] = Y[n] + far * yy[d];
		if (!dfs(t, (d+2)%4, n, step-1)) return 0;
	}
	return 1;
}

int main()
{
	scanf("%d", &N);
	for (int i=1;i<N;i++){
		int a, b; scanf("%d%d", &a, &b);
		con[a].pb(b); con[b].pb(a);
	}
	if (!dfs(1, -1, 0, 50)){ puts("NO"); return 0; }
	puts("YES");
	for (int i=1;i<=N;i++) printf("%lld %lld\n", X[i], Y[i]);
}