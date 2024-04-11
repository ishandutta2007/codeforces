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
int main() {
	int n, k;
	cin >> n >> k;
	string pro;
	cin >> pro;
	long long ans = 0;
	long long now_counter = 0;
	long long dist = 0;
	for (int i = 0;i < n;++i) {
		if (pro[i] == 'b') {
			now_counter++;
			if (now_counter > k) {
				while (now_counter > k) {
					if (dist > i) goto waw;
					if (pro[dist] == 'b') {
						now_counter--;
					}
					dist++;
				}
			}
		}
		ans = max(ans, i - dist + 1);
	}
waw:;
	now_counter = 0;
	dist = 0;
	for (int i = 0;i < n;++i) {
		if (pro[i] == 'a') {
			now_counter++;
			if (now_counter > k) {
				while (now_counter > k) {
					if (dist > i) goto ah;
					if (pro[dist] == 'a') {
						now_counter--;
					}
					dist++;
				}
			}
		}
		ans = max(ans, i - dist + 1);
	}
ah:;
	cout << ans << endl;
}