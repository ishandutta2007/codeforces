#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;

const int C = 1000;
const int D = 2000;
bool dp[2][32][6010];
int opt[1010][32][2010];
int tab[32];

vector <int> v;

int ile[5010], N;
bitset <2010> arr[2010];
PII help[2010];

void addEdge(int x, int y) {
	arr[x].set(y, 1);
	ile[x]--;
}

void print(vector <int> v)
{
	for (auto u : v) ile[++N] = u;
	for (int i=1; i <= N; ++i)
	{
		for (int j=1; j < i; ++j) help[j] = mp(ile[j], j);
		sort(help + 1, help + i);
		for (int j = 1; j < i; ++j)
		{
			if (ile[help[j].e2] < ile[i]) addEdge(i, help[j].e2);
			else addEdge(help[j].e2, i);
		}
	}
	
	FOR(i, 1, N) assert(ile[i] == 0);
	
	FOR(i, 1, N) {
		FOR(j, 1, N) cout << arr[i].test(j);
		cout << "\n";
	}
}

int main()
{
	boost;
	int m;
	cin >> m;
	FOR(i, 1, m) cin >> tab[i];
	sort(tab+1, tab+m+1);
	dp[0][0][0] = 1;
	int res = 6010;
	for (int i=1; i <= C; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			for (int nad = 0; nad <= D; ++nad)
			{
				dp[i & 1][j][nad] = 0; dp[i & 1][0][nad] = 0;
				int current_delta = tab[j] - (i - 1);
				if (nad - current_delta >= 0) 
				{
					dp[i & 1][j][nad] |= dp[(i & 1) ^ 1][j][nad - current_delta];
					dp[i & 1][j][nad] |= dp[(i & 1) ^ 1][j - 1][nad - current_delta];
					if (dp[i & 1][j][nad] && dp[(i & 1) ^ 1][j][nad - current_delta]) opt[i][j][nad] = j;
					if (dp[i & 1][j][nad] && dp[(i & 1) ^ 1][j - 1][nad - current_delta]) opt[i][j][nad] = j - 1;
				}

				if (nad == 0 && j == m && dp[i & 1][j][nad]) {
					if (i < res) {
						res = i;
					}
				}
			}
		}
		
		if (i > res) break;
	}
	
	if (res == 6010) OUT("=(");
	int nad = 0;
	cout << res << endl;
	int j = m;
	for (int i = res; i > 0; --i)
	{
		v.pb(tab[j]);
		if (opt[i][j][nad] == j-1) {
			nad += (i - 1) - tab[j];
			--j;
		}
		else {
			nad += (i - 1) - tab[j];
		}
	}

	reverse(v.begin(), v.end());
	print(v);
}