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

typedef long long ll;

const int Maxn = 300005;

char s[Maxn];
int slen;
ll res;

int main() 
{
	scanf("%s", s); slen = strlen(s);
	for (int i = 0; i < slen; i++) {
		if ((s[i] - '0') % 4 == 0) res++;
		if (i > 0 && (10 * (s[i - 1] - '0') + (s[i] - '0')) % 4 == 0) res += i;
	}
	printf("%I64d\n", res);
    return 0;
}