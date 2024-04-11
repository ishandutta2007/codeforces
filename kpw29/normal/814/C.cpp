#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef unsigned int ui;
typedef vector <int> vi;
const ll mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000100
string s;
int n;

inline int answer(int x, char zn)
{
	int ret = 0, need = 0, j = -1;
	FOR(i, 0, n -1)
	{
		while (j < n && need <= x) {
			++j;
			if (s[j] != zn) ++need;
		}
		if (s[j] != zn) --need;
		--j;
		ret = max(ret, j - i + 1);
		if (s[i] != zn) --need;
	}
	return ret;
}

int main()
{
	boost;
	cin >> n;
	cin >> s;
	s += "$";
	int zap, a;
	cin >> zap;
	char zn;
	while (zap--) {
		cin >> a  >> zn;
		cout << answer(a, zn) << "\n";
	}
}