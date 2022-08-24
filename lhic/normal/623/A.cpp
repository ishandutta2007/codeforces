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
typedef long double ld;

using namespace std;


int n;
char s[1000];
int was[1000];
int m;

int ed[1000][1000];
void dfs(int v, char c) {
	was[v] = 1;
	s[v] = c;
	for (int i = 0; i < n; ++i)
		if (!ed[v][i] && i != v) {
			if (was[i]) {
				if (s[v] + s[i] != 'a' + 'c') {
					cout << "No\n";
					exit(0);
				}
			}
			else {
				dfs(i, 'c' + 'a' - c);
			}
		}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		ed[a][b] = ed[b][a] = 1;
	}
	if (m == (n - 1) * n / 2) {
		cout << "Yes\n";
		for (int i = 0; i < n; ++i)
			cout << "a";
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		for (int j = 0; j < n; ++j)
			cnt += ed[i][j];
		if (cnt != n - 1) {
			if (!was[i])
				dfs(i, 'a');
		}
		else
			s[i] = 'b';
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (s[i] == 'a' && s[j] == 'c' && ed[i][j]) {
				cout << "No\n";
				return 0;
			}
	cout << "Yes\n";
	cout << s << "\n";
	return 0;
}