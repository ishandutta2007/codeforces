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
#define i64 long long int
i64 calc(i64 n, i64 x, i64 y) {
	if ((x + y) % 2 == 0) {
		i64 c = x / 2 * n + y/2;
		return c + (x % 2 ? (n + 1) / 2 : 0);
	}
	else {
		i64 c = (n * n + 1) / 2 + x / 2 * n + y / 2;
		return c + (x % 2 ? n / 2 : 0);
	}
}
int main() {
	ios::sync_with_stdio(false);
	i64 n,x,y;int q;
	for (cin >> n >> q; q--;) {
		cin >> x >> y;
		cout << calc(n, x-1, y-1) + 1 << endl;
	}
	return 0;
}