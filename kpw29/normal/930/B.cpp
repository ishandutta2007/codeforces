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
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
typedef long double ld;

const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int mod = 1e9+7;
string s;
long double prob[30];
int ILE[30], ile[30];
int POS[30];

int main()
{
	long double result = 0.0;
	cin >> s;
	int n = s.size();
	for (int i=0; i<n; ++i) ile[s[i] - 'a']++;
	for (int i=0; i<26; ++i)
	{
		char let = i + 'a';
		vector <int> pos;
		for (int j=0; j<n; ++j)
			if (s[j] == let) pos.pb(j);
		if (pos.empty()) continue;
		
		int best = 0;
		for (int poo = 0; poo < n; ++poo)
		{
			FOR(j, 0, 26) ILE[j] = 0;
			for (auto u : pos)
			{
				int ktore = (u + poo)%n;
				ILE[s[ktore] - 'a']++;
			}
			
			int score = 0;
			FOR(j, 0, 26)
			{
				if (ILE[j] == 1) ++score;
			}
			best = max(best, score);
		}
		result += best;
	}

	double wm = result / (double)n;
	cout << fixed;
	cout << setprecision(15);
	cout << wm;
}