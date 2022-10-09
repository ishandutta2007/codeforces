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
#define REYNA(i, a, b) for (int i=(a); i<(b); ++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PII, PII> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int maxn = 1000100;
int n, a, b;
int deg[maxn];

int main()
{
	boost;
	cin >> n;
	if (n == 2)
	{
		OUT("Yes\n1\n1 2");
	}
	
	FOR(i, 2, n)
	{
		int a, b;
		cin >> a >> b;
		deg[a]++; deg[b]++;
	}
	
	int ile = -1;
	FOR(i, 1, n)
		if (deg[i] > 2)
		{
			if (ile != -1) OUT("No");
			ile = i;
		}
	
	if (ile == -1)
	{
		FOR(i, 1, n)
			if (deg[i] == 2) ile = i;
	}
	
	int cnt = 0;
	FOR(i, 1, n)
		if (deg[i] == 1) ++cnt;
	
	cout << "Yes\n";
	cout << cnt << endl;
	FOR(i, 1, n)
		if (deg[i] == 1) cout << ile << ' ' << i << "\n";
}