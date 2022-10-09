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
const ll INF = 1e18;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int maxn = 1000100;
int n, m, k;
int tab[maxn];
int s;
#include <random>

typedef std::mt19937 rng_type;
std::uniform_int_distribution<rng_type::result_type> udist(0, INT_MAX);

rng_type rng;

int myrandom()
{
  rng_type::result_type random_number = udist(rng);
  return random_number;
}

inline int random(int a, int b) {
	return a + myrandom()%(b-a+1);
}

const int C = 100;
const int D = 1;
int avPetr = 0, avAlex = 0;

int evaluate()
{
	int ret = 0;
	FOR(i, 1, n)
		if (tab[i] == i) ++ret;
	return ret;
}

void genPetr()
{
	FOR(i, 1, n) tab[i] = i;
	FOR(i, 1, 3 * n)
	{
		int a = random(1, n), b = a;
		while (b == a) b = random(1, n);
		swap(tab[a], tab[b]);
	}
	avPetr += evaluate();
}

void genAlex()
{
	FOR(i, 1, n) tab[i] = i;
	FOR(i, 1, 7 * n + 1)
	{
		int a = random(1, n), b = a;
		while (b == a) b = random(1, n);
		swap(tab[a], tab[b]);
	}
	avAlex += evaluate();
}

int main()
{
	rng_type::result_type const seedval = 2137;
	rng.seed(seedval);
	boost;
	cin >> n;
	if (n == 5) OUT("Petr");
	FOR(i, 1, 2 * D)
	{
		if (i <= D) genPetr();
		else genAlex();
	}
	FOR(i, 1, n) cin >> tab[i];
	ll ev = evaluate();
	//if (n == 1000000) cout << avAlex << ' ' << avPetr << endl;
	if (abs(D * ev - avAlex) < abs(D * ev - avPetr)) cout << "Um_nik";
	else cout << "Petr";
}