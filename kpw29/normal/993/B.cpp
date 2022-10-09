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
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
typedef set<int> vi;
vector <PII> v1, v2;
int n, m;
vi number(vector <PII> moje, vector <PII> jego)
{
	set <int> ret;
	for (auto u : moje)
	{
		int ILE1 = 0, ILE2 = 0;
		for (auto v : jego)
		{
			if (v == u) continue;
			if (v.e1 == u.e1 || v.e2 == u.e1) ILE1 = 1;
			if (v.e1 == u.e2 || v.e2 == u.e2) ILE2 = 1;
		}
		if (ILE1 == 0 && ILE2 == 0) continue;
		if (ILE1 == 1 && ILE2 == 1) OUT(-1);
		if (ILE1) ret.insert(u.e1);
		else ret.insert(u.e2);
	}
	
	return ret;
}

int main()
{
	boost;
	cin >> n >> m;
	FOR(i, 1, n) {
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		v1.pb(mp(a, b));
	}
	
	FOR(i, 1, m) { 
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		v2.pb(mp(a, b));
	}

	vi n1 = number(v1, v2), n2 = number(v2, v1);
	if (n1.size() > 1 || n2.size() > 1) OUT(0); //they know but i dont
	if (n1.size() == 1 && n2.size() == 1)
	{
		assert(*n1.begin() == *n2.begin());
		OUT(*n1.begin());
	}
}