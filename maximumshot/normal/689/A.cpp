#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <math.h>
#include <unordered_map>
#include <array>
#include <complex>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

bool solve() {

	int n;

	cin >> n;

	vec< int > a(n);

	for(int i = 0;i < n;i++) {
		char c;
		cin >> c;
		a[i] = c - '0';
	}

	int mat[4][3] = {
		{1, 2, 3},
		{4, 5, 6}, 
		{7, 8, 9},
		{-1, 0, -1}
	};

	int x[10], y[10];

	for(int i = 0;i < 4;i++) {
		for(int j = 0;j < 3;j++) {
			if(mat[i][j] != -1) {
				x[mat[i][j]] = i;
				y[mat[i][j]] = j;
			}
		}
	} 

	int res = 0;

	for(int st = 0;st < 10;st++) {
		int X, Y;
		tie(X, Y) = mt(x[st], y[st]);
		int ok = 1;
		for(int j = 1;j < n;j++) {
			int dx, dy;
			dx = x[a[j]] - x[a[j - 1]];
			dy = y[a[j]] - y[a[j - 1]];
			X += dx;
			Y += dy;
			if(X < 0 || X > 3 || Y < 0 || Y > 2) {
				ok = 0;
				break;
			}
			if(mat[X][Y] == -1) {
				ok = 0;
				break;
			}
		}
		res += ok;
	}

	cout << (res > 1?"NO" : "YES") << "\n";

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}