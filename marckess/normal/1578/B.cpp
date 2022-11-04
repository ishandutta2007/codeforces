
// Problem : A. Windblume Ode
// Contest : Codeforces - Codeforces Round #749 (Div. 1 + Div. 2, based on Technocup 2022 Elimination Round 1)
// URL : https://codeforces.com/contest/1586/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
int n, a[MX];

void main_() {
	cin >> n;
	
	int sum = 0;
	forn (i, n) {
		cin >> a[i];
		sum += a[i];
	}
	
	for (int i = 2; i < sum; i++)
		if (sum % i == 0) {
			cout << n << endl;
			forn (i, n)
				cout << i + 1 << " ";
			cout << endl;
			return;
		}
	
	forn (i, n)
		if (a[i] % 2) {
			cout << n - 1 << endl;
			forn (j, n)
				if (i != j)
					cout << j + 1 << " ";
			cout << endl;
			return;
		}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}