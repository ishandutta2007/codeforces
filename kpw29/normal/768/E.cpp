#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false);}
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
typedef vector <int> vi;
const int mod = 1e9+7;
const int inf = 1e9+10;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 10010

/*int dp[maxn][1010];
typedef pair <int, vi> item;
map <item, int> M;
int nim[maxn], n;

int calcNim(item a)
{
	if (M[a] != NULL) return M[a];
	if (a.e1 == 0) return 0;
	vi sa;
	sa.resize(40, 0);
	int it = 0;
	for (int i=1; i<=a.e1; ++i)
	{
		while (it < (int)a.e2.size() && a.e2[it] < i) ++it;
		if (it < (int)a.e2.size() && a.e2[it] == i) continue;
		vi nowe = a.e2;
		int liczba = a.e1 - i;
		nowe.push_back(i);
		sort(nowe.begin(), nowe.end());
		sa[calcNim(mp(liczba, nowe))]++;
	}

	int sett = 0;
	while (sa[sett] > 0) ++sett;
	M[a] = sett;
	return sett;
}*/
int nimm[3000], AKT = -1, n;
int main()
{
	boost;
	//FOR(i, 1, 30) nim[i] = calcNim(mp(i, empty));
	for (int numer = 0; numer <= 20; ++numer)
	{
		for (int a = 0; a <= numer; ++ a) nimm[++AKT] = numer;
	}

	cin >> n;
	int wyn = 0, boom;
	FOR(i, 1, n) {
		cin >> boom;
		wyn ^= nimm[boom];
	}
	if (wyn > 0) cout << "NO";
	else cout << "YES";
}