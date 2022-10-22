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
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
double dot(complex<double> a, complex<double> b) {
	return a.real() * b.real() + a.imag() * b.imag();
}
double gyaku_dot(complex<double> a, complex<double> b) {
	return a.real() * b.imag() - a.imag() * b.real();
}
double leng(complex<double> a) {
	return sqrt(a.real() * a.real() + a.imag() * a.imag());
}
double angles(complex<double> a, complex<double> b) {
	double cosine = dot(a, b) / (leng(a) * leng(b));
	double sine = gyaku_dot(a, b) / (leng(a) * leng(b));
	double kaku = acos(cosine);
	if (sine <= 0) {
		kaku = 2 * Ma_PI - kaku;
	}
	return kaku;
}
vector<int> convex_hull(vector<complex<double>> a) {
	vector<int> ans;
	double now_minnest = a[0].real();
	int now_itr = 0;
	REP(i, a.size()) {
		if (now_minnest > a[i].real()) {
			now_minnest = a[i].real();
			now_itr = i;
		}
	}
	ans.push_back(now_itr);
	complex<double> ba(0, 1);
	while (true) {
		int now_go = 0;
		double now_min = 0;
		int starter = ans[ans.size() - 1];
		for (int i = 0; i < a.size(); ++i) {
			if (i != starter) {
				double goa = angles(ba, a[i] - a[starter]);
				if (goa > now_min) {
					now_min = goa;
					now_go = i;
				}
			}
		}
		if (now_go == ans[0]) break;
		ans.push_back(now_go);
		ba = complex<double>(a[now_go] - a[starter]);
	}
	return ans;
}
long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
long long dp[4][16][16][16] = {};
int main(){
	int n, t;
	cin >> n >> t;
	vector<pair<long long, long long>> inputs;
	REP(i, n) {
		long long a, b;
		cin >> a >> b;
		inputs.push_back(make_pair(a, b));
	}
	long long ans = 0;
	for (int i = 0; i < (1 << n); ++i) {
		long long cnt[4] = {};
		int now = i;
		int time_consume = 0;
		for (int q = 0; now != 0; ++q) {
			if (now % 2 == 1) {
				cnt[inputs[q].second]++;
				time_consume += inputs[q].first;
			}
			now /= 2;
		}
		if (time_consume == t) {

			REP(q, 4) {
				REP(j, 16) {
					REP(t, 16) {
						REP(p, 16) {
							dp[q][j][t][p] = 0;
						}
					}
				}
			}

			dp[0][0][0][0] = 1;
			for (int q = 0; q <= cnt[1]; ++q) {
				for (int j = 0; j <= cnt[2]; ++j) {
					for (int t = 0; t <= cnt[3]; ++t) {
						for (int p = 0; p < 4; ++p) {
							if (p != 1) {
								dp[1][q + 1][j][t] += dp[p][q][j][t] * (cnt[1] - q);
								dp[1][q + 1][j][t] %= MAX_MOD;
							}
							if (p != 2) {
								dp[2][q][j + 1][t] += dp[p][q][j][t] * (cnt[2] - j);
								dp[2][q][j + 1][t] %= MAX_MOD;
							}
							if (p != 3) {
								dp[3][q][j][t + 1] += dp[p][q][j][t] * (cnt[3] - t);
								dp[3][q][j][t + 1] %= MAX_MOD;
							}
						}
					}
				}
			}
			REP(q, 3) {
				ans += dp[q+1][cnt[1]][cnt[2]][cnt[3]];
				ans %= MAX_MOD;
			}
		}
	}
	cout << ans << endl;
}