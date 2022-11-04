#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 2005;
int n, mem[MX][MX][3];
string s;

int dp (int i, int j, int f);

int win (char a, char b, int f) {
	if (a < b) return 2;
	if (a > b) return 0;
	return f;
}

int find (char ant, int i, int j, int f) {
	// Bob toma el primero
	int izq = dp(i + 1, j, win(ant, s[i], f));
	// Bob toma el ultimo
	int der = dp(i, j - 1, win(ant, s[j], f));
	
	return min(izq, der);
}

// f = 2: Alice gana en sufijo
// f = 1: Empate en el sufijo
// f = 0: Bob gana en el sufijo
int dp (int i, int j, int f) {
	if (i > j) return f;
	
	int &res = mem[i][j][f];
	if (res != -1) return res;
	
	// Alice toma el primero
	int izq = find(s[i], i + 1, j, f);
	
	// Alice toma el ultimo
	int der = find(s[j], i, j - 1, f);
	
	return res = max(izq, der);
}

void main_() {
	cin >> s;
	n = s.size();
	
	forn (i, n + 2)
	forn (j, n + 2)
		memset(mem[i][j], -1, sizeof(mem[i][j]));
	
	int res;
	if (n % 2 == 0) {
		res = dp(0, n - 1, 1);
	} else {
		res = 2 - min(dp(1, n - 1, 2), dp(0, n - 2, 2));
	}
	
	if (res == 2) cout << "Alice" << endl;
	else if (res == 1) cout << "Draw" << endl;
	else cout << "Bob" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}