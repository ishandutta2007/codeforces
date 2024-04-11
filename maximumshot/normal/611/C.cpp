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

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

bool solve() {

	int h, w;

	cin >> h >> w;

	vec< string > mat(h);
	for(int i = 0;i < h;i++) cin >> mat[i];

	vec< vec< int > > dp(h, vec< int >(w)), sum = dp, cnt = dp;
	vec< vec< int > > dp2 = dp, sum2 = dp, cnt2 = dp;

	for(int i = 0;i < h;i++) {
		for(int j = 1;j < w;j++) {
			dp[i][j] = dp[i][j - 1];
			if(mat[i][j] == '.' && mat[i][j - 1] == '.') dp[i][j]++;
		}
	}

	for(int r = 0;r < w;r++) {
		for(int i = 0;i < h;i++) {
			if(i) sum[i][r] = sum[i - 1][r];
			sum[i][r] += dp[i][r];
		}
	}
	for(int i = 0;i < h;i++) {
		for(int j = 0;j + 1 < w;j++) {
			if(i) cnt[i][j] = cnt[i - 1][j];
			if(mat[i][j] == '.' && mat[i][j + 1] == '.') cnt[i][j]++;
		}
	}

	for(int j = 0;j < w;j++) {
		for(int i = 1;i < h;i++) {
			dp2[i][j] = dp2[i - 1][j];
			if(mat[i][j] == '.' && mat[i - 1][j] == '.') dp2[i][j]++;
		}
	}

	for(int r = 0;r < h;r++) {
		for(int j = 0;j < w;j++) {
			if(j) sum2[r][j] = sum2[r][j - 1];
			sum2[r][j] += dp2[r][j];
		}
	}

	for(int i = 0;i + 1 < h;i++) {
		for(int j = 0;j < w;j++) {
			if(j) cnt2[i][j] = cnt2[i][j - 1];
			if(mat[i][j] == '.' && mat[i + 1][j] == '.') cnt2[i][j]++;
		}
	}
	
	int q;
	scanf("%d", &q);

	for(int r1, r2, c1, c2;q;q--) {
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		r1--, c1--;
		r2--, c2--;
		int ans = sum[r2][c2] - (r1?sum[r1 - 1][c2] : 0) - ((c1?sum[r2][c1 - 1] : 0) - (c1 && r1?sum[r1 - 1][c1 - 1] : 0));
		ans -= ((c1?cnt[r2][c1 - 1] : 0) - (c1 && r1?cnt[r1 - 1][c1 - 1] : 0));
		
		int ans2 = sum2[r2][c2] - (c1?sum2[r2][c1 - 1] : 0) - ( (r1?sum2[r1 - 1][c2] : 0) - (r1 && c1?sum2[r1 - 1][c1 - 1] : 0) );
		ans2 -= ( (r1?cnt2[r1 - 1][c2] : 0) - (r1 && c1?cnt2[r1 - 1][c1 - 1] : 0) );
		
		printf("%d\n", ans + ans2);
	}

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}