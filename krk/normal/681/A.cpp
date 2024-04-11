#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
string s;

int main()
{
	scanf("%d", &n);
	while (n--) {
		cin >> s;
		int a, b; cin >> a >> b;
		if (a >= 2400 && a < b) { printf("YES\n"); return 0; }
	}
	printf("NO\n");
	return 0;
}