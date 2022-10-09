#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
#define tysiac 1010
#define milion 1000100
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define OUT(x) { cout << x; return 0; }
#define PRINT(x, y) {printf("%d %d\n", x, y); return;} 
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <ld, ld> PDD;
typedef pair <PII, PII> PP;
typedef pair <ll, int> PLI;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int T, n, m, k, a, b, c;
#define maxn 1010

string cut(string v) {
	string w = "";
	FOR(i, 0, v.size()-1) v[i] %= 2, v[i] += '0';
	int start = 0;
	while (v[start] == '0' && start+1 < v.size()) ++start;
	FOR(i, start, (int)v.size()-1) w+= v[i];
	return w;
}

map <string, int> M;

int main() {
	boost;
	cin >> n;
	FOR(z, 1, n) {
		char zn;
		string s;
		cin >> zn >> s;
		s = cut(s);
		if (zn == '+') M[s]++;
		else if (zn == '-') M[s]--;
		else cout << M[s] << "\n";
	}
}