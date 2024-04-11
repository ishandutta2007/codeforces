#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>
#include<stack>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<sstream>
#include<bitset>
#include<numeric>
#include<climits>
#include<cassert>
#include<complex>
#include<functional>
using namespace std;

typedef long long ll;
template<typename A,typename B>inline void chmin(A &a, B b) { if (a > b)a = b; }
template<typename A,typename B>inline void chmax(A &a, B b) { if (a < b)a = b; }

int N, K;

int main() {
	scanf("%d%d", &N, &K);
	vector<pair<int, int>>vec;
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		vec.push_back(pair<int, int>(a, 0));
		vec.push_back(pair<int, int>(b, 1));
	}

	sort(vec.begin(), vec.end());

	int sum = 0;
	bool ok = false;
	int prev;

	vector<pair<int, int>>ans;
	int cur = 0;
	while (cur < vec.size()) {
		int next = cur;
		while (next < vec.size() && vec[cur].first == vec[next].first&&vec[next].second == 0) {
			sum++;
			next++;
		}
		if (sum >= K) {
			if (!ok) {
				prev = vec[cur].first;
				ok = true;
			}
		}

		while (next < vec.size() && vec[cur].first == vec[next].first&&vec[next].second == 1) {
			sum--;
			next++;
		}

		if (sum < K) {
			if (ok) {
				ans.push_back(pair<int, int>(prev, vec[cur].first));
				ok = false;
			}
		}
		cur = next;
	}

	printf("%d\n", (int)ans.size());
	for (int i = 0; i < ans.size(); i++)printf("%d %d\n", ans[i].first, ans[i].second);

	return 0;
}