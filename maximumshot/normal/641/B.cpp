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
	
	int n, m, q;

	scanf("%d %d %d", &n, &m, &q);

	vec< vec< int > > mat(n + 1, vec< int >(m + 1, 1));

	vec< pair< int, pair<pii, int > > > mas;

	for(int i = 0;i < q;i++) {
		int ty;
		scanf("%d", &ty);
		if(ty == 1 || ty == 2) {
			int r;
			scanf("%d", &r);
			mas.push_back(mp(ty, mp(mp(r, r), r)));
		}else {
			int r, c, x;
			scanf("%d %d %d", &r, &c, &x);
			mas.push_back(mp(ty, mp(mp(r, c), x)));
		}
	}

	for(int it = q - 1;it >= 0;it--) {
		int ty, r, c, x;
		ty = mas[it].first;
		if(ty == 1) {
			r = mas[it].second.second;
			int last = mat[r][m];
			for(int i = m;i > 1;i--) mat[r][i] = mat[r][i - 1];
			mat[r][1] = last;
		}else if(ty == 2) {
			int c = mas[it].second.second;
			int last = mat[n][c];
			for(int i = n;i > 1;i--) mat[i][c] = mat[i - 1][c];
			mat[1][c] = last;
		}else {
			r = mas[it].second.first.first;
			c = mas[it].second.first.second;
			x = mas[it].second.second;
			mat[r][c] = x;
		}
	}

	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}