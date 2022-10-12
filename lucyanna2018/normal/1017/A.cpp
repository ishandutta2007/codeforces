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
pair<int, int> a[111111];
int main() {
	int n,x;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int res = 0;
		for (int j = 0; j < 4; j++) {
			scanf("%d", &x);
			res += x;
		}
		a[i] = make_pair(-res, i);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)if (a[i].second == 1)
		printf("%d\n", i);
	return 0;
}