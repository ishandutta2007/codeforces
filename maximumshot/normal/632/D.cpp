#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);
	
bool solve() {
		
	int n, m;

	scanf("%d %d", &n, &m);
		
	vec< int > cnt(m + 1), dp(m + 1);
	vec< vec< int > > id(m + 1);

	for(int x, i = 0;i < n;i++) {
		scanf("%d", &x);
		if(x <= m) cnt[x]++, id[x].push_back(i);
	}

	for(int x = 1;x <= m;x++) {
		for(int y = x;y <= m;y += x) dp[y] += cnt[x];
	}

	int value = -1;
	for(int i = 1;i <= m;i++) {
		if(value == -1 || dp[value] < dp[i]) {
			value = i;
		}
	}

	printf("%d %d\n", value, dp[value]);

	vec< int > way;

	for(int x = 1;x <= m;x++) {
		if(value % x == 0) {
			for(auto cur : id[x]) way.push_back(cur + 1);
		}
	}
	
	sort(ALL(way));

	for(auto cur : way) printf("%d ", cur);
	printf("\n");

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}