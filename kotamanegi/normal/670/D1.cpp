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
#include <cstdint>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
tuple<long long, long long, long long> bake[200000];
long long ruikei[200000] = {};
int main() {
	int n, k;
	scanf("%I64d%I64d", &n, &k);
	REP(i, n) {
		scanf("%I64d", &get<1>(bake[i]));
	}
	REP(i, n) {
		scanf("%I64d", &get<2>(bake[i]));
	}
	long long ans = 0;
	REP(i, n) {
		get<0>(bake[i]) = get<2>(bake[i]) / get<1>(bake[i]);
	}
	sort(bake, bake + n);
	get<0>(bake[n]) = 1999999999999;
	get<1>(bake[n]) = 0;
	get<2>(bake[n]) = 0;
	n += 1;
	for (int i = 0;i < n;++i) {
		if (i != 0) {
			ruikei[i] = ruikei[i - 1] + get<1>(bake[i]);
		}
		else {
			ruikei[i] = get<1>(bake[i]);
		}
	}
	for (int i = 0;i < n;++i) {
		if (i == 0) {
			ans += get<0>(bake[i]);
		}
		else {
			if (get<0>(bake[i]) != get<0>(bake[i-1])) {
				long long next_time_need = 0;
				for (int q = i - 1;q >= 0;--q) {
					next_time_need += get<1>(bake[q])-(get<2>(bake[q]) % get<1>(bake[q]));
					if (q == 0 || get<0>(bake[q]) != get<0>(bake[q - 1])) break;
				}
				if (k < next_time_need) {
					cout << ans << endl;
					return 0;
				}
				k -= next_time_need;
				ans++;
				ans = min((long long)get<0>(bake[i]), ans + (k / ruikei[i-1]));
				if (ans != get<0>(bake[i])) {
					cout << ans << endl;
					return 0;
				}
				k -= ruikei[i - 1] * (ans - get<0>(bake[i-1]));
			}
		}
	}

	return 0;
}