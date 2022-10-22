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
	int b;
	long long hoge[10000] = {};
	long long hogehoge[10000] = {};
	cin >> b;
	REP(i, b) cin >> hoge[i];
	REP(i, b) {
		cin >> hogehoge[i];
	}
	long long answer = 0;
	for (int i = 0;i < b;++i) {
		for (int q = i;q < b;++q) {
			long long ans = 0;
			long long ans_2 = 0;
			for (int j = i;j <= q;++j) {
				ans = ans | hoge[j];
				ans_2 = ans_2 | hogehoge[j];
			}
			answer = max(ans+ans_2, answer);
		}
	}
	cout << answer << endl;
}
//thank you for reading my code! let's shout! SRM!SRM!SRM!SRM!SRM!SRM!SRM!SRM!