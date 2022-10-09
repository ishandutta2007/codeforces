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
typedef unsigned int ui;
const ll mod = 1e7+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
int n, m, k, DL = 0, CC = 0, T;

bool isprime(int x){ 
	for (int i=2; i<x; ++i)
	  if (x % i == 0) return 0;
	return 1;
}
bool odp[15];

int main() { 
	boost;
	int ile = 0;string ans = "";
	FOR(i, 2, 10) {
		if (isprime(i)) {
			cout << i << endl;
			cin >> ans;
			if (ans[0] == 'y') {
				odp[i] = 1;
				++ile;
				break;
			}
		}
	}
	
	
	if (ile == 0) OUT("prime");
	if (ile > 1) OUT("composite");
	int dzielnik = 0;
	
	FOR(i, 2, 10) 
	  if (odp[i]) dzielnik = i;

	FOR(i, 2, 100) {
		if (i * dzielnik > 100) break;
			  if (isprime(i)) {
				  cout << i * dzielnik << endl;
			  cin >> ans;
			  if (ans[0] == 'y') OUT("composite");
			}
	  }
	   OUT("prime");
}