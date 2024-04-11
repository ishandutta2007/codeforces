
// Problem : B. Team Composition: Programmers and Mathematicians
// Contest : Codeforces - Codeforces Round #756 (Div. 3)
// URL : https://codeforces.com/contest/1611/problem/B
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

void main_() {
	int a, b, res = 0;
	cin >> a >> b;
	
	if (abs(a - b) >= 2) {
		if (a > b) swap(a, b);
		int x = (b - a) / 2;
		x = min(a, x);
		x = min(b / 3, x);
		
		a -= x;
		b -= 3 * x;
		res = x;
	}
	
	res += min(a, b) / 2;
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}