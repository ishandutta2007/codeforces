#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int a, b;
vector <int> res;

int main()
{
	scanf("%d %d", &a, &b);
	while (a < b) {
		res.push_back(b);
		if (b % 2 == 0) b /= 2;
		else {
			b--;
			if (b % 10 != 0) { printf("NO\n"); return 0; }
			b /= 10;
		}
	}
	if (a != b) { printf("NO\n"); return 0; }
	res.push_back(a);
	printf("YES\n");
	printf("%d\n", res.size());
	for (int i = res.size() - 1; i >= 0; i--)
		printf("%d%c", res[i], i - 1 >= 0? ' ': '\n');
	return 0;
}