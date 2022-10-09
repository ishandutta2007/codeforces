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
const int inf =1e9+9;
const ll mod = 1e9+9;
const ll MOD = 1e9+696969;
int n, m, k, a, b, DL = 0, CC = 0, T;
#define maxn 2010
int MIN[maxn];
int readint[maxn];
bool jest[maxn];
int arr[10][10];

void ask(vector <int> &v) {
	FOR(i, 1, n) jest[i] = 0;
	cout << (int)v.size() << endl;
	for (auto u : v) {
		cout << u << ' '; 
		jest[u] = 1;
	}
	cout << endl;
	fflush(stdout);
	
	FOR(i, 1, n) cin >> readint[i];
	/*FOR(i, 1, n) {
		int M = inf;
		for (auto u : v) M = min(M, arr[i][u]);
		readint[i] = M;
	}
	*/
	/*cout << "ANSWER: " << endl;
	FOR(i, 1, n) cout << readint[i] << ' ';*/
}


int main() {
	/*arr[1][2] = 3; arr[1][3] = 2;
	arr[2][1] = 5; arr[2][3] = 7;
	arr[3][1] = 4; arr[3][2] = 8;*/ //arr[1][2] = 0; arr[2][1] = 0;
	cin >> n;
	FOR(i, 1, n) MIN[i] = inf;
	int pot = 1;
	vector <int> asks;
	int LOG = 0;
	while (pot < n) pot *= 2, LOG++;
	for (int kk=1; kk<=LOG; ++kk) {
		asks.clear();
		FOR(i, 1, n)
		  if (((i-1) & (1 << (LOG-kk))) == 0) asks.pb(i);
		
		ask(asks);
		FOR(i, 1, n) {
			if (!jest[i]) MIN[i] = min(MIN[i], readint[i]);
		}
		
		asks.clear();
		FOR(i, 1, n)
		  if (((i-1) & (1 << (LOG-kk))) > 0) asks.pb(i);
		ask(asks);
		FOR(i, 1, n) {
			if (!jest[i]) MIN[i] = min(MIN[i], readint[i]);
		}
		asks.clear();
		
	}
	
	cout << "-1" << endl;
	FOR(i, 1, n) cout << MIN[i] << ' ';
	cout << endl;
}