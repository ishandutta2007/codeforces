#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false);}
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
typedef vector <int> vi;
const int mod = 1e9+7;
const int inf = 1e9+10;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
const int W = 1e9;
#define maxn 1000100

int n, m, k, a, b, c, x;
int tab[maxn], jest[2049], nowejest[2077];

int main()
{
	boost;
	cin >> n >> k >> x;
	FOR(i, 1, n) {
		cin >> tab[i];
		jest[tab[i]]++;
	}
	
	FOR(steps, 1, k)
	{
		int alt = 1;
		FOR(j, 0, 1023)
		{
			
			int sz = (jest[j] / 2);
			nowejest[j ^ x] += sz;
			nowejest[j] += sz;
			if (jest[j] % 2 == 1)
			{
				if (alt) nowejest[j ^ x]++;
				else nowejest[j]++;
				alt ^= 1;
			}
		}
		FOR(j, 0, 1023) {
			jest[j] = nowejest[j], nowejest[j] = 0;
			//FOR(kk, 1, jest[j]) cout << j << ' ';
		}
		//cout << endl;
	}
	
	int MIN = 1025, MAX = -1;
	FOR(j, 0, 1023)
		if (jest[j])
		{
			MIN = min(MIN, j);
			MAX = max(MAX, j);
		}
	cout << MAX << ' ' << MIN << endl;
	
}