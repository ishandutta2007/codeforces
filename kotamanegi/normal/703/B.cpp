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
long long n[200000] = {};
long long sum = 0;
bool counter[200000] = {};
bool consider[200000] = {};
int main() {
	int nn, kk;
	cin >> nn >> kk;
	for (int i = 1;i <= nn;++i) {
		long long a;
		cin >> a;
		n[i] = a;
		sum += a;
	}
	REP(i, kk) {
		int a;
		cin >> a;
		counter[a] = true;
	}
	long long ans = n[1] * n[nn];
	for (int i = 1;i < nn;++i) {
		ans += n[i] * n[i + 1];
	}
	for (int i = 1;i <= nn;++i) {
		if (counter[i] == true) {
			sum -= n[i];
			consider[i] = true;
			long long pre_ans = sum;
			if (i == 1) {
				if (consider[nn] == false) {
					pre_ans -= n[nn];
				}
			}
			else {
				if (consider[i - 1] == false) {
					pre_ans -= n[i - 1];
				}
			}
			if (i == nn) {
				if (consider[1] == false) {
					pre_ans -= n[1];
				}
			}
			else {
				if (consider[i + 1] == false) {
					pre_ans -= n[i + 1];
				}
			}
			ans	+= pre_ans * n[i];
		}
	}
	cout << ans << endl;
}