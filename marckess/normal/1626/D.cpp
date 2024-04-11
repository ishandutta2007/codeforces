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
int n, a[MX], to[2 * MX], cn[MX];

int f (int x, int y) {
	if (!x || x >= y) return 1e9;
	int res = to[cn[x - 1]];
	res += to[cn[y - 1] - cn[x - 1]];
	res += to[cn[n] - cn[y - 1]];
	return res;
}

void main_() {
	cin >> n;
	
	forn (i, n + 3) {
		cn[i] = 0;
	}
	
	forn (i, n) {
		cin >> a[i];
		cn[a[i]]++;
	}
	sort(a, a + n);
	
	if (n == 1) {
		cout << 2 << endl;
		return;
	}
	
	forr (i, 1, n)
		cn[i] += cn[i - 1];
	
	int k = 1;
	while (k < n)
		k *= 2;
	
	while (k >= 0) {
		if ((k & -k) == k)
			to[k] = 0;
		else
			to[k] = to[k + 1] + 1;
		k--;
	}
	to[0] = 1;
	
	int res = 1e9;
	forn (i, n) {
		int x = a[i];
		
		for (int l = -1; l <= 1; l++) {
			for (int j = 0; i + (1 << j) < n; j++)
				for (int k = -1; k <= 1; k++)
					res = min(res, f(x + l, a[i + (1 << j)] + k));
			
			for (int j = 0; n - (1 << j) > i; j++)
				for (int k = -1; k <= 1; k++)
					res = min(res, f(x + l, a[n - (1 << j)] + k));
		}
	}
	
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