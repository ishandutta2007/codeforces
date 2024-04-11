//algorytm dziala dokladnie wedlug mojego rozwiazania zadania 6 z LXVII OM
#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000100
int A[maxn], B[maxn], XOR[maxn], type[maxn];
vector <int> v[maxn];
bool odw[maxn];
int skoj[maxn], toparent[maxn], n, m, a, b;

inline void printEdge(int a, int b)
{
	int sr = A[a];
	if (sr == A[b] || sr == B[b]);
	else sr = B[a];
	printf("%d %d %d\n", XOR[a] xor sr, sr, XOR[b] xor sr);
}

void dfs(int x)
{
	odw[x] = 1;
	for (auto edge : v[x]) {
	  int u = XOR[edge] xor x;
	  if (!odw[u])
	  {
	  		type[edge] = 1;
	   		toparent[u] = edge;
	   		dfs(u);
	  }
	  else if (type[edge] == 0) type[edge] = 2;
	}
}
vector <PII> result;
void solve(int x)
{
	odw[x] = 1;
	int e = 0;
	for (auto edge : v[x]) 
	{
		int u = XOR[edge] xor x;
		if (!odw[u]) solve(u);
	}
	for (auto edge : v[x]) 
	{
		int u = XOR[edge] xor x;
		if (!skoj[edge] && edge != toparent[x])
		{
			if (!e) e = edge;
			else result.pb(mp(e, edge)), skoj[e] = 1, skoj[edge] = 1, e = 0;
		}
	}
	if (e) result.pb(mp(e, toparent[x])), skoj[e] = 1, skoj[toparent[x]] = 1;
}

int main()
{
	scanf("%d%d", &n, &m);
	if (m & 1) OUT("No solution");
	for (int i=1; i<=m; ++i)
	{
		scanf("%d%d", &a, &b);
		A[i] = b;
		B[i] = a;
		XOR[i] = A[i] xor B[i];
		v[a].pb(i);
		v[b].pb(i);
	}
	fill(skoj, skoj + m + 1, 0);
	dfs(1);
	//STEP 1 -> merging backwards edges

	for (int i=1; i<=n; ++i)
	{
		int e = 0;
		for (auto edge:v[i])
			if (skoj[edge] == 0 && type[edge] == 2)
			{
				if (!e) e = edge;
				else result.pb(mp(e,edge)), skoj[e] = 1, skoj[edge] = 1, e = 0;
			}
	}
	
	fill(odw, odw + n + 1, false);
	solve(1);
	for (auto it : result) printEdge(it.e1, it.e2);
}