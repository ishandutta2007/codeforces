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
int n, p[MX], res[MX];

void main_() {
	cin >> n;
	forn (i, n)
		cin >> p[i];
	
	vi a, b;
	forn (i, n) {
		char c;
		cin >> c;
		
		if (c == '0') a.pb(i);
		else b.pb(i);
	}
	
	sort(all(a), [&] (int i, int j) {
		return p[i] < p[j];
	});
	sort(all(b), [&] (int i, int j) {
		return p[i] < p[j];
	});
	
	int k = 1;
	for (int i : a)
		res[i] = k++;
	for (int i : b)
		res[i] = k++;
	
	forn (i, n)
		cout << res[i] << " ";
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