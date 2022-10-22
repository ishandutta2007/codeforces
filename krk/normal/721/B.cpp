#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n, k;
int has[Maxn];

int main()
{
	scanf("%d %d", &n, &k);
	while (n--) {
		string s; cin >> s;
		has[s.length()]++;
	}
	string s; cin >> s;
	int res = 0;
	for (int i = 0; i < s.length(); i++)
		res += has[i];
	printf("%d %d\n", res + 1 + res / k * 5, res + has[s.length()] + (res + has[s.length()] - 1) / k * 5);
	return 0;
}