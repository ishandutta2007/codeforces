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
string solve(string a, string b) {
	if (a.length() > b.length()) swap(a, b);
	b = "0" + b;
	reverse(a.begin(), a.end());
	while (a.length() < b.length()) {
		a.push_back('0');
	}
	reverse(a.begin(), a.end());
	int kuriagari = 0;
	string ans;
	for (int i = a.length() - 1; i >= 0; --i) {
		kuriagari += a[i] - '0';
		kuriagari += b[i] - '0';
		ans.push_back(kuriagari % 10 + '0');
		kuriagari /= 10;
	}
	while (ans.size() > 1 && ans[ans.size() - 1] == '0') {
		ans.pop_back();
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
int winniner(string a, string b) {
	if (a.length() < b.length()) return 1;
	else if (a.length() > b.length()) return 0;
	else {
		for (int q = 0; q < a.length(); ++q) {
			if (a[q] < b[q]) {
				return 1;
			}
			else if(a[q] > b[q]){
				return 0;
			}
		}
		return 1;
	}
}
int main(){
	long long l;
	cin >> l;
	string s;
	cin >> s;
	string now_ans;
	int ok = 0;
	int tea[3] = { 0,l/2,l/2+1 };
	for (int go = l / 2; go >= 1; --go) {
		if (s[go] != '0') {
			tea[0] = go;
			break;
		}
	}
	for (int go = l / 2+1; go < l; ++go) {
		if (s[go] != '0') {
			tea[2] = go;
			break;
		}
	}
	for (int ta = 0; ta <= 2; ++ta) {
		int geko = tea[ta];
		if (geko <= 0 || geko >= l) {
			continue;
		}
		string a, b;
		REP(i, geko) {
			a.push_back(s[i]);
		}
		for (int i = geko; i < s.length(); ++i) {
			b.push_back(s[i]);
		}
		if (b[0] != '0') {
			string c = solve(a, b);
			if (ok == 0 || winniner(c,now_ans) == 1) {
				now_ans = c;
				ok = 1;
			}
		}
	}
	cout << now_ans << endl;
	return 0;
}