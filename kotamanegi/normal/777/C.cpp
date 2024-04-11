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
long long hogee[200000] = {};
long long now_value[200000] = {};
long long now_back[200000] = {};
int main() {
#define int long long
	iostream::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0;i < n;++i) {
		for (int q = 0;q < m;++q) {
			int tmp;
			cin >> tmp;
			if (now_value[q] <= tmp) {
				now_value[q] = tmp;
			}
			else {
				hogee[now_back[q]] = max(hogee[now_back[q]], i-1);
				now_back[q] = i;
				now_value[q] = tmp;
			}
		}
	}
	for (int i = 0;i < m;++i) {
		hogee[now_back[i]] = max(hogee[now_back[i]],n-1);
	}
	for (int i = 1;i < n;++i) {
		hogee[i] = max(hogee[i], hogee[i - 1]);
	}
	int k;
	cin >> k;
	for (int i = 0;i < k;++i) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		if (hogee[a] >= b) {
			cout << "Yes" << endl;
		}
		else cout << "No" << endl;
	}
	return 0;
}