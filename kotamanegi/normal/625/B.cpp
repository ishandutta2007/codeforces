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
	string a, b;
	cin >> a >> b;
	if (a.length() < b.length()) {
		printf("0");
		return 0;
	}
	long long ans = 0;
	for (int i = 0;i < a.length()-b.length()+1;++i) {
		if (b[0] == a[i]) {
			for (int q = 0;q < b.length();++q) {
				if (a[i + q] != b[q]) goto failed;
			}
			ans++;
			i += b.length() - 1;
		}
	failed:;
	}
	cout << ans;
}