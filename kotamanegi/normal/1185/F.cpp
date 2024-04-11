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
tuple<long long, long long, long long> dp[5000];
int main(){
	REP(i, 5000) {
		dp[i] = make_tuple(LONG_INF, -1, -1);
	}
#define int long long
	iostream::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<long long> friends;
	REP(i, n) {
		long long a;
		cin >> a;
		long long now = 0;
		for (int q = 0; q < a; ++q) {
			long long geko = 0;
			cin >> geko;
			geko--;
			now += (1 << geko);
		}
		friends.push_back(now);
	}
	vector<tuple<long long, long long,long long>> inputs;
	REP(i, m) {
		long long a;
		cin >> a;
		long long  b;
		cin >> b;
		long long now = 0;
		for (int q = 0; q < b; ++q) {
			long long geko = 0;
			cin >> geko;
			geko--;
			now += (1 << geko);
		}
		inputs.push_back(make_tuple(now,a,i + 1));
	}
	sort(inputs.begin(), inputs.end());
	vector<tuple<long long, long long, long long>> nextings;
	nextings.push_back(make_tuple(get<1>(inputs[0]), get<0>(inputs[0]), get<2>(inputs[0])));
	int cnt = 1;
	for (int i = 1; i < inputs.size(); ++i) {
		if (get<0>(inputs[i]) != get<0>(inputs[i - 1])) {
			cnt = 0;
		}
		cnt++;
		if (cnt <= 2) {
			nextings.push_back(make_tuple(get<1>(inputs[i]), get<0>(inputs[i]), get<2>(inputs[i])));
		}
	}
	for (int i = 0; i < nextings.size(); ++i) {
		for (int q = i + 1; q < nextings.size(); ++q) {
			long long nya = (get<1>(nextings[i]) | get<1>(nextings[q]));
			long long price = get<0>(nextings[i]) + get<0>(nextings[q]);
			if (get<0>(dp[nya]) > price) {
				dp[nya] = make_tuple(price, get<2>(nextings[i]), get<2>(nextings[q]));
			}
		}
	}
	long long ans[2] = {};
	long long ans_value = LONG_INF;
	long long ans_friends = -1LL;
	for (long long i = 0; i < 4096; ++i) {
		long long cnt_friend = 0;
		for (int q = 0; q < n; ++q) {
			if ((friends[q] & i) == friends[q]) {
				cnt_friend++;
			}
		}
		if (get<0>(dp[i]) != LONG_INF) {
			if (cnt_friend > ans_friends || (cnt_friend == ans_friends && ans_value > get<0>(dp[i]))) {
				ans[0] = get<1>(dp[i]);
				ans[1] = get<2>(dp[i]);
				ans_friends = cnt_friend;
				ans_value = get<0>(dp[i]);
			}
		}
	}
	if (ans[0] > ans[1]) swap(ans[0], ans[1]);
	cout << ans[0] << " " << ans[1] << endl;
}