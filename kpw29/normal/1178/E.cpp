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
const ll mod = 1e9+696969;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 1001000;
string s;

int tab[maxn];
int freq[maxn];
int cze[2][3][maxn];
int choice[maxn];
int wyn[maxn];

int main()
{
	string ret = "";
	boost;
	cin >> s;
	int n = s.length();
	FOR(i, 1, n) {
		tab[i] = s[i - 1] - 'a';
		freq[tab[i]]++;
	}
	
	int OPT = 0;
	if (freq[1] > freq[OPT]) OPT = 1;
	if (freq[2] > freq[OPT]) OPT = 2;
	
	int LEFT[maxn], RIGHT[maxn];
	
	FOR(i, 1, n) {
		LEFT[i] = LEFT[i - 1];
		if (tab[i] == OPT) ++LEFT[i];
	}
	
	RIGHT[n + 1] = 0;
	for (int i=n; i>0; --i)
	{
		RIGHT[i] = RIGHT[i + 1];
		if (tab[i] == OPT) ++RIGHT[i];
	}
	
	FOR(i, 1, n)
	{
		cze[0][tab[i]][LEFT[i]]++;
		cze[1][tab[i]][RIGHT[i]]++;
	}
	
	assert(LEFT[n] == RIGHT[1]);
	int gg = LEFT[n] - 1, hf = (gg + 1) / 2;
	FOR(i, 0, hf)
	{
		int c1, c2;
		if (OPT == 0) c1 = 1, c2 = 2;
		if (OPT == 1) c1 = 0, c2 = 2;
		if (OPT == 2) c1 = 0, c2 = 1;
		
		int freq1 = min(cze[0][c1][i], cze[1][c1][i]);
		int freq2 = min(cze[0][c2][i], cze[1][c2][i]);
		
		if (freq1 >= freq2) choice[i] = c1, wyn[i] = freq1;
		else choice[i] = c2, wyn[i] = freq2;
	}
	int curr = 0;
	FOR(i, 1, n)
	{
		int gr = min(RIGHT[i], LEFT[i]);
		if (tab[i] == OPT)
		{
			curr = 0;
			ret += (char)(OPT + 'a');
		}
		else
		{
			if (tab[i] == choice[gr] && curr < wyn[gr])
			{
				++curr;
				ret += (char)(tab[i] + 'a');
			}
			
		}
	}
	
	cout << ret;
	string w = ret;
	reverse(w.begin(), w.end());
	assert(w == ret);
	assert((int)w.length() >= n/2);
}