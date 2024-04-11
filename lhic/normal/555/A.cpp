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


typedef long long ll;
typedef long double ld;

using namespace std;

int n, k;
int a[120000];
int ans;

int main() {
	scanf("%d%d", &n, &k);
	ans = n - 1;
	int lst = 1;
	for (int i = 0; i < k; ++i) {
		int kk;
		scanf("%d", &kk);
		for (int j = 0; j < kk; ++j)
			scanf("%d", &a[j]);
		for (int j = 0; j < kk - 1; ++j)
			if (a[j] + 1 == a[j + 1] && a[j] == lst)
				--ans, ++lst;
			else
				++ans;
	}

	cout << ans;


	return 0;
}