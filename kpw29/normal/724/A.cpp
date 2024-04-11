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
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
int n, m, k, a, b, c, T;
map <string, int> val;

int main() {
	val["monday"] = 1;
	val["tuesday"] = 2;
	val["wednesday"] = 3;
	val["thursday"] = 4;
	val["saturday"] = 6;
	val["sunday"] = 0;
	val["friday"] = 5;
	string F, S;
	cin >> F >> S;
	int a = val[F], b = val[S];
	if (a == b) OUT("YES");
	if ((a + 3) % 7 == b) OUT("YES");
	if ((a + 2) % 7 == b) OUT("YES");
	OUT("NO");
}