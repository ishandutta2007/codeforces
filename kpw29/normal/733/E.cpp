#include <bits/stdc++.h>
#include <string>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned int ull;
typedef pair <int, int> PII;
typedef pair <PII, int> PPI;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
typedef unsigned int ui;
const int inf = 1e9+9;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;

int n,m,k,a,b,c;
#define maxn 1000100
string s;
int t[maxn];
ll wyn[maxn];

ll pref1[maxn], suf0[maxn];
int zer[maxn], jed[maxn];
int DL = 0, D0;

int main()
{
	boost;
	cin >> n;
	cin >> s;
	n = s.size();
	FOR(i, 0, n-1)
	if (s[i] == 'U') t[i + 1] = 1;
	else t[i + 1] = 0;
	
	t[0] = 1; t[n + 1] = 0;
	FOR(i, 1, n)
	{
		jed[i] = jed[i-1];
		if (t[i] == 1) {
			jed[i]++;
			++DL;
			pref1[DL] = pref1[DL - 1] + i;
		}
	}
	for (int i=n; i>0; --i)
	{
		zer[i] = zer[i + 1];
		if (t[i] == 0) {
			zer[i]++;
			++D0;
			suf0[D0] = suf0[D0 - 1] + i;
		}
	}
	
	FOR(i, 1, n) {
		ll sum = 0;
		if (t[i] == 1) {
			//zaczynamy od tego ze idziemy w prawo
			if (jed[i-1] < zer[i + 1]) {
				ll kurs = jed[i-1] + 1;
				sum += 2 * (suf0[zer[i + 1]] - suf0[zer[i + 1] - kurs] - kurs * i);
				sum += 2 * ((kurs-1) * i - pref1[kurs - 1]);
				sum += i;
			}
			else {
				ll kurs = zer[i + 1];
				sum += 2 * (suf0[kurs] - kurs * i);
				sum += 2 * ((kurs) * i - (pref1[jed[i - 1]] - pref1[jed[i-1] - (kurs)]));
				sum += (n - i + 1);
			}
			
		}
		else {
			//zaczynamy od tego ze idziemy w lewo
			if (jed[i-1] <= zer[i + 1]) {
				ll kurs = jed[i-1];
				sum += 2 * (suf0[zer[i + 1]] - suf0[zer[i + 1] - kurs] - kurs * i);
				sum += 2 * ((kurs) * i - pref1[kurs]);
				sum += i;
			}
			else {
				ll kurs = zer[i + 1];
				sum += 2 * (suf0[kurs] - kurs * i);
				sum += 2 * ((kurs + 1) * i - (pref1[jed[i - 1]] - pref1[jed[i-1] - (kurs + 1)]));
				sum += (n - i + 1);
			}
		}
		
		cout << sum << ' ';
	}
}