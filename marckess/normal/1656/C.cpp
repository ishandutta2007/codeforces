#include <bits/stdc++.h>

#define forn(i,n) for (int i = 0; i < n; i++)

using namespace std;

const int MX = 200005;
int n, k, a[MX];

void main_ () {
	cin >> n;
	set<int> st;
	forn (i, n) {
		cin >> a[i];
		st.insert(a[i]);
	}

	if (!st.count(1)) {
		cout << "yes" << endl;
		return;
	}

	if (st.count(0) || st.count(2)) {
		cout << "no" << endl;
		return;
	}

	for (int x : st)
		if (st.count(x + 1)) {
			cout << "no" << endl;
			return;
		}
	
	cout << "yes" << endl;
}

int main () {

	int t;
	cin >> t;
	while (t--)
		main_();
	
    return 0;
}