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
int n;
vvi a;

bool esPos (int m) {
	int mx = 0;
	for (int i = 0; i <= m; i++)
		mx = max(mx, a[i][1]);
	
	int i = m + 1, j = m + 1;
	while (j < n) {
		if (a[j][1] < mx) {
			while (i <= j) {
				mx = max(mx, a[i][1]);
				i++;
			}
		}
		j++;
	}
	
	return i == n;
}

void main_() {
	cin >> n;
	a = vvi(n, vi(3));
	
	forn (i, n) cin >> a[i][0];
	forn (i, n) cin >> a[i][1];
	forn (i, n) a[i][2] = i;
	
	sort(all(a));
	
	int i = 0, j = n - 1, rep = 20;
	while (rep--) {
		int m = (i + j) / 2;
		if (esPos(m)) j = m;
		else i = m;
	}
	
	vi res(n);
	while (j < n) {
		res[a[j][2]] = 1;
		j++;
	}
	
	for (int x : res)
		cout << x;
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