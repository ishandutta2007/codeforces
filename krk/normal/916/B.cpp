#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxb = 62;

ll n;
int k;
int has;
map <ll, int> M;

int main()
{
	scanf("%I64d", &n);
	for (int i = 0; i < Maxb; i++)
		if (n & 1ll << ll(i)) { has++; M[i]++; }
	scanf("%d", &k);
	if (has > k) { printf("No\n"); return 0; }
	while (has < k) {
		map <ll, int>::iterator it = M.end(); it--;
		int tk = min(k - has, it->second);
		if (tk < it->second) break;
		M[it->first - 1] += 2 * tk; has += tk;
		M.erase(it);
	}
	while (has < k) {
		map <ll, int>::iterator it = M.begin();
		M[it->first - 1] += 2; has++;
		it->second--;
		if (it->second == 0) M.erase(it);
	}
	vector <ll> res;
	for (map <ll, int>::iterator it = M.begin(); it != M.end(); it++)
		while (it->second--) res.push_back(it->first);
	printf("Yes\n");
	for (int i = int(res.size()) - 1; i >= 0; i--)
		printf("%I64d%c", res[i], i - 1 >= 0? ' ': '\n');
	return 0;
}