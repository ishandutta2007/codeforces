#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 1000005;

string s;
int best[Maxn];
int nil, one;

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin >> s;
	nil = 1;
	for (int i = 0; i < s.length(); i++) {
		best[i] = min(nil, one) + 1;
		if (s[i] == '0') nil = best[i];
		else one = best[i];
	}
	int lst = s.length() - 1;
	while (s[lst] == '0') lst--;
	printf("%d\n", best[lst]);
	return 0;
}