#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
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
#define maxn 1000100
int n;
ll b[maxn], c[maxn], sumOfAll;

ll a[maxn];

ll cnt[35];

int main() {
	boost;
	cin >> n;

	ll sum = 0;
	FOR(i,1, n) cin >> b[i], sum += b[i];
	FOR(i, 1, n) cin >> c[i], sum += c[i];
	if (n == 1) {
		if (b[1] == c[1]) OUT(b[1]);
		OUT(-1);
	}

	ll r = (2 * n);
	if (sum % r != 0) OUT(-1);
	sum /= r;

	FOR(i, 1, n) {
		ll ile = b[i] + c[i];
		ile -= sum;
		if (ile < 0) OUT(-1);
		if (ile % n != 0) OUT(-1);
		a[i] = (ile / n);
	}
	
	FOR(i, 1, n) {
		FOR(j, 0, 30)
		  if ((1 << j) & a[i]) cnt[j]++;
	}
	
	FOR(i, 1, n) {
		ll AND = 0, OR = 0;
		
		FOR(j, 0, 30)
		  if ((1<<j) & a[i]) AND += (1LL << j) * cnt[j];
		
		FOR(j, 0, 30) 
		  if ((1<<j) & a[i]) OR += (1LL << j) * n;
		  else OR += (1LL << j) * cnt[j];
		if (AND != b[i]) OUT(-1);
		if (OR != c[i]) OUT(-1);	
	}
	
	FOR(i, 1, n) cout << a[i] << ' ';
}