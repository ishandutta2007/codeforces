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

const int MX = 100005;
int n, res[MX], a[MX];

void main_() {
	cin >> n;
	forn (i, n)	
		cin >> a[i];
	sort(a, a + n);
	
	if (n % 2) {
		cout << "NO" << endl;
		return;
	}
	
	int i = 0, j = n / 2;
	forn (k, n) {
		if (k % 2) res[k] = a[j++];
		else res[k] = a[i++];
	}
	
	forn (i, n) {
		int f = res[i] > res[MOD(i - 1, n)] && res[i] > res[MOD(i + 1, n)];
		int g = res[i] < res[MOD(i - 1, n)] && res[i] < res[MOD(i + 1, n)];
		
		if (!f && !g) {
			cout << "NO" << endl;
			return;
		}
	}
	
	cout << "YES" << endl;
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