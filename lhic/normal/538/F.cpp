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

const int MAXN = 300000;

const int SQ = 300;

int n;

int arr[MAXN];

int ad[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < min(SQ, i); ++j) {
			if (arr[j] > arr[i]) {
				int l, r;
				if (j != 0)
					r = (i - 1) / j;
				else
					r = n;
				l = (i - 1) / (j + 1) + 1;
				l = max(l, 1);
				//cout << i << " " << j << " " << l << " " << r << "\n";
				++ad[l];
				--ad[r + 1];
			}
		}
		for (int k = 1; (i - 1) / k >= SQ && k < n; ++k) {
			if (arr[(i - 1) / k] > arr[i])
				++ad[k], --ad[k + 1];
		}
	}

	int now = 0;
	for (int i = 1; i < n; ++i) {
		now += ad[i];
		printf("%d ", now);
	}

	return 0;
}