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
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
int m, k, a, b, c, DL = 0, T;
#define maxn 1000100
int tab[maxn];
string s;
ll n;
int main()
{
	boost;
	cin >> n;
	if (n == 0) OUT("a");
	s = "";
	for (int i='a'; i<='z'; ++i) {
		int ile = 0, wsk = 1;
		while ((ll)ile * (ile + 1) / 2 <= n) ++ile, ++wsk;
		--ile; --wsk;
		n -= ile * (ile + 1) / 2;
		if (wsk > 1) for (int j=1; j<=wsk; ++j) s += (char)i;
	}
	
	cout << s;
	
	
}