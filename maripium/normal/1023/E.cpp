#include <bits/stdc++.h>
using namespace std;

int n;
int query(int r1,int c1,int r2,int c2) {
	cout << '?' << ' ' << r1 << ' ' << c1 << ' ' << r2 << ' ' << c2 << '\n';
	string res; cin >> res;
	return res == "YES";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	int r = 1, c = 1;
	string fir, sec;
	for (int i = 1; i < n; ++i) {
		if (query(r, c + 1, n, n)) {
			fir += 'R';
			c++;
		}
		else {
			fir += 'D';
			r++;
		}
	}
	r = n, c = n;
	for (int i = 1; i < n; ++i) {
		if (query(1, 1, r - 1, c)) {
			sec += 'D';
			r--;
		}
		else {
			sec += 'R';
			c--;
		}
	}
	reverse(sec.begin(), sec.end());
	string res = fir + sec;
	cout << '!' << ' ' << res;
}