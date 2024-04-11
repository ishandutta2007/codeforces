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
int n, m, k, a, b, c;
#define maxn 1001000
int tab[maxn], t[maxn], DL, people, keys, pos;
vi small, big;

inline int odl(int a, int b) {
	return abs(a - b);
}
int main()
{
	boost;
	cin >> people >> keys >> pos;
	FOR(i, 1, people) cin >> tab[i];
	sort(tab+1, tab+people+1);
	FOR(i, 1, keys)
	{
		cin >> a;
		if (a >= pos) big.pb(a);
		else small.pb(a);
	}
	sort(small.begin(), small.end());
	sort(big.begin(), big.end());
	reverse(small.begin(), small.end());
	int res = 2100 * 1000 * 1000;
	for (int i=0; i<=people; ++i)
	{
		int tu = i, tam = people - i;
		int tmp = 0;
		if (tu > (int)small.size() || tam > (int)big.size()) continue;
		DL = 0;
		FOR(j, 1, tu) t[++DL] = small[j - 1];
		FOR(j, 1, tam) t[++DL] = big[j - 1];
		sort(t+1, t+DL+1);
		FOR(j, 1, people) tmp = max(tmp, odl(t[j], tab[j]) + odl(t[j], pos));
		res = min(res, tmp);
	}
	
	cout << res;
}