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
long long dp[50][3][3][3][3];
int main(){
#define int long long
	long long test_case;
	cin >> test_case;
	REP(tea, test_case) {
		long long l, r;
		cin >> l >> r;
		REP(i, 50) {
			REP(q, 3) {
				REP(j, 3) {
					REP(t, 3) {
						REP(p, 3) {
							dp[i][q][j][t][p] = 0;
						}
					}
				}
			}
		}
		dp[31][0][0][0][0] = 1;
		for (long long i = 31; i >= 1; --i) {
			REP(q, 3) {
				REP(j, 3) {
					REP(t, 3) {
						REP(p, 3) {
							long long next_q = q * 2;
							long long next_j = j * 2;
							long long next_t = t * 2;
							long long next_p = p * 2;
							if (((1LL << (i - 1)) & r) != 0) {
								next_q++;
								next_j++;
							}
							if (((1LL << (i - 1)) & l) != 0) {
								next_t--;
								next_p--;
							}
							{
								//fill a -> 1,b -> 0;
								next_q--;
								next_t++;
								if (next_q >= 0 && next_j >= 0 && next_t >= 0 && next_p >= 0) {
									dp[i - 1][min(next_q, 2LL)][min(next_j, 2LL)][min(next_t, 2LL)][min(next_p, 2LL)] += dp[i][q][j][t][p];
								}
								next_q++;
								next_t--;
							}
							{
								//fill a -> 0,b -> 1
								next_j--;
								next_p++;
								if (next_q >= 0 && next_j >= 0 && next_t >= 0 && next_p >= 0) {
									dp[i - 1][min(next_q, 2LL)][min(next_j, 2LL)][min(next_t, 2LL)][min(next_p, 2LL)] += dp[i][q][j][t][p];
								}
								next_j++;
								next_p--;
							}
							{
								//fill a -> 0, b -> 0
								if (next_q >= 0 && next_j >= 0 && next_t >= 0 && next_p >= 0) {
									dp[i - 1][min(next_q, 2LL)][min(next_j, 2LL)][min(next_t, 2LL)][min(next_p, 2LL)] += dp[i][q][j][t][p];
								}
							}
						}
					}
				}
			}
		}
		long long ans = 0;
		REP(i, 3) {
			REP(q, 3) {
				REP(t, 3) {
					REP(j, 3) {
						ans += dp[0][i][q][t][j];
					}
				}
			}
		}
		cout << ans << endl;
	}
}