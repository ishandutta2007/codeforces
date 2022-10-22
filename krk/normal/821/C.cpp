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

char str[20];
int val;
int n;
vector <int> V;
set <int> S;
int cur = 1;
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++) {
		scanf("%s", str);
		if (str[0] == 'a') {
			scanf("%d", &val); V.push_back(val);
		} else {
			if (!V.empty() && V.back() != cur) {
				res++;
				while (!V.empty()) {
					S.insert(V.back()); V.pop_back();
				}
				S.erase(S.begin());
			} else if (V.empty()) S.erase(S.begin());
				else V.pop_back();
			cur++;
		}
	}
	printf("%d\n", res);
	return 0;
}