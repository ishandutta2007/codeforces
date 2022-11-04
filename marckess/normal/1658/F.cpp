// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
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

const int MX = 200005;
int n, m, acu[MX];
string s;

void main_() {
	cin >> n >> m >> s;
	
	int act = 0;
	for (char c : s) 
		if (c == '1')
			act++;
	
	if (1ll * act * m % n) {
		cout << -1 << endl;
		return;
	}
	
	int tar = 1ll * act * m / n;
	int izq = n, der = -1;
	
	acu[n] = 0;
	for (int i = n - 1; i >= 0; i--) {
		acu[i] = acu[i + 1];
		if (s[i] == '1') {
			acu[i]++;
			izq = min(izq, i);
			der = max(der, i);
		}
	}
	
	for (int i = 0; i + m <= n; i++)
		if (acu[i] - acu[i + m] == tar) {
			cout << 1 << endl << i + 1 << " " << i + m << endl; 
			return;
		}
	
	for (int i = 0; i + (n - m) <= n; i++)
		if (acu[0] - (acu[i] - acu[i + (n - m)]) == tar) {
			cout << 2 << endl;
			
			cout << 1 << " " << i << endl;
			cout << i + (n - m) + 1 << " " << n << endl;
			
			return;
		}
	
	cout << -1 << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}