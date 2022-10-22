#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxb = 31;

int n;
map <int, int> M;
ll res; 

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		M[a]++;
	}
	for (int i = 0; i < Maxb; i++)
		for (map <int, int>::iterator it = M.begin(); it != M.end(); it++)
			if (it->first <= (1 << i)) {
				int nd = (1 << i) - it->first;
				if (nd == it->first) res += ll(it->second) * (it->second - 1);
				else if (M.find(nd) != M.end()) res += ll(it->second) * M[nd];
			}
	printf("%I64d\n", res / 2);
	return 0;
}