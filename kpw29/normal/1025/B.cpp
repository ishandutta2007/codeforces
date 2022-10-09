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
int n, m, k, a, b, c;
int ile[30];
const int maxn = 200100;
int A[maxn], B[maxn];
bool prime[100100];

void check(int x)
{
	FOR(i, 1, n)
	{
		if (A[i] % x > 0 && B[i] % x > 0) return;
	}
	
	OUT(x);
}

int main()
{
	boost;
	string s;
	cin >> n;
	FOR(i, 1, n) cin >> A[i] >> B[i];
	FOR(i, 1, 100000) prime[i] = true;
	FOR(i, 2, 100000)
		for (int j=i+i; j<=100000; j+=i) prime[j] = false;
	
	vector <int> divs;
	int help = A[1];
	FOR(i, 2, 100000)
	{
		if (prime[i] == false) continue;
		if (help % i == 0)
		{
			divs.pb(i);
			while (help % i == 0) help /= i;
		}
	}
	
	if (help > 1) divs.pb(help);
	help = B[1];
	FOR(i, 2, 100000)
	{
		if (prime[i] == false) continue;
		if (help % i == 0)
		{
			divs.pb(i);
			while (help % i == 0) help /= i;
		}
	}
	if (help > 1) divs.pb(help);
	for (auto u : divs) check(u);
	cout << "-1";
}