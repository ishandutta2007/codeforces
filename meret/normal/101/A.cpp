#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)

vector< pair<int, int> > counts;

bool deleted[255];
int got[255];

char s[100005];

int n, k;

int main() {
	scanf("%s %d", s, &k);
	n = strlen(s);
	for (int i = 0; i < n; ++i)
		++got[s[i]];
	for (int i = 'a'; i <= 'z'; ++i)
		counts.push_back(make_pair(got[i], i));
	sort(counts.begin(), counts.end());
	int z = 0;
	for (int i = 0; i < (int) counts.size(); ++i) {
		k -= counts[i].first;
		if (k < 0)
			break;
		++z;
		deleted[counts[i].second] = true;
	}
	printf("%d\n", 26 - z);
	for (int i = 0; i < n; ++i)
		if (!deleted[s[i]])
			putchar(s[i]);
	putchar('\n');
}