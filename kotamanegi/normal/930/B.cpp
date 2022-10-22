#define  _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
int griding[20000];
int dp[30][6000][30] = {};
int main() {
	string s;
	cin >> s;
	s += s;
	for (int i = 0; i < s.length(); ++i) {
		griding[i] = s[i] - 'a';
	}
	for (int i = 0; i < s.length() / 2; ++i) {
		for (int q = 1; q < s.length() / 2; ++q) {
			dp[griding[i]][q][griding[i + q]]++;
		}
	}
	int ans = 0;
	for (int i = 0; i < 27; ++i) {
		int pre_ans = 0;
		for (int q = 1; q <= s.length() / 2; ++q) {
			int popo = 0;
			for (int j = 0; j < 27; ++j) {
				if (dp[i][q][j] == 1) popo++;
			}
			pre_ans = max(pre_ans, popo);
		}
		ans += pre_ans;
	}
	int meme = s.length() / 2;
	cout << fixed << setprecision(10);
	cout << (double)ans / (double)meme << endl;
	return 0;
}