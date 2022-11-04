
// Problem : B. Kalindrome Array
// Contest : Codeforces - Codeforces Global Round 17
// URL : https://codeforces.com/contest/1610/problem/B
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

vi a;
bool go (int x) {
	int i = 0, j = int(a.size()) - 1;
	
	while (i < j) {
		if (a[i] == x) i++;
		else if (a[j] == x) j--;
		else if (a[i] != a[j]) return 0;
		else i++, j--;
	}
	
	return 1;
}

void main_() {
	int n;
	
	cin >> n;
	a = vi(n);
	
	forn (i, n)
		cin >> a[i];
	
	int i = 0, j = n - 1;
	while (i < j) {
		if (a[i] != a[j]) {
			if (go(a[i]) || go(a[j])) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
			return;
		}
		i++, j--;
	}
	cout << "YES" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}