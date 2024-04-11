#include <bits/stdc++.h>

#define forn(i,n) for (int i = 0; i < n; i++)

using namespace std;

const int MX = 100005;
int n, a[MX];

void main_ () {
	cin >> n;
	forn (i, n)
		cin >> a[i];
	
	int x = 0, y = 0;
	forn (i, n) {
		if (a[i] < a[x]) x = i;
		if (a[i] > a[y]) y = i;
	}

	cout << x + 1 << " " << y + 1 << endl;
}

int main () {

	int t;
	cin >> t;
	while (t--)
		main_();
	
    return 0;
}