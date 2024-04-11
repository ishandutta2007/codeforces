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

int n, m;
vector <vector <int> > A;
vector <vector <int> > dp;
vector <int> res;
int k;

int main() 
{
	scanf("%d %d", &n, &m);
	A.assign(n, vector <int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &A[i][j]);
	dp.assign(n, vector <int>(m));
	res.assign(n, -1);
	for (int j = 0; j < m; j++)
		dp[n - 1][j] = n - 1;
	res[n - 1] = n - 1;
	for (int i = n - 2; i >= 0; i--)
		for (int j = 0; j < m; j++) {
			dp[i][j] = A[i][j] <= A[i + 1][j]? dp[i + 1][j]: i;
			res[i] = max(res[i], dp[i][j]); 
		}
	scanf("%d", &k);
	while (k--) {
		int l, r; scanf("%d %d", &l, &r); l--; r--;
		if (res[l] >= r) printf("Yes\n");
		else printf("No\n");
	}
    return 0;
}