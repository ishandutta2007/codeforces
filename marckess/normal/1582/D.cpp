
// Problem : D. Vupsen, Pupsen and 0
// Contest : Codeforces - Codeforces Round #750 (Div. 2)
// URL : https://codeforces.com/contest/1582/problem/D
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

const int MX = 100005;
int n, a[MX];

void main_() {
	cin >> n;
	forn (i, n)
		cin >> a[i];
	
	for (int i = 0; i < n - (n % 2) * 3; i += 2)
		cout << a[i + 1] << " " << -a[i] << " ";
	
	if (n % 2) {
		int x = a[n - 3];
		int y = a[n - 2];
		int z = a[n - 1];
		
		if (x != y)
			cout << z << " " << -z << " " << -(x - y) << endl;
		else if (x != z)
			cout << y << " " << -(x - z) << " " << -y << endl;
		else if (y != z)
			cout << -(y - z) << " " << x << " " << -x << endl;
		else
			cout << 1 << " " << 1 << " " << -2 << endl;
	} else {
		cout << endl;
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