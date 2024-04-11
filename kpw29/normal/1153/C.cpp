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
const int maxn = 300100;

char s[maxn];
int n, otw, zam, znaki, no, nz;
char nowe[maxn];

bool ok()
{
	int score = 0;
	FOR(i, 1, n-1)
	{
		score += nowe[i] == ')'? -1 : 1;
		if (score <= 0) return false;
	}
	
	score += nowe[n] == ')'? -1 : 1;
	if (score == 0) return true;
	else return false;
}

void below()
{
	int cnt = 0;
	FOR(i, 1, n)
	{
		if (s[i] != '?') nowe[i] = s[i];
		else {
			if (cnt < nz) nowe[i] = ')';
			else nowe[i] = '(';
			++cnt;
		}
	}
	
	if (ok())
	{
		printf("%s", nowe + 1);
		exit(0);
	}
}

void up()
{
	int cnt = 0;
	FOR(i, 1, n)
	{
		if (s[i] != '?') nowe[i] = s[i];
		else 
		{
			if (cnt < no) nowe[i] = '(';
			else nowe[i] = ')';
			++cnt;
		}
	}
	
	if (ok())
	{
		printf("%s", nowe + 1);
		exit(0);
	}
}

int main()
{
	scanf("%d%s", &n, s+1);
	if (n % 2 != 0) OUT(":(");
	FOR(i, 1, n) {
		if (s[i] == '?') ++znaki;
		if (s[i] == '(') ++otw;
		if (s[i] == ')') ++zam;
	}
	no = (zam - otw + znaki) / 2;
	nz = znaki - no;
	up();
	OUT(":(");
}