/*

This Submission is to determine how many 120/240 min const. delivery point there are.

//info
120 req. steps <= 5
*/
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
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define seg_size 262144
#define REP(a,b) for(long long a = 0;a < b;++a)

unsigned long xor128() {
	static unsigned long x = time(NULL), y = 362436069, z = 521288629, w = 88675123;
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
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
	double kaku = acos(min((double)1.0, max((double)-1.0, cosine)));
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
		double now_length = 0;
		int starter = ans[ans.size() - 1];
		for (int i = 0; i < a.size(); ++i) {
			if (i != starter) {
				double goa = angles(ba, a[i] - a[starter]);
				if (goa - now_min >= eps || (abs(goa - now_min) <= eps && (abs(a[i] - a[starter]) - now_length) >= eps)) {
					now_min = goa;
					now_go = i;
					now_length = abs(a[i] - a[starter]);
				}
			}
		}
		if (now_go == ans[0]) break;
		ans.push_back(now_go);
		ba = complex<double>(a[now_go] - a[starter]);
	}
	return ans;
}
vector<long long >geko[300000];
long long kazu[300000];
int main(){
	iostream::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<int,int>> D;
	REP(i, n) {
		int a;
		cin >> a;
		D.push_back(make_pair(a, i*2));
	}
	sort(D.begin(), D.end());
	reverse(D.begin(), D.end());
	kazu[0] = D[0].second + 1;
	kazu[D[0].first] = D[0].second + 2;
	int now_itr = 1;
	vector<int> gogo;
	for (int i = 1; i < D[0].first; ++i) {
		if (kazu[i] != 0) continue;
		kazu[i] = D[now_itr].second + 1;
		int hoge = i + D[now_itr].first;
		if (kazu[hoge] == 0) {
			kazu[hoge] = D[now_itr].second + 2;
		}
		else {
			if (D[now_itr].first == 1) {
				geko[i].push_back(D[now_itr].second + 2);
			}
			else {
				geko[hoge - 1].push_back(D[now_itr].second + 2);
			}
		}
		now_itr++;
	}
	vector<int> neko;
	while (now_itr < n) {
		if (D[now_itr].first == 1) {
			cout << kazu[0] << " " << D[now_itr].second + 1 << endl;
			cout << D[now_itr].second+1 << " " << D[now_itr].second + 2 << endl;
			now_itr++;
			continue;
		}
		geko[0].push_back(D[now_itr].second + 1);
		geko[D[now_itr].first - 2].push_back(D[now_itr].second + 2);
		now_itr++;
	}
	for (int i = 0; kazu[i] != 0; ++i) {
		if (i != 0) {
			cout << kazu[i - 1] << " " << kazu[i] << endl;
		}
		REP(j, geko[i].size()) {
			cout << kazu[i] << " " << geko[i][j] << endl;
		}
	}
}