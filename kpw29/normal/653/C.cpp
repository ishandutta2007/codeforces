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
typedef pair <ll, int> PLI;
typedef vector <int> vi;
typedef unsigned int ui;
const int inf = 2e9+9091203;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
const int BASE=10000;
int n, m, b,a, c, k;
#define maxn 150100
int t[maxn];
vector <PII> wyn;
bool correct(int x) {
	if (x == 0 || x == n + 1) return 1;
	if (x % 2 == 0) {
		if (t[x-1] < t[x] && t[x + 1] < t[x]) return 1;
	}
	else {
		if (t[x-1] > t[x] && t[x + 1] > t[x]) return 1;
	}
	return 0;
}
int space = 0;

void check(int a, int b) {
	if (a > b) swap(a, b); //a jest mniejsze
	if (a < 1 || b < 1 || a == b || a > n || b > n) return;
	int sum = correct(a-1) + correct(a) + correct(a+1);
	if (b - 1 > a + 1) sum += correct(b - 1);
	if (b > a + 1) sum += correct(b);
	if (b + 1 > a) sum += correct(b + 1);
	swap(t[a], t[b]);
	int dum = correct(a-1) + correct(a) + correct(a+1);
	if (b - 1 > a + 1) dum += correct(b - 1);
	if (b > a + 1) dum += correct(b);
	if (b + 1 > a) dum += correct(b + 1);
	swap(t[a], t[b]);
	if (-space + dum - sum == 0) wyn.pb(mp(a, b));
}

int main()
{
	boost;
	cin >> n;
	for (int i=1; i<=n; ++i) cin >> t[i];
	t[0] = inf;
	if (n % 2 == 1) t[n+1] = inf;
	else t[n+1] = 0;
	

	for (int i=1; i<=n; ++i) {
		if (!correct(i)) space++;	
	}

	for (int i=1; i<=n; ++i) {
		if (!correct(i)) {
			for (int j=1; j<=n; ++j) check(i, j);
			for (int j=1; j<=n; ++j) check(i+1, j);
			for (int j=1; j<=n; ++j) check(i-1, j);
			break;
		}
	}
	//for (auto it : wyn) cout << it.e1 << ' ' << it.e2 << endl;
	sort(wyn.begin(), wyn.end());
	if (wyn.size() == (int)0) OUT(0);
	int res = 1;
	for (int i=1; i<wyn.size(); ++i)
	  if (wyn[i] != wyn[i-1]) ++res;
	cout << res;
}