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

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

int df(int a, int b) {
	int ans = 0;
	if (a % 10 != b % 10)
		++ans;
	if (a / 10 != b / 10)
		++ans;
	return ans;
}

int main() {
	int x;
	cin >> x;
	int m1, m2;
	int h, m;
	scanf("%d:%d", &h, &m);
	m2 = m % 10;
	m /= 10;
	if (m >= 6)
		m1 = 0;
	else
		m1 = m;
	int mn = 2;
	if (x == 12) {
		for (int i = 1; i <= 12; ++i)
			mn = min(mn, df(i, h));
	}
	else {
		for (int i = 0; i <= 23; ++i)
			mn = min(mn, df(i, h));
	}
	if (x == 12) {
		for (int i = 1; i <= 12; ++i) {
			if (mn == df(i, h)) {
				if (i < 10)
					cout << 0;
				cout << i << ":" << m1 << m2 << "\n";
				return 0;
			}
		}
	}
	else {
		for (int i = 0; i <= 23; ++i) {
			if (mn == df(i, h)) {
				if (i < 10)
					cout << "0";
				cout << i << ":" << m1 << m2 << "\n";
				return 0;
			}
		}
	}
	return 0;
}