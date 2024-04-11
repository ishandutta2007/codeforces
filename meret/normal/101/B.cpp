#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)

const int N = 100005;

const int MD = 1e9 + 7;

int n, m;

struct Bus {
	int start, end;
	int nno;
};

bool operator < (Bus a, Bus b) {
	return a.end < b.end;
}

Bus buses[N];

pair<int, int> finish[N];

int dp[N];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &buses[i].start, &buses[i].end);
		buses[i].nno = i;
		finish[i] = make_pair(buses[i].start, i);
	}
	sort(buses, buses + m);
	for (int i = 0; i < m; ++i)
		finish[buses[i].nno].second = i;
	sort(finish, finish + m);
	int curFinish = m - 1;
	int sum = 0;
	for (int i = m - 1; i >= 0; --i) {
		while (curFinish >= 0 && finish[curFinish].first > buses[i].end) {
			sum = (MD + sum - dp[finish[curFinish].second]) % MD;
			--curFinish;
		}
		if (buses[i].end == n)
			dp[i] = 1;
		else
			dp[i] = sum;
		if (i > 0 && buses[i].end > buses[i - 1].end) {
			int j = i;
			while (j + 1 < m && buses[j + 1].end == buses[j].end)
				++j;
			for (int k = i; k <= j; ++k)
				sum = (sum + dp[k]) % MD;
		}
	}
	int result = 0;
	for (int i = 0; i < m; ++i)
		if (buses[i].start == 0)
			result = (result + dp[i]) % MD;
	printf("%d\n", result);
}