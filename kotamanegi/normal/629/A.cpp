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
bool grid[200][200] = {};
int combination(int a,int b) {
	int hoge = a;
	for (int i = 2;i < b +1;++i) {
		hoge = hoge * (a-i+1);
		hoge = hoge / i;
	}
	return hoge;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0;i < n;++i) {
		string a;
		cin >> a;
		for (int q = 0;q < n;++q) {
			if (a[q] == 'C') {
				grid[i][q] = true;
			}
			else {
				grid[i][q] = false;
			}
		}
	}
	long long ans = 0;
	for (int i = 0;i < n;++i) {
		int hoge = 0;
		for (int q = 0;q < n;++q) {
			if (grid[i][q] == true) hoge++;
		}
		ans += combination(hoge, 2);
	}
	for (int i = 0;i < n;++i) {
		int hoge = 0;
		for (int q = 0;q < n;++q) {
			if (grid[q][i] == true) hoge++;
		}
		ans += combination(hoge, 2);
	}
	cout << ans << endl;
}
//thank you for reading my code!