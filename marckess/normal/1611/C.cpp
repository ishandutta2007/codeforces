
// Problem : C. Polycarp Recovers the Permutation
// Contest : Codeforces - Codeforces Round #756 (Div. 3)
// URL : https://codeforces.com/contest/1611/problem/C
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

void main_() {
	int n;
	cin >> n;
	
	vi v(n);
	
	forn (i, n)
		cin >> v[i];
	
	if (v[0] == n) {
		reverse(v.begin() + 1, v.end());
	} else if (v.back() == n) {
		reverse(v.begin(), v.end() - 1);
	} else {
		cout << -1 << endl;
		return;
	}
	
	forn (i, n)
		cout << v[i] << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}