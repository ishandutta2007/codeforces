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
double calculate[11000][1100] = {};
vector<double> ans;
int main() {
	int k, wow;
	cin >> k >> wow;
	calculate[0][0] = 1.0;
	for (int i = 0;i < 10600;++i) {
		for (int q = 0;q <= k;++q) {
			calculate[i + 1][q + 1] += calculate[i][q] * (double)(k - q) / (double)(k);
			calculate[i+1][q] += calculate[i][q] * (1.0 - ((double)(k - q) / (double)(k)));
		}
		ans.push_back(calculate[i + 1][k]);
	}
	for (int i = 0;i < wow;++i) {
		double motome = 0;
		cin >> motome;
		motome /= 2000;
		int top = ans.size();
		int bot = 0;
		while (top - bot > 1) {
			int mid = top + bot;
			mid /= 2;
			if (ans[mid] > motome) {
				top = mid;
			}else{
				bot = mid;
			}
		}
		if (ans[bot] > motome) {
			cout << bot + 1 << endl;
		}else{
			cout << top + 1 << endl;
		}
	}
	return 0;
}