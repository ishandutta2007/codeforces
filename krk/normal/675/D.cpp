#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

int n;
set <ii> S;

int main()
{
	scanf("%d", &n);
	int a; scanf("%d", &a); n--;
	S.insert(ii(0, 0)); S.insert(ii(2000000000, 0));
	S.insert(ii(a, 1));
	while (n--) {
		scanf("%d", &a);
		set <ii>::iterator it1 = S.lower_bound(ii(a, 0)), it2;
		it2 = it1; it1--;
		int res = it1->second > it2->second? it1->first: it2->first;
		int lvl = max(it1->second, it2->second);
		S.insert(ii(a, lvl + 1));
		printf("%d%c", res, n? ' ': '\n');
	}
	return 0;
}