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
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <cstdlib>
#define EVAL 1
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
#define PI 3.1415926535
int main() {
	iostream::sync_with_stdio(false);
	long long p, k;
	cin >> p >> k;
	vector<long long> wow;
	vector<long long> ans;
	wow.push_back(p / k);
	ans.push_back(p - wow[0]*k);
	for (int i = 1;i <= 1000000;++i) {
		if (i % 2 == 1) {
			long long getting = wow[i - 1];
			wow.push_back((getting + k - 1) / k);
			ans.push_back(k * wow[i] - getting);
		}
		else {
			long long getting = wow[i - 1];
			wow.push_back(getting / k);
			ans.push_back(getting - wow[i]*k);
		}
		if (wow[i] == 0) break;
	}
	if (wow[wow.size()-1] != 0) {
		cout << -1 << endl;
		return 0;
	}
	while (ans[ans.size() - 1] == 0) {
		ans.pop_back();
	}
	cout << ans.size() << endl;
	for (int i = 0;i < ans.size();++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}