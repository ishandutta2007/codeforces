#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef double ld;

using namespace std;

int n, m;
int a[26];

void out(string s, int k) {
	cout << k << "\n";
	for (int i = 0; i < k; ++i) {
		cout << s;
		reverse(s.begin(), s.end());
	}
	cout << "\n";
}

void outj() {
	cout << 0 << "\n";
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < a[i]; ++j)
			cout << (char)('a' + i);
	cout << "\n";
}

void solve0() {
	for (int i = 0; i < 26; ++i)
		if (a[i] % 2 == 1) {
			outj();
			return;
		}
	for (int i = 1; i < n; ++i) {
		if (n % i != 0)
			continue;
		int k = n / i;
		int fl = 0;
		for (int j = 0; j < 26; ++j)
			if (a[j] % k != 0) {
				fl = 1;
				break;
			}
		if (fl)
			continue;
		if (k % 2 == 0) {
			string s;
			for (int j = 0; j < 26; ++j) {
				for (int jj = 0; jj * k < a[j]; ++jj)
					s += (char)('a' + j);
			}
			out(s, k);
			return;
		}
		else {
			if (i % 2 == 0) {
				continue;
			}
			string s;
			int cc = 0;
			for (int j = 0; j < 26; ++j)
				if ((a[j] / k) % 2 == 1)
					++cc;

			if (cc > 1)
				continue;
			char ccc;
			for (int j = 0; j < 26; ++j) {
				if ((a[j] / k) % 2 == 1)
					ccc = 'a' + j, --a[j];
				a[j] /= 2 * k;
				for (int xx = 0; xx < a[j]; ++xx)
					s += (char)('a' + j);
			}
			string s2 = s;
			reverse(s2.begin(), s2.end());
			out(s + ccc + s2, k);
			return;
		}
	}
	outj();
}

void solve1() {
	int c = 0; 
	int cc = 0;
	for (int i = 0; i < 26; ++i) {
		if (a[i] % 2 == 1)
			c = i, ++cc;
	}
	if (cc > 1) {
		cout << 0 << "\n";
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < a[i]; ++j)
				cout << (char)('a' + i);
		cout << "\n";
		return;
	}
	int cnt = a[c];
	
	for (int i = 1; i <= n; ++i) {
		if (n % i != 0)
			continue;
		int k = n / i;
		if (cnt < k)
			continue;
		a[c] = cnt - k;
		int fl = 0;
		for (int j = 0; j < 26; ++j)
			if (a[j] % (2 * k) != 0) {
				fl = 1;
				break;
			}
		if (fl)
			continue;
		string s;
		for (int j = 0; j < 26; ++j) {
			a[j] /= 2 * k;
			for (int xx = 0; xx < a[j]; ++xx)
				s += (char)('a' + j);
		}
		string s2 = s;
		reverse(s2.begin(), s2.end());
		s = (char)(c + 'a') + s + s2;
		cout << k << "\n";
		for (int i = 0; i < k; ++i)
			cout << s;
		cout << "\n";
		return;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin >> m;
	for (int i = 0; i < m; ++i)
		cin >> a[i], n += a[i];
	if (n % 2 == 0) {
		solve0();
		return 0;
	}
	else {
		solve1();
		return 0;
	}
	return 0;
}