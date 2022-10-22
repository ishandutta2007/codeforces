#define  _CRT_SECURE_NO_WARNINGS
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
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
int main() {
	int cnt = 2;
	int n;
	cin >> n;
	cout << "? 1" << endl;
	int a;
	cin >> a;
	cout << "? " << n / 2 + 1 << endl;
	int b;
	cin >> b;
	int now = b - a;
	if (now == 0) {
		cout << "! 1" << endl;
		return 0;
	}
	int now_bot = 1;
	int now_top = n / 2;
	while ((now_top - now_bot) > 1) {
		int mid = (now_bot + now_top) / 2;
		cout << "? " << mid << endl;
		int a;
		cin >> a;
		cout << "? " << mid + n / 2 << endl;
		int b;
		cnt += 4;
		assert(cnt <= 60);
		cin >> b;
		if (b - a == 0) {
			cout << "! " << mid << endl;
			return 0;
		}
		if (b - a > 0) {
			if (now > 0) {
				now_bot = mid;
			}
			else {
				now_top = mid;
			}
		}
		else {
			if (now < 0) {
				now_bot = mid;
			}
			else {
				now_top = mid;
			}
		}
	}
	for (int i = now_bot; i <= now_top; ++i) {
		cout << "? " << i << endl;
		int a = 0;
		cin >> a;
		cout << "? " << i + n / 2 << endl;
		cnt += 2;
		assert(cnt <= 60);
		int b;
		cin >> b;
		if (b - a == 0) {
			cout << "! " << i << endl;
			return 0;
		}
	}
	cout << "! -1" << endl;
	return 0;
}