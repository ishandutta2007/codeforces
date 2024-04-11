#include <bits/stdc++.h>

#define forn(i,n) for (int i = 0; i < n; i++)

using namespace std;

typedef long long ll;

ll n;

void main_ () {
	cin >> n;
	n *= 2;

	ll res = 1;
	while (n % 2 == 0) {
		n /= 2;
		res *= 2;
	}

	if (n == 1) {
		cout << -1 << endl;
		return;
	}

	cout << min(res, n) << endl;
}

int main () {

	int t;
	cin >> t;
	while (t--)
		main_();
	
    return 0;
}