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
typedef pair <ll, int> PLI;
typedef vector <int> vi;
typedef unsigned int ui;
const int inf = 2e9+9091203;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
const int BASE=10000;
int n, m, b, c, k;
#define maxn 1001100
int goal[5];
int pref[maxn];
char s[maxn];
bool check(int dl)
{
//	printf("%d\n", dl);
	for (int i=1; i<=n; ++i)
	{
		int sum = 0;
		if (i - dl - 1 < 0) sum = pref[i + dl];
		else sum = pref[i + dl] - pref[i - dl - 1];
		//printf("i, dl, sum, %d %d K: %d %d\n", i, dl,k,  sum);
		if (sum > k && s[i] == '0') return 1;
	}
	//printf("NIE UDALO SIE: %d", dl);
	return 0;
}
int main()
{
	/*char a;
	int tab[5], DL = 0;
	for (int i=1; i<=2; ++i)
	  for (int j=1; j<=2; ++j) scanf(" %c", &a), tab[++DL] = a;
	if (tab[4] == 'X') swap(tab[3], tab[4]);
	if (tab[3] == 'X') swap(tab[1], tab[3]);
	if (tab[2] == 'X') swap(tab[2], tab[1]);
	
	  DL = 0;
	for (int i=1; i<=2; ++i)
	  for (int j=1; j<=2; ++j) scanf(" %c", &a), goal[++DL] = a;

	for (int steps = 0; steps < 1000000; ++steps) {
		int r = rand()%4;
		if (r == 0) swap(goal[1], goal[2]);
		if (r == 0) swap(goal[2], goal[4]);
		if (r == 0) swap(goal[4], goal[3]);
		if (r == 0) swap(goal[3], goal[1]);
	bool b1 = 1;
	for (int i=1; i<=4; ++i)
	  if (tab[i] != goal[i]) b1 = 0;
	  if (b1) OUT("YES");
  }
	OUT("NO");*/
	scanf("%d%d", &n, &k);
	scanf("%s", s + 1);
	int MAX = n / 2;
	int x = 0, y = n;
	pref[0] = 0;
	for (int i=1; i<=n; ++i)
	{
		pref[i] = pref[i-1];
		if (s[i] == '0') pref[i]++;
	}
	for (int i=n+1; i<=n+n+n; ++i) pref[i] = pref[i-1];
	
	
	while (x < y) {
		int sr = ((x +y) >> 1);
		if (check(sr)) y = sr;
		else x = sr + 1;
	}
	cout << x;
}