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
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <int, int> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef vector <int> vi;
typedef unsigned int ui;
//const int mod = 998244353;
const int mod = 1e9+7;
#define maxn 1000100
int n, m, k, a, b, c;
int tab[maxn];

int main() {
	boost;
	cin >> n >> k;
	int spare = 4 * 60 - k;
	int wyn = 0;
	FOR(i, 1, n) {
		if (5 * i <= spare) {
			spare -= 5 * i;
			++wyn;
		}
		else OUT(wyn);
	}
	cout << wyn;
}