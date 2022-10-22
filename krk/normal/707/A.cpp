#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, m;

int main()
{
	scanf("%d %d", &n, &m);
	bool ok = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char ch; scanf(" %c", &ch);
			if (ch == 'C' || ch == 'M' || ch == 'Y')
				ok = false;
		}
	}
	printf("%s\n", ok? "#Black&White": "#Color");
	return 0;
}