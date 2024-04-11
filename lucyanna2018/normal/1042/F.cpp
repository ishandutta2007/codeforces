#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
#define ran 1000010
int n, K;
vector<int> e[ran];
int dp1[ran], dp2[ran];
void dfs(int x,int fat) {
	if (e[x].size() == 1) {
		dp1[x] = 1;
		dp2[x] = 0;
		return;
	}
	dp1[x] = 0;
	dp2[x] = 0;
	vector<int> cur;
	for (auto y : e[x]) {
		if (y == fat)continue;
		dfs(y, x);
		dp1[x] += dp1[y];
		cur.push_back(dp2[y] + 1);
	}
	sort(cur.begin(), cur.end());
	int L = cur.size();
	if (L == 1 || cur[L - 1] + cur[L - 2] <= K) {
		dp1[x] -= L - 1;
		dp2[x] = cur[L - 1];
	}else
	for(int i=1; i<L; i++)
		if (cur[i] + cur[i - 1] > K) {
			dp1[x] -= i - 1;
			dp2[x] = cur[i - 1];
			break;
		}
}
int main() {
	scanf("%d%d", &n, &K);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	int r = 1;while (e[r].size() == 1)r++;
	dfs(r, r);
	printf("%d\n", dp1[r]);
	return 0;
}