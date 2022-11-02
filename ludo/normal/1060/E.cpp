#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int maxn = 200 * 1000 + 1;

int N, p[maxn];
vi E[maxn];

ll npath[maxn][2], sumpath[maxn][2], ret = 0LL;

void dfs(int u, int v)
{
	for (int w : E[v]) {
		if (w == u) continue;
		p[w] = v;
		dfs(v, w);
	}

	npath[v][0] = npath[v][1] = 0;
	sumpath[v][0] = sumpath[v][1] = 0;

	ll inc = 0LL;
	for (int w : E[v]) {
		if (w == u) continue;

		npath[v][0] += npath[w][1];
		npath[v][1] += npath[w][0];
		sumpath[v][0] += sumpath[w][1] + npath[w][1];
		sumpath[v][1] += sumpath[w][0] + npath[w][0];

		// subtract even, even
		inc -= 1LL * (sumpath[w][1] + npath[w][1]) * npath[w][1];
		// subtract odd, odd
		inc -= 1LL * (sumpath[w][0] + npath[w][0]) * npath[w][0];
		// subtract even, odd
		inc -= 1LL * (sumpath[w][0] + npath[w][0] + npath[w][0]) * npath[w][1];
		// subtract odd, even
		inc -= 1LL * (sumpath[w][1] + npath[w][1] + 0) * npath[w][0];
	}
	inc += sumpath[v][0] + sumpath[v][1] + npath[v][1];
	// even, even:
	inc += 1LL * sumpath[v][0] * npath[v][0];
	// odd, odd:
	inc += 1LL * sumpath[v][1] * npath[v][1];
	// even, odd:
	inc += 1LL * (sumpath[v][1] + npath[v][1]) * npath[v][0];
	// odd, even:
	inc += 1LL * (sumpath[v][0] + 0) * npath[v][1];

	ret += inc;
	npath[v][0]++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	scanf("%d", &N);
	// cin >> N;
	for (int i = N; --i; ) {
		int u, v;
		scanf("%d%d", &u, &v);
		// cin >> u >> v;
		E[u].pb(v);
		E[v].pb(u);
	}

	dfs(1, 1);
	printf("%lld\n", ret/2LL);
	return 0;
}