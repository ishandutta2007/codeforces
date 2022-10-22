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
#include <random>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define LONG_INF 10000000000000000
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
int done[10000] = {};
int main() {
	int n, k;
	cin >> n >> k;
	int now = 0;
	for (int i = 0;i < k;++i) {
		int tmp;
		cin >> tmp;
		tmp %= (n - i);
		for (int q = 0;q < tmp;++q) {
			while (true) {
				now++;
				now %= n;
				if (done[now] == false) break;
			}
		}
		if (i != 0) cout << " ";
		cout << now+1;
		done[now] = true;
		while (true) {
			now++;
			now %= n;
			if (done[now] == false) break;
		}
	}
	cout << endl;
	return 0;
}