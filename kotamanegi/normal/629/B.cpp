#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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
#include <list>
#include <typeinfo>
using namespace std;
#define REP(a,b) for(long long a = 0;a < b;++a)
int man_imos[500] = {};
int woman_imos[500] = {};
int main() {
	int n;
	cin >> n;
	for (int i = 0;i < n;++i) {
		string a;
		int b, c;
		cin >> a >> b >> c;
		if (a[0] == 'M') {
			for (int q = b;q <= c;++q) {
				man_imos[q]++;
			}
		}
		else {
			for (int q = b;q <= c;++q) {
				woman_imos[q]++;
			}
		}
	}
	int max_ans = 0;
	for (int i = 0;i < 400;++i) {
		max_ans = max(max_ans,2* min(woman_imos[i], man_imos[i]));
	}
	cout << max_ans << endl;
}
//thank you for reading my code!