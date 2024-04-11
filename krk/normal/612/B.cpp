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

const int Maxn = 200005;

int n;
int pos[Maxn];
ll res;

int main() 
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		pos[a] = i;
	}
	for (int i = 1; i < n; i++)
		res += abs(pos[i] - pos[i + 1]);
	printf("%I64d\n", res);
    return 0;
}