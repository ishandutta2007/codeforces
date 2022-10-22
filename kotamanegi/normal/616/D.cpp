#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <algorithm>
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
using namespace std;
#define REP(a,b) for(int a = 0;a < b;++a)
int shaku[10000000] = {};
int canbe[10000000] = {};
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0;i < n;++i) {
		scanf("%d", &shaku[i]);
	}
	int max_length = 0;
	int max_first = 0;
	int max_end = 0;
	int now_length = 0;
	int diff_now = 0;
	int now_point = 0;
	for (int i = 0;i < n;++i) {
		if (canbe[shaku[i]] >= 1) {
			now_length++;
			canbe[shaku[i]]++;
		}
		else {
			if (diff_now != k) {
				canbe[shaku[i]]++;
				now_length++;
				diff_now++;
			}
			else {
				for (int q = now_point;q < n;++q) {
					canbe[shaku[now_point]]--; now_point++; now_length--;
					if (now_point == n||q >= i) goto end;
					if (canbe[shaku[now_point - 1]] == 0) break;
				}
				canbe[shaku[i]]++;
				now_length++;
			}
		}
		if (now_length > max_length) {
			max_first = now_point;
			max_end = i;
			max_length = now_length;
		}
	}
end:;
	printf("%d %d", max_first + 1, max_end + 1);
	return 0;
}