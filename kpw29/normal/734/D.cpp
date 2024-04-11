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

ll n, m, k;
#define maxn 1000100
ll x, y, xx, yy;
typedef pair <ll, int> PLI;

set <PLI> iks, igrek, ukos1, ukos2;

int main() {
	boost;
	cin >> n >> x >> y;
	iks.insert({INF, 0});
	iks.insert({-INF, 0});
	igrek.insert({INF, 0});
	igrek.insert({-INF, 0});
	ukos1.insert({INF, 0});
	igrek.insert({-INF, 0});
	ukos2.insert({INF, 0});
	igrek.insert({-INF, 0});
	
	iks.insert({x, 0});
	igrek.insert({y, 0});
	ukos1.insert({y, 0});
	ukos2.insert({y, 0});
	
	FOR(i, 1, n) {
		char zn;
		int type;
		cin >> zn >> xx >> yy;
		if (zn == 'R') type = 1;
		if (zn == 'B') type = 2;
		if (zn == 'Q') type = 3;
		if (yy == y) iks.insert({xx, type});
		if (xx == x) igrek.insert({yy, type});
		if (x+y == xx+yy) ukos1.insert({yy, type});
		if (x-y == xx-yy) ukos2.insert({yy, type});
		
	}
	
	//solve in 8 directions
	set <PLI>::iterator it = iks.lower_bound({x, 0});
	++it;
	if ((*it).e2 & 1) OUT("YES");
	
	it = iks.lower_bound({x, 0});
	--it;
	if ((*it).e2 & 1) OUT("YES");
	
	it = igrek.lower_bound({y, 0});
	++it;
	if ((*it).e2 & 1) OUT("YES");
	
	it = igrek.lower_bound({y, 0});
	--it;
	if ((*it).e2 & 1) OUT("YES");
	
	
	
	it = ukos1.lower_bound({y, 0});
	++it;
	if ((*it).e2 & 2) OUT("YES");
	
	it = ukos1.lower_bound({y, 0});
	--it;
	if ((*it).e2 & 2) OUT("YES");
	
	it = ukos2.lower_bound({y, 0});
	++it;
	if ((*it).e2 & 2) OUT("YES");
	
	it = ukos2.lower_bound({y, 0});
	--it;
	if ((*it).e2 & 2) OUT("YES");
	
	cout << "NO";
}