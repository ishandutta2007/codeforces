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

int cc;
map<string, int> mm;
int vl[2][5010][1010];
int mn[5100];
int mx[5100];

int fnd(string s) {
	if (mm.count(s))
		return mm[s];
	else
		return mm[s] = cc++;
}
int n, m;

char name[5100];
char s[5100];
char t[5100];
char op[5100];

int main() {
	scanf("%d%d", &n, &m);
	int x = fnd("?");
	for (int i = 0; i < m; ++i)
		vl[0][x][i] = 0, vl[1][x][i] = 1;
	for (int i = 0; i < n; ++i) {
		scanf(" %s := %s", name, s);
		int x = fnd(name);
		if (s[0] == '0' || s[0] == '1') {
			for (int j = 0; j < m; ++j)
				vl[0][x][j] = vl[1][x][j] = s[j] - '0';
		}
		else {
			scanf(" %s %s", op, t);
			int a = fnd(s);
			int b = fnd(t);
			if (op[0] == 'A') {
				for (int j = 0; j < m; ++j)
					vl[0][x][j] = vl[0][a][j] & vl[0][b][j];
				for (int j = 0; j < m; ++j)
					vl[1][x][j] = vl[1][a][j] & vl[1][b][j];
			}
			else if (op[0] == 'O') {
				for (int j = 0; j < m; ++j)
					vl[0][x][j] = vl[0][a][j] | vl[0][b][j];
				for (int j = 0; j < m; ++j)
					vl[1][x][j] = vl[1][a][j] | vl[1][b][j];
			}
			else {
				for (int j = 0; j < m; ++j)
					vl[0][x][j] = vl[0][a][j] ^ vl[0][b][j];
				for (int j = 0; j < m; ++j)
					vl[1][x][j] = vl[1][a][j] ^ vl[1][b][j];
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		int s1 = 0;
		int s2 = 0;
		for (int j = 1; j <= n; ++j) {
			s1 += vl[0][j][i];
			s2 += vl[1][j][i];
		}
		if (s1 < s2) {
			mn[i] = 0;
			mx[i] = 1;
		}
		else if (s1 > s2) {
			mn[i] = 1;
			mx[i] = 0;
		}
		else {
			mn[i] = mx[i] = 0;
		}
	}
	for (int i = 0; i < m; ++i)
		cout << mn[i];
	cout << "\n";
	for (int i = 0; i < m; ++i)
		cout << mx[i];
	cout << "\n";
	return 0;
}