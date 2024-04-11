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
#define LONG_INF 30000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
double dot(complex<double> a, complex<double> b) {
	return a.real()* b.real() + a.imag() * b.imag();
}
double gyaku_dot(complex<double> a, complex<double> b) {
	return a.real()* b.imag() - a.imag() * b.real();
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
unsigned long xor128() {
	static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
pair<long long, long long> seg_tree[seg_size * 4];
pair<long long, long long> seg_find(long long now, long long n_l, long long n_r, long long w_l, long long w_r) {
	if (w_l <= n_l && n_r <= w_r) return seg_tree[now];
	if (n_r <= w_l || w_r <= n_l) return make_pair(0, 0);
	pair<long long, long long> a = seg_find(now * 2, n_l, (n_l + n_r) / 2, w_l, w_r), b = seg_find(now * 2 + 1, (n_l + n_r) / 2, n_r, w_l, w_r);
	a.first += b.first;
	a.second += b.second;
	return a;
}
long long seg_set(int now) {
	seg_tree[now] = make_pair(seg_tree[now * 2].first + seg_tree[now * 2 + 1].first, seg_tree[now * 2].second + seg_tree[now * 2 + 1].second);
	if (now != 1) seg_set(now / 2);
	return 0;
}
long long inv(long long now) {
	long long now_go = MAX_MOD - 2LL;
	long long ans = 1;
	while (now_go != 0) {
		if (now_go % 2 == 1) {
			ans *= now;
			ans %= MAX_MOD;
		}
		now *= now;
		now %= MAX_MOD;
		now_go /= 2;
	}
	return ans;
}
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
#define int long long
	int a, b, c;
	cin >> a >> b >> c;
	int ans = c*2LL;
	int geko = min(a, b);
	ans += geko * 2LL;
	a -= geko;
	b -= geko;
	if (a != 0)ans++;
	if (b != 0) ans++;
	cout << ans << endl;
	return 0;
}