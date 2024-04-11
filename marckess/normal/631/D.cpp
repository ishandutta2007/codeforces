#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int n, m, x, y;
ll la[200005], lb[200005], t[200005], p[200005];
char ca[200005], cb[200005]; 
int b[200005];

void obtKPM () {
	int i = 0, j = -1;
	b[0] = -1;

	while (i < m) {
		while (j >= 0 && p[i] != p[j])
			j = b[j];
		i++, j++;
		b[i] = j;
	}
}

ll KMP () {
	ll res = 0;
	int i = 0, j = 0;

	while (i < n) {
		while (j >= 0 && t[i] != p[j])
			j = b[j];
		i++, j++;

		if (j == m) {
			int ind = i - j;
			j = b[j];

			if (ind == 0 || i == n)
				continue;

			if (ca[ind-1] == cb[0] && la[ind-1] >= lb[0] && ca[i] == cb[m+1] && la[i] >= lb[m+1])
				res++;
		}
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	string ss;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> ss;
		ca[i] = ss.back();
		la[i] = stol(ss.substr(0, ss.size() - 2));
	}

	for (int i = 0; i < m; i++) {
		cin >> ss;
		cb[i] = ss.back();
		lb[i] = stol(ss.substr(0, ss.size() - 2));
	}

	x = 0, y = 0;
	char ac = ca[0];
	for (int i = 1; i < n; i++) {
		if (ca[i] == ac) {
			la[x] += la[i];
			la[i] = 0;
		} else {
			x++;
			la[x] = la[i];
			ca[x] = ca[i];
			ac = ca[i];
		}
	}
	n = x + 1;

	ac = cb[0];
	for (int i = 1; i < m; i++) {
		if (cb[i] == ac) {
			lb[y] += lb[i];
			lb[i] = 0;
		} else {
			y++;
			lb[y] = lb[i];
			cb[y] = cb[i];
			ac = cb[i];
		}
	}
	m = y + 1;

	if (m == 1) {
		ll res = 0;
		for (int i = 0; i < n; i++) {
			if (ca[i] == cb[0]) {
				res += max(0LL, la[i] - lb[0] + 1);
			}
		}
		cout << res << endl;
		return 0;
	}

	if (m == 2) {
		ll res = 0;
		for (int i = 0; i < n - 1; i++) {
			if (ca[i] == cb[0] && la[i] >= lb[0] && ca[i+1] == cb[1] && la[i+1] >= lb[1])
				res++;
		}
		cout << res << endl;
		return 0;
	}

	for (int i = 0; i < n; i++)
		t[i] = la[i] * 30 + (ca[i] - 'a');
	for (int i = 1; i < m - 1; i++)
		p[i-1] = lb[i] * 30 + (cb[i] - 'a');
	m -= 2;

	obtKPM();
	cout << KMP() << endl;

	return 0;
}