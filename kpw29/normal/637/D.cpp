#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define e1 first
#define e2 second
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
#define boost ios_base::sync_with_stdio(0)
typedef long long int ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
const int mod = 100;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 4e18 + 3;
#define maxn 300100
int poz[maxn], n, m, skok, rozbieg;
vector <int> wyskoki, ladowania;

int main()
{
	scanf("%d%d%d%d", &n, &m, &rozbieg, &skok);
	for (int i=1; i<=n; ++i) scanf("%d", &poz[i]);
	sort(poz + 1, poz + n + 1);
	poz[0] = -1;
	for (int i=1; i<=n; ++i)
	  if (poz[i] - 1 - (poz[i-1] + 1) >= rozbieg) wyskoki.pb(poz[i] - 1), ladowania.pb(poz[i-1] + 1);
	  ladowania.pb(poz[n] + 1);
	//for (int i=0; i<wyskoki.size(); ++i) cout << wyskoki[i] << ' ';
	//Czy dla pierwszej pozycji na pewno wyskok jest wyznaczony dobrze ?
	if (wyskoki.size() == 0) OUT("IMPOSSIBLE");
	if (wyskoki[0] != poz[1] - 1) OUT("IMPOSSIBLE");
	for (ui i=0; i<wyskoki.size(); ++i) {
		if (ladowania[i + 1] - wyskoki[i] > skok) OUT("IMPOSSIBLE");
	}
	/*for (ui i=0; i<wyskoki.size(); ++i) printf("LAD: %d WYSK: %d ", ladowania[i], wyskoki[i]);
	printf("%d\n", ladowania[ladowania.size() - 1]);*/
	printf("RUN %d\n", wyskoki[0]);
	for (ui i=0; i<wyskoki.size(); ++i) {
		printf("JUMP %d\n", ladowania[i + 1] - wyskoki[i]);
		if (i != wyskoki.size() - 1) {
			printf("RUN %d\n", wyskoki[i + 1] - ladowania[i + 1]);
		}
		else if (ladowania[i + 1] != m) printf("RUN %d\n", m - ladowania[i + 1]);
	}
	
}