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
#include<map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define LONG_INF 800000000000000000
int ans[200000] = {};
vector<int> numbers[200000] = {};
int gs[200000] = {};
int main() {
	int n;
	cin >> n;
	vector<int> a;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
		numbers[tmp].push_back(i+1);
	}
	int nya = 1;
	for (int i = 1;i <= n;++i) {
		if (numbers[i].size() != 0) {
			int cnt = 0;
			for (int q = 0;q < numbers[i].size();++q) {
				if (numbers[i][q] == i) {
					if (ans[numbers[i][q]] == 0) {
						cnt++;
					}
				}
			}
			if (cnt == 0) {
				cout << "-1" << endl;
				return 0;
			}
			gs[nya] = i;
			for (int q = 0;q < numbers[i].size();++q) {
				ans[numbers[i][q]] = nya;
			}
			nya++;
		}
	}
	cout << nya - 1 << endl;
	for (int q = 1;q <= n;++q) {
		cout << ans[q] << " ";
	}
	cout << endl;
	for (int q = 1;q < nya;++q) {
		cout << gs[q] << " ";
	}
	cout << endl;
	return 0;
}