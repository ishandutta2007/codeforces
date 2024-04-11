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
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int mod = 1e9+7;
const int maxn = 6110;

int n;
string s1, s2;

bool used[maxn];
PII tab[maxn];
int DL = 0;
PII NEWTAB[maxn];
vector <int> res;

void shift(int x)
{
	res.pb(x);
	x = n - x + 1;
	DL = 0;
	for (int i = n; i >= x; --i) NEWTAB[++DL] = tab[i];
	FOR(i, 1, x - 1) NEWTAB[++DL] = tab[i];
	FOR(i, 1, n) tab[i] = NEWTAB[i];
}
PII fixed;

int ILE = 1;
bool check()
{
	for (int i=1; i<=n; ++i)
		if (tab[i].e1 != i - 1) return 0;
	return 1;
}

bool spoko[maxn];

int main()
{
	srand(time(0));
	boost;
	cin >> n >> s1 >> s2;
	/*n = rand()%10 + 1;
	s1 = ""; s2 = "";
	for (int i=1; i<=n; ++i) {
		char zn = rand()%(26);
		zn += 'a';
		s1 += zn;
	}
	s2 = s1;
	random_shuffle(s1.begin(), s1.end());
	cout << s1 << ' ' << s2 << endl;*/
	for (int i=1; i<=n; ++i)
	{
		bool ok = 0;
		for (int j = 1; j <= n; ++j)
		{
			if (ok) break;
			if (tab[j].e1 != 0) continue;
			if (s2[i - 1] == s1[j - 1])
			{
				ok = 1;
				tab[j].e1 = i;
				break;
			}
		}
		if (!ok) OUT(-1);
	}
	
	
	if (n == 1) OUT("0\n");
	//cin >> n;
	//FOR(i, 1, n) cin >> tab[i].e1;
	FOR(i, 1, n) tab[i].e2 = 0;
	FOR(i, 1, n) tab[i].e1--;
	
	if (tab[1].e1 != 0)
	{
		for (int i=2; i<=n; ++i)
			if (tab[i].e1 == 0) 
			{
				if (i != n) shift(n - i);
				shift(n);
			}
	}
	tab[1].e2 = 1;
	spoko[0] = 1;
	while (ILE < n)
	{
		if (tab[1].e2 == 1) //special is at the beginning
			{
				int key = (tab[1].e1 + n - 1) % n;
				if (spoko[key]) key = (tab[1].e1 + 1) % n;
				assert(!spoko[key]);
				
				FOR(i, 1, n)
					if (tab[i].e1 == key)
					{
						++ILE;
						spoko[key] = 1;
						tab[i].e2 = 1;
						shift(n - i + 1);
						break;
					}
					
			}
		else if (tab[n].e2 == 1) //specials are a suffix
			{
				int wh = n;
				while (tab[wh - 1].e2 == 1) --wh;
				shift(n - wh + 1);
			}
		else  //neither a suffix nor a prefix
		{
			int wh = n;
			while (tab[wh - 1].e2 == 0) --wh;
			shift(n - wh + 1);
		}
	}
	
	//cout << "EEEEEND\n";
	//still something to be fixed
	for (int i=1; i<=n; ++i)
	{
		if (tab[i].e1 == 0)
		{
			if (i < n)
			{
				if (tab[i + 1].e1 != 1) shift(n);
			}
			else 
			{
				if (tab[1].e1 != 1) shift(n);
			}
			break;
		}
	}
	
	if (!check())
	{
		for (int i=2; i<=n; ++i)
			if (tab[i].e1 == 0)
			{
				shift(n - i + 1);
				shift(n - (n - i + 1));
				break;
			}
			
		if (!check()) shift(n);
		assert(check());
	}

	
	assert((int)res.size() <= 6100);
	cout << (int)res.size() << "\n";
	for (auto u : res) cout << u << ' ';
}