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
int main() {
	long long n, k;
	scanf("%I64d%I64d", &k, &n);
	string hoge;
	cin >> hoge;
	string ans;
	for (long long i = 0;i < k;++i) {
		if (n == 0) {
			ans.push_back(hoge[i]);
		}
		else {
			int nownow = max((int)'z'-(int)hoge[i],(int)hoge[i]-(int)'a');
			if (nownow <= n) {
				n -= nownow;
				if ((int)'z'-(int)hoge[i] >= (int)hoge[i]-(int)'a') {
					ans.push_back('z');
				}
				else {
					ans.push_back('a');
				}
			}
			else {
				for (int q = 97;q >= 0;++q) {
					if (n == q - (int)hoge[i] || n == (int)hoge[i] - q) {
						n = 0;
						ans.push_back((char)q);
						goto thanks;
					}
				}
			thanks:;
			}
		}
	}
	if (n >0) {
		printf("-1\n");
		return 0;
	}
	else {
		cout << ans << endl;
		return 0;
	}
}