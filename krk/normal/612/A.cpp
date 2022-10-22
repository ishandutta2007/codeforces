#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, p, q;
string s;

int main() 
{
	cin >> n >> p >> q;
	cin >> s;
	for (int i = 0; i * p <= n; i++)
		for (int j = 0; i * p + j * q <= n; j++) if (i * p + j * q == n) {
			printf("%d\n", i + j);
			int pnt = 0;
			for (int k = 0; k < i; k++) {
				printf("%s\n", s.substr(pnt, p).c_str()); pnt += p;
			}
			for (int k = 0; k < j; k++) {
				printf("%s\n", s.substr(pnt, q).c_str()); pnt += q;
			}
			return 0;
		}
	printf("-1\n");
    return 0;
}