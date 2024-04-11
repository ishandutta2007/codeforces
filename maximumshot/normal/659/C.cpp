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
#include <list>
#include <stack>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

bool solve() {

	int n, m;

	scanf("%d %d", &n, &m);

	vec< int > a(n + 1);
	for(int i = 1;i <= n;i++) {
		scanf("%d", &a[i]);
	}

	sort(a.begin() + 1, a.end());

	vec< int > ans;

	for(int s = 0, j = 1, i = 1;i <= inf;i++) {
		while(j <= n && a[j] < i) j++;
		if(j <= n && a[j] == i) continue;
		if(s + i <= m) s += i, ans.push_back(i);
		else break;
	}

	printf("%d\n", (int)ans.size());
	for(int i = 0;i < (int)ans.size();i++) printf("%d ", ans[i]);
	printf("\n");

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}