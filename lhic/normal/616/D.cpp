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

const int MAXN = 510000;


int n, k;
int arr[MAXN];

int cc[1000010];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);
	int bl = 0;
	int br = 0;
	int now = 0;
	int nk = 0;
	for (int i = 0; i < n; ++i) {
		while (now < n && (nk < k || (nk == k && cc[arr[now]] != 0))) {
			if (cc[arr[now]] == 0)
				++nk;
			++cc[arr[now]];
			++now;
		}
		if (now - i > br - bl)
			bl = i, br = now;
		--cc[arr[i]];
		if (cc[arr[i]] == 0)
			--nk;
	}

	printf("%d %d\n", bl + 1, br);

	return 0;
}