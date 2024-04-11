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
	long long n = 0;
	scanf("%I64d", &n);
	long long a[100] = {};
	REP(i, n) { scanf("%I64d", &a[i]); }
	sort(a, a + n,greater<long long>());
	long long answer = a[0];
	long long max_now = a[0];
	for (int i = 1;i < n;++i) {
		if (max_now > a[i]) {
			max_now = a[i];
			answer += max_now;
		}
		else if (max_now == a[i]) {
			max_now = max_now - 1;
			if (max_now >= 1) {
				answer += max_now;
			}
			else {
				goto end;
			}
		}
		else {
			max_now = max_now - 1;
			if (max_now >= 1) {
				answer += max_now;
			}
			else {
				goto end;
			}
		}
	}
end:;
	printf("%I64d", answer);
}