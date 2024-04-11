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
const int maxn = 401000;
int n, m, k, a, b, c, sum;
bool primes[maxn];

int main()
{
	/*R(i, 0, maxn=1) primes[i] = true;
	primes[0] = primes[1] = false;
	FOR(i, 2, n)
		if (primes[i])
			for (int j=i+i; j<maxn; j+=i) primes[j] = false;
	*/
	boost;
	cin >> n;
	int ones = 0, twos = 0;
	FOR(i, 1, n) {
		cin >> a;
		sum += a;
		if (a ==2)++twos;
		else ++ones;
	}
	
	if (ones==0) {
		FOR(i, 1, n) cout << "2 ";
		exit(0);
	}
	else if (twos == 0) {
		FOR(i, 1, n) cout << "1 ";
		exit(0);
	}
	else {
		cout << "2 1 ";
		FOR(i, 1, twos - 1) cout << "2 ";
		FOR(i, 1, ones - 1) cout << "1 ";
	}
	
}