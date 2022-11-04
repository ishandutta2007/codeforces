// Problem : D. Expression Evaluation Error
// Contest : Codeforces - Codeforces Round #742 (Div. 2)
// URL : https://codeforces.com/contest/1567/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

const int MX = 105;
int n, s, pot[10];
string res[MX];

void solve () {
	cin >> s >> n;
	
	forn (i, n)
		res[i] = string(10, '0');
	
	int f = n, j = 0;
	for (int i = 9; i >= 0; i--) {
		for (int k = s / pot[i]; k > 0; k--)
			if (s - k * pot[i] >= f - k) {
				f -= k;
				s -= k * pot[i];
				
				int a = k / n;
				int b = k % n;
				
				forn (l, n)
					if (l < b) {
						res[j][i] = a + 1 + '0'; 
						(j += 1) %= n;
					} else if (a) {
						res[j][i] = a + '0';
						(j += 1) %= n;
					}
				
				break;
			}
	}
	
	forn (i, n) {
		reverse(all(res[i]));
		cout << stoi(res[i]) << " ";
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	pot[0] = 1;
	for (int i = 1; i < 10; i++)
		pot[i] = 10 * pot[i - 1];
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}