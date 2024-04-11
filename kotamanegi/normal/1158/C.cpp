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
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000000000000000000000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
map<pair<long long, long long>, long long> memo;
long long power(long long a,long long now) {
	if (memo[make_pair(a, now)]) return memo[make_pair(a, now)];
	long long ans = 1;
	pair<int, int> base = make_pair(a, now);
	while (now != 0) {
		if (now % 2 == 1) {
			ans *= a;
			ans %= MOD;
		}
		now /= 2;
		a *= a;
		a %= MOD;
	}
	return memo[base] = ans;
}
long long inv(long long a) {
	return power(a, MOD - 2);
}
long long permutation(long long a, long long b) {
	long long ans = 1;
	for (long long i = 0; i < b; ++i) {
		ans *= (a - i);
		ans %= MOD;
	}
	return ans;
}
long long combination(long long a, long long b) {
	long long ans = 1;
	for (long long i = 0; i < b; ++i) {
		ans *= (a - i);
		ans %= MOD;
		ans *= inv(i + 1);
		ans %= MOD;
	}
	return ans;
}
int backing[600000];
int find_back(int now) {
	if (now == -1||backing[now] == now) return now;
	return backing[now] = find_back(backing[now]);
}
int main() {
	int test_case;
	scanf("%d", &test_case);
	REP(teast, test_case) {
		int n;
		scanf("%d", &n);
		REP(i, n + 2) {
			backing[i] = i;
		}
		vector<vector<int>> vertexs;
		vector<int> input;
		REP(i, n + 1) {
			vertexs.push_back(vector<int>());
		}
		REP(i, n) {
			int tmp;
			scanf("%d", &tmp);
			tmp--;
			input.push_back(tmp);
		}
		vector<int> visiting;
		REP(i, n + 1) {
			visiting.push_back(0);
		}
		for (int i = n - 1; i >= 0; --i) {
			if (input[i] == -2) {
				vertexs[i + 1].push_back(i);
				visiting[i]++;
				continue;
			}
			vertexs[input[i]].push_back(i);
			visiting[i] += 1;
			int nowing = input[i] - 1;
			while (nowing > i) {
				if (backing[nowing] == nowing) {
					vertexs[i].push_back(nowing);
					visiting[nowing]++;
					backing[nowing] = nowing - 1;
				}
				nowing = find_back(nowing);
			}
		}
		vector<int> topological_sort;
		topological_sort.push_back(n);
		for (int i = 0; i < topological_sort.size(); ++i) {
			int now = topological_sort[i];
			for (int q = 0; q < vertexs[now].size(); ++q) {
				visiting[vertexs[now][q]]--;
				if (visiting[vertexs[now][q]] == 0) {
					topological_sort.push_back(vertexs[now][q]);
				}
			}
		}
		if (topological_sort.size() != n + 1) {
			cout << -1 << endl;
			continue;
		}
		vector<int> ans;
		REP(i, n) {
			ans.push_back(0);
		}
		int now_ans = n;
		for (int i = 1; i < topological_sort.size(); ++i) {
			ans[topological_sort[i]] = now_ans;
			now_ans--;
		}
		REP(i, n) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}