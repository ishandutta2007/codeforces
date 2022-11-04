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
	
int n, m, q, a[100005], b[100005], l, r, x;
int k = 0, s = 0;
ll sum[100005], aa = 0, ab = 0, off = 0;

ll obtRes () {
	int ind = upper_bound(sum, sum+s, -off) - sum;
	ll res = 1e18;

	if (ind < s)
		res = abs(sum[ind] + off);

	ind--;
	if (ind >= 0)
		res = min(res, abs(sum[ind] + off));

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> q;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int j = 0; j < m; j++)
		cin >> b[j];

	for (int i = 0; i < n; i++)
		if (i % 2 == 0)
			aa += a[i];
		else
			aa -= a[i];

	while (k < n) {
		if (k % 2 == 0)
			ab -= b[k];
		else
			ab += b[k];
		k++;
	}

	sum[s++] = aa + ab;
	while (k < m) {
		if (k % 2 == 0)
			ab -= b[k];
		else
			ab += b[k];

		if ((k-n) % 2 == 0)
			ab += b[k-n];
		else
			ab -= b[k-n];

		if ((k-n) % 2 == 0)
			sum[s++] = aa - ab;
		else
			sum[s++] = aa + ab;

		k++;
	}
	sort(sum, sum+s);

	cout << obtRes() << endl;

	while (q--) {
		cin >> l >> r >> x;
		l--, r--;

		if (l % 2 == r % 2)
			if (l % 2 == 0)
				off += x;
			else
				off -= x;
	
		cout << obtRes() << endl;
	}


	return 0;
}