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

const int Maxn = 1005;

map <string, int> M;

int n, m;
char str[Maxn];
int a, b, c;

int main() 
{
	scanf("%d %d", &n, &m);
	while (n--) {
		scanf("%s", str); M[str] |= 1;
	}
	while (m--) {
		scanf("%s", str); M[str] |= 2;
	}
	for (map <string, int>::iterator it = M.begin(); it != M.end(); it++)
		if (it->second == 1) a++;
		else if (it->second == 2) b++;
		else c++;
	if (c % 2 == 0)
		printf("%s\n", a > b? "YES": "NO");
	else printf("%s\n", a >= b? "YES": "NO");

    return 0;
}