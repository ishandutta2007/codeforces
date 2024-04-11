#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define REYNA(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, pair <int, ll> > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 1001000;
int n, m, k, a, b, c;
int x, y, z, t1, t2, t3;

int value[2][1010], init[2][1010];
int wynik[1010];

bool check(int i)
{
	int l = 0, r = 0;
	FOR(j, 1, i-1)
		if (wynik[j] > wynik[i]) ++l;
	FOR(j, i+1, n)
		if (wynik[j] > wynik[i]) ++r;
	
	return (l == init[0][i] && r == init[1][i]);
}

void check()
{
	bool ans = 1;
	FOR(i, 1, n) ans &= check(i);
	if (!ans) OUT("NO");
	cout << "YES\n";
	FOR(i, 1, n) cout << wynik[i] << ' ';
	exit(0);
}

int main()
{
	boost;
	cin >> n;
	FOR(j, 0, 1) FOR(i, 1, n) cin >> value[j][i], init[j][i] = value[j][i];
	FOR(i, 1, n) wynik[i] = -1;
	
	int DIG = n;
	while (true)
	{
		bool ist = 0, ile = 0;
		FOR(i, 1, n)
			if (wynik[i] == -1) ist = 1;
		if (!ist) check();
		/*FOR(i, 1, n) cout << value[0][i] << ' ';
		cout << endl;
		FOR(i, 1, n) cout << value[1][i] << ' ';
		cout << endl;*/
		
		FOR(i, 1, n)
			if (wynik[i] == -1 && value[0][i] == 0 && value[1][i] == 0)
			{
				wynik[i] = DIG;
				ile = 1;
			}
		
		if (ile == 0) OUT("NO");
		FOR(i, 1, n)
			if (wynik[i] == DIG)
			{
				FOR(j, 1, i-1) value[1][j]--;
				FOR(j, i+1, n) value[0][j]--;
			}
			
		--DIG;
	}
}