#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000100
int n, m, a, b, c;
ll value[28];
map <ll, int> cnt;
char s[maxn];

ll pref[maxn];
vector <int> wyst[27];

int main()
{
	for (int i=0; i<26; ++i) cin >> value[i];
	scanf("%s", s+ 1);
	int n = 1;
	while (s[n]) ++n; --n;
	for (int i=1; i<=n; ++i)
	  wyst[s[i] - 'a'].pb(i);

	ll sum = 0, wyn = 0;
	for (int i=1; i<=n; ++i)
	{
		sum += value[s[i] - 'a'];
		pref[i] = sum;
	}
	//for (int i=1; i<=n; ++i) cout << pref[i] << ' ';
	//cout << endl;
	for (int i=0; i<26; ++i)
	{
		cnt.clear();
		for (int j=wyst[i].size()-1; j>=0; --j)
		  cnt[pref[wyst[i][j]]]++;

		for (ui j=0; j<wyst[i].size(); ++j)
		{
			int akt = wyst[i][j];
			cnt[pref[akt]]--;
			wyn += cnt[pref[akt] + value[i]];
		}
	}
	
	cout << wyn;
}