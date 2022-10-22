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
#define LONG_INF 100000000000000
int preform[1000] = {};
int main() {
	int n, q;
	cin >> n >> q;
	int ns = 0;
	for (int i = 0;i < q;++i) {
		int a, b, c;
		cin >> a >> b >> c;
		a -= ns;
		ns += a;
		for (int j = 0;j < n;++j) {
			preform[j] = max(0, preform[j] - a);
		}
		int sum = 0;
		vector<int> gogo;
		for (int j = 0;j < n;++j) {
			if (preform[j] == 0) {
				gogo.push_back(j);
				if (gogo.size() == b) goto ok;
			}
		}
		cout << -1 << endl;
		goto failed;
	ok:;
		for (int i = 0;i < gogo.size();++i) {
			sum += gogo[i] + 1;
			preform[gogo[i]] = c;
		}
		cout << sum << endl;
	failed:;
	}
	return 0;
}