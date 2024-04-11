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
	int n;
	string hoge;
	cin >> n >> hoge;
	int ans = 0;
	for (int i = 0;i < n;++i) {
		for (int q = i;q < n;++q) {
			int x = 0, y = 0;
			for (int j = i;j < q+1;++j) {
				if (hoge[j] == 'U') {
					y++;
				}
				else if (hoge[j] == 'R') {
					x++;
				}
				else if (hoge[j] == 'D') {
					y--;
				}
				else {
					x--;
				}
			}
			if (x == 0 && y == 0) ans++;
		}
	}
	cout << ans << endl;
}