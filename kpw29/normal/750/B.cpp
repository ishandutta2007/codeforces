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
const int equ = 20000;

int main() {
	boost;
	cin >> n;
	int pos = 0;
	string s;
	while (n--) {
		cin >> m >> s;
		if (s == "East" || s == "West")
		{
			if (pos == 0 || pos == equ) OUT("NO");
		}
		else {
			if (s == "North") {
				if (pos - m < 0) OUT("NO");
				pos -= m;
			}
			if (s == "South") {
				if (pos + m > equ) OUT("NO");
				pos += m;
			}
		}

	}
	
	if (pos == 0) cout << "YES";
	else cout << "NO";
}