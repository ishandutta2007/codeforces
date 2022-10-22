#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<queue>
#include<math.h>
#include<deque>

#define ll long long
#define ld long double

using namespace std;

const int inf = 1e5 + 5;
void solve() {
	int n, k;
	scanf("%d%d", &n, &k);
	vector<ll> values(n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &values[i]);
	vector<pair<ll, int> > possibilities;
	possibilities.reserve(n * k + 3);
	possibilities.emplace_back(0, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			possibilities.emplace_back(values[i] * j, j);
		}
	}
	sort(possibilities.begin(), possibilities.end());
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		ll sum;
		scanf("%lld", &sum);
		int best_result = inf;
		for (int j = 0; j < (int)possibilities.size(); j++) {
			if (possibilities[j].first > sum)
				break;
			ll rem = sum - possibilities[j].first;
			auto it = lower_bound(possibilities.begin(), possibilities.end(), make_pair(rem, 0));
			while (it != possibilities.end() && it->first == rem) {
				best_result = min(best_result, it->second + possibilities[j].second);
				it++;
			}
		}
		if (best_result > k)
			printf("-1\n");
		else
			printf("%d\n", best_result);
	}

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	solve();
}