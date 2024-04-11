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
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
ll n, k;
ll X, Y;
int que;

bool ask(ll x, ll y)
{
	++que;
	assert(que <= 4500);
	cout << x << ' ' << y << endl;
	string ans;
	cin >> ans;
	if (ans == "Yes" && x == y) exit(0);
	return (ans == "Yes");
}

int main()
{
	srand(time(0));
	boost;
	cin >> n >> k;
	X = 1; Y = n;
	while (que <= 4500)
	{
		if (Y - X > 40)
		{
			ll mid = (X + Y) / 2;
			if (ask(X, mid)) Y = mid;
			else X = mid + 1;
			X = max(1LL, X - k);
			Y = min(n, Y + k);
		}
		else
		{
			ll diff = rand()%(Y - X + 1);
			if (ask(X + diff, X + diff)) exit(0);
			X = max(1LL, X - k);
			Y = min(n, Y + k);
		}
	}
}