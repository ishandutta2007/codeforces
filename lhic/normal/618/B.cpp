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
typedef double ld;

using namespace std;

int n;
int a[100][100];
int ans[100];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j], --a[i][j];
			if (i != j) {
				ans[i] = max(ans[i], a[i][j]);
				ans[j] = max(ans[j], a[i][j]);
			}
		}
	for (int i = 0; i < n; ++i)
		if (ans[i] == n - 2) {
			++ans[i];
			break;
		}
	for (int i = 0; i < n; ++i)
		cout << ans[i] + 1 << " ";
	return 0;
}