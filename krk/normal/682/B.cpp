#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int n;
multiset <int> S;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		S.insert(a);
	}
	for (int i = 1; ; i++) {
		multiset <int>::iterator it = S.lower_bound(i);
		if (it == S.end()) { printf("%d\n", i); return 0; }
		else S.erase(it);
	}
	return 0;
}