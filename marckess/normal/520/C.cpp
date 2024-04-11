#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

string s, dna = "ACGT";
int n;

ll pot (ll b, int p, int m) {
	ll res = 1;

	while (p) {
		if (p & 1) {
			res *= b;
			res %= m;
		}

		b *= b;
		b %= m;
		p /= 2;
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	vi c(255);
	int mx = 0, p = 0;

	cin >> n >> s;

	for (char h : s) {
		c[h]++;
		mx = max(mx, c[h]);
	}

	for (char h : dna)
		if (c[h] == mx)
			p++;

	cout << pot(p, n, 1e9+7) << endl;

	return 0;
}