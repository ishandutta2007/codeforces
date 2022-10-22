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
	int n, b, d;
	cin >> n >> b >> d;
	vector<int> a;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	int cnt = 0;
	int now_size = 0;
	for (int i = 0;i < n;++i) {
		if (a[i] <= b) {
			now_size += a[i];
			if (now_size > d) {
				now_size = 0;
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}