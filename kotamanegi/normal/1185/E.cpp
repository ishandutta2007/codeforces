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
int main(){
#define int long long
	iostream::sync_with_stdio(false);
	int test_case;
	cin >> test_case;
	REP(testing, test_case) {
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> inputs[26];
		vector<string> campus;
		vector<string> moto;
		REP(i, n) {
			string a;
			cin >> a;
			moto.push_back(a);
			REP(q, a.length()) {
				if (a[q] != '.') {
					inputs[a[q] - 'a'].push_back(make_pair(i + 1, q+1));
					a[q] = '.';
				}
			}
			campus.push_back(a);
		}
		vector<tuple<long long, long long, long long, long long>> ans;
		vector<int> gogo;
		int ok = 0;
		int now_itr = -1;
		for (int i = 0; i < 26; ++i) {
			if (inputs[i].size() != 0) {
				now_itr = max(now_itr, i);
				gogo.push_back(i);
				sort(inputs[i].begin(), inputs[i].end());
				if (inputs[i][0].first == inputs[i][inputs[i].size() - 1].first) {
					int gogo_min = inputs[i][0].second;
					int gogo_max = inputs[i][0].second;
					for (int q = 0; q < inputs[i].size(); ++q) {
						gogo_min = min(inputs[i][q].second, gogo_min);
						gogo_max = max(inputs[i][q].second, gogo_max);
					}
					ans.push_back(make_tuple(inputs[i][0].first, gogo_min, inputs[i][0].first, gogo_max));
				}
				else {
					for (int q = 1; q < inputs[i].size(); ++q) {
						if (inputs[i][q].second != inputs[i][q - 1].second) {
							ok = 1;
							break;
						}
					}
					ans.push_back(make_tuple(inputs[i][0].first, inputs[i][0].second, inputs[i][inputs[i].size() - 1].first, inputs[i][0].second));
				}
			}
		}
		if (ok == 0) {
			for (int q = 0;q < ans.size(); ++q) {
				if (get<0>(ans[q]) == get<2>(ans[q])) {
					for (int j = get<1>(ans[q])-1; j <= get<3>(ans[q])-1; ++j) {
						campus[get<0>(ans[q])-1][j] = (char)(gogo[q] + 'a');
					}
				}
				else {
					for (int j = get<0>(ans[q])-1; j <= get<2>(ans[q])-1; ++j) {
						campus[j][get<1>(ans[q])-1] = (char)(gogo[q] + 'a');
					}
				}
			}
			if (moto == campus) {
				cout << "YES" << endl;
				cout << now_itr+1 << endl;
				int already_done = 0;
				REP(i, ans.size()) {
					while(already_done < gogo[i]){
						cout << get<0>(ans[i]) << " " << get<1>(ans[i]) << " " << get<2>(ans[i]) << " " << get<3>(ans[i]) << endl;
						already_done++;
					}
					already_done++;
					cout << get<0>(ans[i]) << " " << get<1>(ans[i]) << " " << get<2>(ans[i]) << " " << get<3>(ans[i]) << endl;
				}
			}
			else {
				cout << "NO" << endl;
			}
		}
		else {
			cout << "NO" << endl;
		}
	}
}