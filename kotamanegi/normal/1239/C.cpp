//J^!w

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
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 1e-5
#define LONG_INF 2000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144*2
#define REP(a,b) for(long long a = 0;a < b;++a)
long long ans[300000];
int main() {
	vector<pair<long long, long long>> vertexs;
	long long n, p;
	cin >> n >> p;
	REP(i, n) {
		long long a;
		cin >> a;
		vertexs.push_back(make_pair(a, i));
	}
	sort(vertexs.begin(), vertexs.end());
	reverse(vertexs.begin(), vertexs.end());
	long long now_time = 0;
	priority_queue<long long, vector<long long>, greater<long long>> next;
	queue<long long> now_going;
	int now_worst = LONG_INF;
	while (next.empty() == false || vertexs.empty() == false||now_going.empty() == false) {
		while (vertexs.size() != 0&&vertexs.back().first <= now_time) {
			int valueing = vertexs.back().second;
			if (now_worst > valueing) {
				now_going.push(valueing);
				now_worst = valueing;
			}
			else {
				next.push(vertexs.back().second);
			}
			vertexs.pop_back();
		}
		if(now_going.empty() == false){
			now_time += p;
			ans[now_going.front()] = now_time;
			now_going.pop();
			continue;
		}
		if (next.empty() == true) {
			now_time = vertexs.back().first;
			now_worst = LONG_INF;
		}
		else {
			now_going.push(next.top());
			now_worst = next.top();
			next.pop();
		}
	}
	REP(i, n) {
		if (i != 0)cout << " ";
		cout << ans[i];
	}
	cout << endl;
}