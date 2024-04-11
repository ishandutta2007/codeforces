#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 1e-5
#define LONG_INF 2000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144
#define REP(a,b) for(long long a = 0;a < b;++a)
pair<int,tuple<int,int,int>> dp[200000][3][3];
int ans_size = 0;
int ans[200000];
void backtrace(tuple<int, int, int> now) {
	if (now == make_tuple(0, 0, 0)) {
		return;
	}
	tuple<int, int, int> next = dp[get<0>(now)][get<1>(now)][get<2>(now)].second;
	backtrace(next);
	if (dp[get<0>(next)][get<1>(next)][get<2>(next)].first < dp[get<0>(now)][get<1>(now)][get<2>(now)].first) {
		ans[ans_size] = get<0>(now);
		ans_size++;
	}
	return;
}
int main() {
	iostream::sync_with_stdio(false);
	int t;
	cin >> t;
	REP(i, t) {
		string s;
		cin >> s;
		REP(i, 3) {
			REP(q, 3) {
				REP(j, s.length()+1) {
					dp[j][i][q] = make_pair(1e9, make_tuple(-1, -1, -1));
				}
			}
		}
		dp[0][0][0] = make_pair(0, make_tuple(0, 0, 0));
		string geko[2] = { "one","two" };
		REP(i, s.length()) {
			REP(q, 3) {
				REP(j, 3) {
					if (dp[i][q][j].first == 1e9) continue;
					//skip
					if (dp[i + 1][q][j].first > dp[i][q][j].first + 1) {
						dp[i + 1][q][j] = make_pair(dp[i][q][j].first + 1, make_tuple(i, q, j));
					}
					int next_x = q;
					int next_y = j;
					if (geko[0][next_x] == s[i]) {
						next_x++;
					}
					else {
						next_x = 0;
						if (geko[0][next_x] == s[i]) {
							next_x++;
						}
					}
					if (geko[1][next_y] == s[i]) {
						next_y++;
					}
					else {
						if (geko[1][0] == s[i]) {
							next_y = 1;
						}
						else {
							next_y = 0;
						}
					}
					if (next_x != 3 && next_y != 3) {
						if (dp[i + 1][next_x][next_y].first > dp[i][q][j].first) {
							dp[i + 1][next_x][next_y] = make_pair(dp[i][q][j].first, make_tuple(i, q, j));
						}
					}
				}
			}
		}
		ans_size = 0;
		tuple<int, int, int> now = make_tuple(s.length(), 0, 0);
		REP(i, 3) {
			REP(q, 3) {
				if (dp[get<0>(now)][get<1>(now)][get<2>(now)].first > dp[s.length()][i][q].first) {
					now = make_tuple(s.length(), i, q);
				}
			}
		}
		backtrace(now);
		cout << ans_size << endl;
		REP(i, ans_size) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}