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
bool comed[100000] = {};
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	if (n == 4||k <= n) {
		cout << "-1" << endl;
		return 0;
	}
	vector<int> first_man, second_man;
	int ok = 0;
	for (int i = 0;i < n;++i) {
		if (i == 0) {
			first_man.push_back(a);
			comed[a] = true;
		}
		else if (i == 1) {
			first_man.push_back(c);
			comed[c] = true;
			comed[b] = true;
			comed[d] = true;
		}
		else if (i == n - 2) {
			first_man.push_back(d);
		}
		else if (i == n - 1) {
			first_man.push_back(b);
		}
		else {
			for (int q = ok + 1;q <= n;++q) {
				if (comed[q] == false) {
					first_man.push_back(q);
					comed[q] = true;
					ok = q;
					goto lol;
				}
			}
		lol:;
		}
	}
	second_man.push_back(c);
	second_man.push_back(a);
	for (int i = 2;i < n-2;++i) {
		second_man.push_back(first_man[i]);
	}
	second_man.push_back(b);
	second_man.push_back(d);
	cout << first_man[0];
	for (int i = 1;i < n;++i) {
		cout << " " << first_man[i];
	}
	cout << endl;
	cout << second_man[0];
	for (int i = 1;i < n;++i) {
		cout << " " << second_man[i];
	}
	cout << endl;
}