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
string s;
int L, R, U, D;

int main()
{
	scanf("%d", &n);
	cin >> s;
	for (int i = 0; i < n; i++)
		if (s[i] == 'L') L++;
		else if (s[i] == 'R') R++;
		else if (s[i] == 'U') U++;
		else if (s[i] == 'D') D++;
	printf("%d\n", 2 * (min(L, R) + min(U, D)));
	return 0;
}