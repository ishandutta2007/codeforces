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

const int Maxn = 500005;

char str[Maxn];
int n;
string s[Maxn];
int len[Maxn];

int main() 
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", str); s[i] = str;
		len[i] = s[i].length();
	}
	for (int i = n - 2; i >= 0; i--) {
		int p = 0;
		while (p < len[i] && p < len[i + 1] && s[i][p] == s[i + 1][p]) p++;
		if (p == len[i]) continue;
		if (p == len[i + 1]) { len[i] = len[i + 1]; continue; }
		if (s[i][p] < s[i + 1][p]) continue;
		len[i] = p;
	}
	for (int i = 0; i < n; i++)
		printf("%s\n", s[i].substr(0, len[i]).c_str());
    return 0;
}