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

struct Edge {
	int dest, cost;

	Edge (int _dest, int _cost) :dest(_dest), cost(_cost) {};
};

vector<Edge> e[N];
int n;

long long dp[N];
int timeSpent[N];
int size[N];
bool visited[N];

struct Entry {
	int timeSpent, size;

	Entry (int _timeSpent, int _size) :timeSpent(_timeSpent), size(_size) {}
};

bool operator < (Entry a, Entry b) {
	return a.timeSpent * (long long) b.size < b.timeSpent * (long long) a.size;
}

void dfs(int x) {
	visited[x] = true;
	vector<Edge> sons;
	FOREACH (it, e[x]) {
		if (!visited[it->dest]) {
			sons.push_back(*it);
			dfs(it->dest);
		}
	}
	vector<Entry> v;
	size[x] = 1;
	FOREACH (it, sons) {
		size[x] += size[it->dest];
		dp[x] += dp[it->dest] + it->cost * size[it->dest];
		timeSpent[x] += timeSpent[it->dest] + 2 * it->cost;
		v.push_back(Entry(timeSpent[it->dest] + 2 * it->cost, size[it->dest]));
	}
	sort(v.begin(), v.end());
	int totalTime = 0;
	FOREACH (it, v) {
		dp[x] += it->size * (long long) totalTime;
		totalTime += it->timeSpent;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		e[a].push_back(Edge(b, cost));
		e[b].push_back(Edge(a, cost));
	}
	dfs(1);
	printf("%.9lf\n", (double ((long double) dp[1] / (long double) (n - 1))));
}