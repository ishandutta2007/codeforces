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
const int MAXN = 120000;

int f[MAXN];
int gg[MAXN];
int go[MAXN];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		scanf("%d", f + i), --f[i];
	int cc = 0;
	for (int i = 0; i < n; ++i) {
		if (i == f[i]) {
			gg[i] = cc;
			go[cc] = i;
			++cc;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (i != f[i] && f[f[i]] != f[i]) {
			cout << -1 << "\n";
			return 0;
		}
	}
	int m = cc;
	cout << m << "\n";
	for (int i = 0; i < n; ++i) {
		cout << gg[f[i]] + 1 << " ";
	}
	cout << "\n";
	for (int i = 0; i < m; ++i) {
		cout << go[i] + 1 << " ";
	}
	cout << "\n";
	return 0;
}