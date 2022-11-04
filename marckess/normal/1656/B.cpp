#include <bits/stdc++.h>

#define forn(i,n) for (int i = 0; i < n; i++)

using namespace std;

const int MX = 200005;
int n, k, a[MX];

void main_ () {
	cin >> n >> k;
	
	set<int> st;
	forn (i, n) {
		cin >> a[i];
		st.insert(a[i]);
	}

	forn (i, n)
		if (st.count(k + a[i])) {
			cout << "yes" << endl;
			return;
		}
	
	cout << "no" << endl;
}

int main () {

	int t;
	cin >> t;
	while (t--)
		main_();
	
    return 0;
}