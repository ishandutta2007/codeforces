
// Problem : B. Shifting Sort
// Contest : Codeforces - Codeforces Round #744 (Div. 3)
// URL : https://codeforces.com/contest/1579/problem/B
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

const int MX = 55;
int n, a[MX], b[MX];
vvi res;

void main_() {
	cin >> n;
	forn (i, n) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a, a + n);
	
	res.clear();
	forn (i, n)
		if (a[i] != b[i]) {
			int k = i;
			while (a[i] != b[k])
				k++;
			
			res.pb({i + 1, k + 1, k - i});
			
			while (k > i) {
				swap(b[k - 1], b[k]);
				k--;
			}
		}
	
	cout << res.size() << endl;
	for (vi &r : res)
		cout << r[0] << " " << r[1] << " " << r[2] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}