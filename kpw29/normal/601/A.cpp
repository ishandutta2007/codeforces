#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000100
int n,m,k,a,b,c;
int d[1000100][2];
int mac[1010][1010];

int bfs(int start, int par)
{
	for (int i=1; i<=n; ++i) d[i][par] = -1;
	d[start][par] = 0;
	queue <int> q;
	while (!q.empty()) q.pop();
	d[start][par] = 0;
	q.push(start);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		if (x == n) return d[x][par];
		for (int i=1; i<=n; ++i)
		  if (mac[x][i] == par && d[i][par] == -1) {
			  q.push(i);
			  d[i][par] = d[x][par] + 1;
		  }
	}
	return -1;
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=k; ++i)
	{
		scanf("%d%d", &a, &b);
		mac[a][b] = 1;
		mac[b][a] = 1;
	}
	for (int i=1; i<=n; ++i) mac[i][i] = 2;
	int w1 = bfs(1, 0); int w2 = bfs(1, 1);
	if (w1 == -1 || w2 == -1) puts("-1");
	else printf("%d", max(w1, w2));
	
}