#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

struct st {
	ll cnt;
	ll dp[5];
	ll bc;
	st() {
		cnt = bc = 0;
		for (int i = 0; i < 5; ++i)
			dp[i] = 0;
	}
};

int was[210000];
ll gans = 0;
int n;
vector<int> eds[210000];
int k;

st dfs1(int v) {
	was[v] = 1;
	st now;
	now.cnt = 1;
	now.dp[0] = 1;
	for (int u: eds[v]) {
		if (was[u])
			continue;
		st tmp = dfs1(u);
		rotate(tmp.dp, tmp.dp + k - 1, tmp.dp + k);
		tmp.bc += tmp.dp[0];
		gans += tmp.bc * now.cnt;
		gans += tmp.cnt * now.bc;
		for (int i = 0; i < k; ++i)
			for (int j = 0; j < k; ++j)
				gans += tmp.dp[i] * now.dp[j] * ((i + j + k - 1) / k);
		now.cnt += tmp.cnt;
		now.bc += tmp.bc;
		for (int i = 0; i < k; ++i)
			now.dp[i] += tmp.dp[i];
	}
	return now;
}



int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	dfs1(0);
	cout << gans << "\n";
	return 0;
}