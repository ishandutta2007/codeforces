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

int main()
{
	int mx = 0;
	scanf("%d", &n);
	while (cin >> s) {
		int cand = 0;
		for (int i = 0; i < s.length(); i++)
			cand += isupper(s[i]);
		mx = max(mx, cand);
	}
	printf("%d\n", mx);
	return 0;
}