#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 500005;
int n, s[MX];

bool esPos (int m) {
	for (int i = 0, j = m; i < m; i++, j++)
		if (j < n && s[i] < s[j] * 2)
			return 0;
	return 1;
}

int obtRes () {
	int i = (n+1)/2, j = n+1, rep = 20;

	while (rep--) {
		int m = (i+j)/2;
		if (esPos(m)) j = m;
		else i = m;
	}

	if (esPos(i)) return i;
	return j;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];

	sort(s, s+n, greater<int>());

	cout << obtRes() << endl;

	return 0;
}