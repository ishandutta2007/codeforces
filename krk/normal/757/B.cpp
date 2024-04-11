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

int n;
int has[Maxn];
int res = 1;

int main() 
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		has[a]++;
	}
	for (int i = 2; i < Maxn; i++) {
		int cand = 0;
		for (int j = i; j < Maxn; j += i)
			cand += has[j];
		res = max(res, cand);
	}
	printf("%d\n", res);
    return 0;
}