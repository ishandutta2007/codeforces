#include <bits/stdc++.h>
#include <string>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <PII, int> PPI;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1003
int r[maxn], MIN, MAX;
vector <string> v;

string s;
int n;
int main() {
	boost;
	cin >> n;
	MIN = inf;
	FOR(i, 1, n) {
		cin >> r[i];
		MIN = min(MIN, r[i]);
	}
	s = "";
	FOR(i, 1, n) s += '0';
	r[n + 1] = inf;
	r[0] = -1;
	int broken = 0;
	while (1) {
		if (broken) break;
		int MIN = n + 1, MAX = 0;
		FOR(i, 1, n)
		  if (r[MIN] > r[i]) MIN = i;
		  
		FOR(i, 1, n) 
		  if (r[MAX] < r[i]) MAX = i;
		  
		int cntMax = 0, cntMin = 0;
		if (r[MAX] == r[MIN]) break;
		
		FOR(i, 1, n) {
		  if (r[i] == r[MIN]) cntMin++;
		  if (r[i] == r[MAX]) cntMax++;
		}
		int Go = 1;
		if (cntMax == 1 && cntMin == n-1 && r[MAX] == r[MIN] + 1) {
			Go = 0;
			//specialCase
			int sz = v.size() - 1;
			FOR(i, 0, sz-1)
			  if (v[i][MAX - 1] == '0') {
				  v[i][MAX - 1] = '1';
				  r[MAX] = max(0, r[MAX] - 1);
				  broken = 1;
				  break;
			  }
			if (!broken) Go = 1;
		}
		//cout << MAX << endl;
		if (Go) {
			int nd = 0;
			FOR(i, 1, n)
			  if (i != MAX && r[nd] < r[i]) nd = i;
			s[nd-1] = '1';
			s[MAX-1] = '1';
			v.pb(s);
			r[nd] = max(0, r[nd] - 1);
			r[MAX] = max(0, r[MAX] - 1);
			s[nd-1] = '0';
			s[MAX-1] = '0';
		}
		//FOR(i, 1, n) cout << r[i] << ' ';
		//cout << endl;
	}
	
	int Maks = 0;
	FOR(i, 1, n) Maks = max(Maks, r[i]);
	int sz = v.size();
	cout << Maks << endl << sz << endl;
	FOR(i, 0, sz-1) cout << v[i] << "\n";
}