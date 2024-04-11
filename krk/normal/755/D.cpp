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

const int Maxn = 1000005;

int n, k;
int has[Maxn];
ll res;

void Insert(int x, int val)
{
	x++;
	for (int i = x; i <= n; i += i & -i)
		has[i] += val;
}

int Get(int x)
{
	x++;
	int res = 0;
	for (int i = x; i > 0; i -= i & -i)
		res += has[i];
	return res;
}

void InsertI(int l, int r)
{
	l = (l + 1) % n; r = (r - 1 + n) % n;
	if (l <= r) { Insert(l, 1); Insert(r + 1, -1); }
	else {
		Insert(l, 1); Insert(n, -1);
		Insert(0, 1); Insert(r + 1, -1);
	}
}

int main() 
{
	scanf("%d %d", &n, &k);
	if (k > n - k) k = n - k;
	res = 1;
	int lst = 0;
	do {
		int nxt = (lst + k) % n;
		int add = Get(lst);
		res += add + 1;
		printf("%I64d%c", res, nxt == 0? '\n': ' ');
		InsertI(lst, nxt);
		InsertI((lst - k + n) % n, lst);
		lst = nxt;
	} while (lst);
    return 0;
}