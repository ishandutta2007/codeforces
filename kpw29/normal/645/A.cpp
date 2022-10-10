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
#define maxn 100100
int goal[5];

int main()
{
	char a;
	int tab[5], DL = 0;
	for (int i=1; i<=2; ++i)
	  for (int j=1; j<=2; ++j) scanf(" %c", &a), tab[++DL] = a;
	  DL = 0;
	for (int i=1; i<=2; ++i)
	  for (int j=1; j<=2; ++j) scanf(" %c", &a), goal[++DL] = a;

	for (int steps = 0; steps < 10000000; ++steps) {
		int r = rand()%4;
		if (r == 0 && (goal[1] == 'X' || goal[2] == 'X') )swap(goal[1], goal[2]);
		if (r == 1 && (goal[2] == 'X' || goal[4] == 'X') )swap(goal[2], goal[4]);
		if (r == 2 && (goal[4] == 'X' || goal[3] == 'X') )swap(goal[4], goal[3]);
		if (r == 3 && (goal[3] == 'X' || goal[1] == 'X')) swap(goal[3], goal[1]);
	bool b1 = 1;
	for (int i=1; i<=4; ++i)
	  if (tab[i] != goal[i]) b1 = 0;
	  if (b1) OUT("YES");
  }
	OUT("NO");
}