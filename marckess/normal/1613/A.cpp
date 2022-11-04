
// Problem : A. Long Comparison
// Contest : Codeforces - Educational Codeforces Round 118 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1613/problem/A
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

int x1, x2, p1, p2;

void main_() {
	cin >> x1 >> p1;
	cin >> x2 >> p2;
	
	while (x1 % 10 == 0) {
		x1 /= 10;
		p1++;
	}
	while (x2 % 10 == 0) {
		x2 /= 10;
		p2++;
	}
	
	if (to_string(x1).size() + p1 > to_string(x2).size() + p2) {
		cout << ">";
	}
	if (to_string(x1).size() + p1 < to_string(x2).size() + p2) {
		cout << "<";
	}
	if (to_string(x1).size() + p1 == to_string(x2).size() + p2) {
		if (to_string(x1) > to_string(x2)) cout << ">";
		if (to_string(x1) < to_string(x2)) cout << "<";
		if (to_string(x1) == to_string(x2)) cout << "=";
	}
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