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
const int mod = 1000000;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 50100;

int rnd[maxn], arr[maxn], nast[maxn], ans = -1, start, x;
int bestrun, bestval, bestnext;
PII query(int val) {
	cout << "? " << val << endl;
	int nxt, value;
	cin >> value >> nxt;
	//value = arr[val]; nxt = nast[val];
	if (nxt == -1 && value == -1) exit(0);
	return mp(nxt, value);
}

void ask(int val) {
	PII wyn = query(val);
	if (wyn.e2 >= x) {
		if (ans == -1) ans = wyn.e2;
		else ans = min(ans, wyn.e2);
	}
	else {
		if (wyn.e2 > bestval) {
			bestrun = val;
			bestval = wyn.e2;
			bestnext = wyn.e1;
		}
	}
}
int n;
int main()
{
	srand(time(0));
	cin >> n >> start >> x;
	//FOR(i, 1, n) cin >> arr[i];
	//FOR(i, 1, n) cin >> nast[i];
	
	PII help = query(start);
	bestrun = start;
	bestval = help.e2;
	bestnext = help.e1;
	if (bestval >= x) ans = bestval;
	
	FOR(i, 1, n) rnd[i] = i;
	random_shuffle(rnd+1, rnd+n+1);
	FOR(i, 1, min(n, 999)) ask(rnd[i]);
	FOR(i, 1, 999)
	{
		if (bestnext == -1) break;
		ask(bestnext);
	}
	
	cout << "! " << ans << endl;
}