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

int n;
int a;
int mn;
vector <int> V;

int main()
{
	mn = 2000000007;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (a < mn) { mn = a; V.clear(); }
		if (a == mn) V.push_back(i);
	}
	mn = 2000000007;
	for (int i = 0; i + 1 < V.size(); i++)
		mn = min(mn, V[i + 1] - V[i]);
	printf("%d\n", mn);
	return 0;
}