#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define e1 first
#define e2 second
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
#define boost ios_base::sync_with_stdio(false)
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long int ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair <int, int> PII;
typedef pair <PII, int> PPI;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
typedef vector <int> vi;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
#define maxn 200100

int jest[maxn], n, m, a, PHI;
vector <int> v[maxn];
int best[maxn], dp[maxn];

inline void countDP(int x)
{
	if (v[x].empty()) dp[x] = -1;
	else
	{
		int res = (int)v[x].size();
		dp[x] = res; best[x] = 0;
		for (int j=x+x; j<=m; j+=x)
			if (dp[j] > 0)
			{
				if (dp[j] + res > dp[x]) dp[x] = dp[j] + res, best[x] = j;
			}
		
	}
}

PLL extgcd(ll a, ll b)
{
	if (b == 0) return {1, 0};
	PLL res = extgcd(b, a%b);
	return {res.e2, res.e1 - (a / b) * res.e2};
}

inline int solve_congr(int x, int y)
{
	if (y == 0) return 0;
	PLL ret = extgcd(x, m);
	ret.e1 %= m;
	ret.e1 *= (ll)y / __gcd(x, m);
	ret.e1 += (ll)m * m;
	ret.e1 %= m;
	return ret.e1;
}



vi repairDP(vi v)
{
	vi ret;
	ret.clear();
	int sz = (int)v.size();
	ret.pb(v[0]);
	for (int i=1; i<sz; ++i) ret.pb(solve_congr(v[i-1], v[i]));
	return ret;
}

int main()
{
	boost;
	cin >> n >> m;
	if (m == 1) OUT("1\n0");
	PHI = 0;
	FOR(i, 1, m-1)
		if (__gcd(i, m) == 1) PHI++;
	FOR(i, 1, n)
	{
		cin >> a;
		jest[a] = 1;
	}
	FOR(i, 0, m-1)
		if (!jest[i]) v[__gcd(m, i)].pb(i);
	
	for (int i=m; i>0; --i)
		if (m % i == 0) countDP(i);
	
	//niekoniecznie zawsze trzeba zaczynac od jedynki, czasem po prostu sie nie da z jedynka, wiec trzeba innym	
	dp[0] = 0;
	int val = 0;

	FOR(i, 1, m)
		if (dp[i] > 0)
		{
			if (dp[i] > dp[val]) val = i;
		}
	
	if (val == 0) OUT("0\n");
	vi final_sequence;
	final_sequence.clear();
	
	while (val != 0)
	{
		for (auto u : v[val]) final_sequence.pb(u);
		val = best[val];
	}
	//for (auto u : final_sequence) cout << u << ' ';
	//cout << endl;
	
	vi output = repairDP(final_sequence);
	cout << (int)output.size() << "\n";
	for (auto u : output) cout << u << ' ';
}