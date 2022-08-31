#include <bits/stdc++.h>
using namespace std;


int a[3], b=0;
int m=-1, x=0, y=0;

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	string s;
	cin >> s;
	int n = s.size();
	for (int i=0, j=n-1; i<j; i++, j--)
		swap(s[i], s[j]);
	for (int i=0; i<n; ++i)
		s[i] -= '0';

	for (int i=0; i<n; ++i) {
		b = (b + s[i]) % 3;
		if (!s[i]) {
			a[s[i] % 3]++;
			continue;
		}
		if (b == 0)
			m = i, x = 0, y = 0;
		if (b == 1) {
			if (a[1] >= 1 && i-1 > m-x-y)
				m = i, x = 1, y = 0;
			if (a[2] >= 2 && i-2 > m-x-y)
				m = i, x = 0, y = 2;	 
		}
		if (b == 2) {
			if (a[1] >= 2 && i-2 > m-x-y)
				m = i, x = 2, y = 0;
			if (a[2] >= 1 && i-1 > m-x-y)
				m = i, x = 0, y = 1;	 
		}
		a[s[i] % 3]++;
	}
	if (m == -1) {
		for (int i=0; i<n; ++i)
			if (!s[i]) {
				cout << "0\n";
				return 0;
			}
		cout << "-1\n";
	}
	else {
		cout << char('0'+s[m]);
		for (int i=m-1; i>=0; --i) {
			if (s[i]%3==0) cout << char('0'+s[i]);
			if (s[i]%3==1) if (!x) cout << char('0'+s[i]); else --x;
			if (s[i]%3==2) if (!y) cout << char('0'+s[i]); else --y;
		}
	}



	return 0;
}