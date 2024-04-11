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

int n, m;
vector <int> res;

int main() 
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= 2 * n; i++) {
		if (2 * n + i <= m) res.push_back(2 * n + i);
		if (i <= m) res.push_back(i);
	}
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}