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
#define seg_size 262144
#define REP(a,b) for(long long a = 0;a < b;++a)
int main() {
#define int long long
	iostream::sync_with_stdio(false);
	long long n;
	cin >> n;
	vector<tuple<long long, long long, long long>> inputs;
	long long now_max = 0LL;
	REP(i, n) {
		long long a, b, c;
		cin >> a >> b >> c;
		now_max = max(now_max, b - c + 1LL);
		inputs.push_back(make_tuple(a, b - c, c));
	}
	sort(inputs.begin(), inputs.end(), [](const auto& l, const auto& r) {
		if (get<0>(l) + get<2>(l) != get<0>(r) + get<2>(r)) {
			return get<0>(l) + get<2>(l) < get<0>(r) + get<2>(r);
		}
		else {
			return get<0>(l) < get<0>(r);
		}
	});
	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> next;
	long long now_time = 0;
	long long ans = 0;
	long long now_itr = 0;
	while (now_time < now_max) {
		while (next.empty() == false&&next.top().second < now_time) {
			next.pop();
		}
		if (next.empty() == true) {
			now_time = max(get<0>(inputs[now_itr]),now_time);
			next.push(make_pair(get<2>(inputs[now_itr]), get<1>(inputs[now_itr])));
			now_itr++;
			continue;
		}
		long long next_go = (next.top().second - now_time) / next.top().first;
		if (now_itr == n) {
			//no choice
			ans += (next_go+1LL);
			now_time += (next_go + 1LL) * next.top().first;
			continue;
		}
		next_go = min(next_go, (get<0>(inputs[now_itr]) - now_time) / next.top().first);
		if (next_go > 0) {
			ans += next_go;
			now_time += next_go * next.top().first;
			continue;
		}
		if (now_time + next.top().first < get<0>(inputs[now_itr]) + get<2>(inputs[now_itr])) {
			ans++;
			now_time += next.top().first;
			continue;
		}
		else {
			next.push(make_pair(get<2>(inputs[now_itr]), get<1>(inputs[now_itr])));
			now_time = max(now_time, get<0>(inputs[now_itr]));
			now_itr++;
		}
	}
	cout << ans << endl;
}