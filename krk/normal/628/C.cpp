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

const int Maxn = 100005;

int n, k;
char s[Maxn], my[Maxn];

int main() 
{
	scanf("%d %d", &n, &k);
	scanf("%s", s);
	for (int i = 0; i < n; i++)
		if (s[i] - 'a' > 'z' - s[i])
			if (s[i] - 'a' <= k) { my[i] = 'a'; k -= (s[i] - 'a'); }
			else { my[i] = s[i] - k; k = 0; }
		else if ('z' - s[i] <= k) { my[i] = 'z'; k -= ('z' - s[i]); }
			 else { my[i] = s[i] + k; k = 0; }
	if (k > 0) printf("-1\n");
	else {
		my[n] = '\0';
		printf("%s\n", my);
	}
    return 0;
}