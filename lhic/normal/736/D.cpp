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

bitset<2001> bb[2001];
bitset<2001> br[2001];
int n, m;
int qa[510000];
int qb[510000];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", qa + i, qb + i);
		--qa[i];
		--qb[i];
		bb[qa[i]][qb[i]] = 1;
	}
	for (int i = 0; i < n; ++i)
		br[i][i] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			if (bb[j][i]) {
				swap(bb[i], bb[j]);
				swap(br[i], br[j]);
				break;
			}
		}
		for (int j = 0; j < n; ++j) {
			if (j != i && bb[j][i]) {
				bb[j] ^= bb[i];
				br[j] ^= br[i];
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		if (br[qb[i]][qa[i]])
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}