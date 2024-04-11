#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int h, a[100005];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	cin >> h;
	for (int i = 0; i <= h; i++)
		cin >> a[i];

	bool f = true;
	for (int i = 0; i < h; i++)
		if (a[i] > 1 && a[i+1] > 1)
			f = false;

	if (f) {
		cout << "perfect" << endl;
		return 0;
	}

	cout << "ambiguous" << endl;

	int c = 1;
	cout << 0 << " ";
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < a[i+1]; j++)
			cout << c << " ";
		c += a[i];
	}
	cout << endl;

	c = 1;
	cout << 0 << " ";
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < a[i+1] - 1; j++)
			cout << c << " ";
		c += a[i];
		cout << c - 1 << " ";
	}
	cout << endl;

	return 0;
}