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

const int Maxn = 100005;

int n;
set <int> S;
int my[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int p; scanf("%d", &p);
		set <int>::iterator it = S.end(), it2;
		if (it == S.begin()) my[p]--;
		else {
			it--;
			if (*it < p) my[p]--;
			 else {
			 	it2 = it;
			 	if (it2 != S.begin()) {
			 		it2--;
			 		if (*it2 < p) my[*it]++;
			 	} else my[*it]++;
			 }
		}
		S.insert(p);
	}
	int i = 1;
	for (int j = 2; j <= n; j++)
		if (my[j] > my[i]) i = j;
	printf("%d\n", i);
	return 0;
}