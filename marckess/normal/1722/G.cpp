#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
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
int n, a[MX];

void main_() {
	cin >> n;
	int off = 0;
	if (n % 4 == 1) {
		for (int x : {2, 0, 4, 5, 3})
			a[off++] = x;
	}
	if (n % 4 == 2) {
		for (int x : {4, 1, 2, 12, 3, 8})
			a[off++] = x;
	}
	if (n % 4 == 3) {
		for (int x : {2, 1, 3})
			a[off++] = x;
	}
	
	int act = 16;
	while (off < n)
		a[off++] = act++;
	
	forn (i, n)
		cout << a[i] << " ";
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