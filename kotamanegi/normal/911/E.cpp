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
#define LONG_INF 2000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> wow;
	map<int,int> woa;
	REP(i, k) {
		int tmp;
		cin >> tmp;
		woa[tmp]++;
		wow.push_back(tmp);
	}
	stack<int> as;
	int nowing = 1;
	for (int i = 0;i < k;++i) {
		as.push(wow[i]);
		while (as.empty() == false&&as.top() == nowing) {
			as.pop();
			nowing++;
		}
	}
	int nya = 0;
	while (as.empty() == false) {
		if (as.top() < nya) {
			cout << -1 << endl;
			return 0;
		}
		nya = as.top();
		as.pop();
	}
	woa[0] = 1;
	for (int i = 0;i < k;++i) {
		cout << wow[i] << " ";
	}
	for (int i = 1;i <= n;++i) {
		if (woa[i] == 1 && woa[i - 1] != 1) {
			int cnt = i - 1;
			while (woa[cnt] == 0) {
				woa[cnt]++;
				cout << cnt << " ";
				cnt--;
			}
		}
	}
	int cnt = n;
	while (woa[cnt] == 0) {
		woa[cnt]++;
		cout << cnt << " ";
		cnt--;
	}
	cout << endl;
	return 0;
}