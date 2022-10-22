#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxn = 85;

int n, k;
int a[Maxn];
set <int> S;
int res;

int Nxt(int book, int from)
{
	for (int i = from; i < n; i++)
		if (a[i] == book) return i;
	return n;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		if (S.find(a[i]) == S.end()) {
			res++;
			if (S.size() == k) {
				int rem = -1, mx = -1;
				for (set <int>::iterator it = S.begin(); it != S.end(); it++) {
					int cand = Nxt(*it, i);
					if (cand > mx) { mx = cand; rem = *it; }
				}
				S.erase(rem);
			}
			S.insert(a[i]);
		}
	printf("%d\n", res);
	return 0;
}