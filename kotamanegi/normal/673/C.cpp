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
int hoge[100000] = {};
int t[100000] = {};
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0;i < n;++i) {
		scanf("%d", &t[i]);
	}
	for (int i = 0;i < n;++i) {
		int wow[6000] = {};
		int now_max = 5900;
		for (int q = i;q < n;++q) {
			wow[t[q]]++;
			if (wow[t[q]] >= wow[now_max]) {
				if (wow[t[q]] > wow[now_max] || t[q] < now_max) {
					now_max = t[q];
				}
			}
			hoge[now_max]++;
		}
	}
	cout << hoge[1];
	for (int i = 2;i <= n;++i) {
		cout << " " << hoge[i];
	}
	cout << endl;
}