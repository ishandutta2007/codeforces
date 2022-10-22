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
int hogehoge[200000] = {};
int main() {
	int n, k, h;
	scanf("%d%d%d", &n, &h, &k);
	long long ans = 0;
	long long now_height = 0;
	REP(i, n) {
		scanf("%d", &hogehoge[i]);
	}
	hogehoge[n] = 0;
	for (int i = 0;i < n;++i) {
		now_height += hogehoge[i];
		if (hogehoge[i + 1] > h - now_height) {
			long long need = now_height + hogehoge[i + 1] - h;
			long long pre_ans = need / k;
			if (need % k != 0) {
				pre_ans++;
			}
			ans += pre_ans;
			now_height -= pre_ans * k;
			if (now_height < 0) now_height = 0;
		}
	}
	ans += now_height / k;
	if(now_height %k != 0) ans++;
	cout << ans << endl;
}