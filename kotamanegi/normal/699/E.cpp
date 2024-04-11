#define _CRT_SECURE_NO_WARNINGS
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
#include<map>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <iomanip>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
double dp[10485760] = {};
int count_ni(int a) {
	int ans = 0;
	while (a != 0) {
		ans += a % 2;
		a /= 2;
	}
	return ans;
}
int main() {
	int a, b;
	cin >> a >> b;
	vector<double> p;
	int pwa = 0;
	p.push_back(0);
	int waw = 1;
	REP(i, a) {
		double hoge;
		cin >> hoge;
		p.push_back(hoge);
		dp[waw] = hoge;
		if (p[i+1] == 0.0) {
			pwa++;
		}
		waw *= 2;
	}
	if (a-pwa <= b) {
		for (int i = 0;i < a;++i) {
			if (p[i+1] != 0.0) {
				cout << "1.0 ";
			}
			else {
				cout << "0.0 ";
			}
		}
		return 0;
	}
	int topping = 1;
	for (int i = 0;i < a;++i) {
		topping *= 2;
	}
	for (int i = 0;i < topping;++i) {
		int tips = 0;
		for (int q = 1;q <= topping - 1;q *= 2) {
			tips++;
			if ((i | q) != i) {
				double hogehoge = 1.0;
				int copy_i = i;
				for (int j = 0;copy_i != 0;++j) {
					if (copy_i % 2 == 1) {
						hogehoge -= p[j + 1];
					}
					copy_i /= 2;
				}
				dp[i | q] += dp[i] * p[tips] / hogehoge;
			}
		}
	}
	double ans[100] = {};
	for (int i = 1;i <= topping*2;++i) {
		if (count_ni(i) == b) {
			int copy_i = i;
			for (int q = 0;copy_i != 0;++q) {
				if (copy_i % 2 == 1) {
					ans[q] += dp[i];
				}
				copy_i /= 2;
			}
		}
	}
	for (int i = 0;i < a;++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}