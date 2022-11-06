#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
using namespace std;

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); i ++)
#define pb(e) push_back(e)
#define mp make_pair

typedef long long ll;

const ll INF = 1LL << 40;

int L;
ll A[160];
char S[160];

ll mem[160][160][160];

ll find(int l, int r, int d) 
{
	if (l == r) return A[d];
	if (mem[l][r][d] != -1) return mem[l][r][d];

	ll res = -INF;

	if (d > 0) 
	{
		ll tmp = A[d] + find(l, r, 0);
		res = max(res, tmp);
	}

	{
		ll tmp = A[d + 1] + find(l + 1, r, 0);
		res = max(res, tmp);
	}

	for (int i = l + 1; i < r; i ++) 
	{
		if (S[l] != S[i]) continue;
		res = max(res, find(l + 1, i, d + 2) + find(i + 1, r, 0));
	}

	for (int i = l + 1; i < r; i ++) 
		res = max(res, find(l, i, 0) + find(i, r, d));

	return mem[l][r][d] = res;
}



int main() 
{
	while (cin >> L)
	{
		A[0] = 0;
		for (int i = 1; i <= L; i ++) 
		{
			cin >> A[i];
			if (A[i] == -1) A[i] = -INF;
		}

		cin >> S;

		memset(mem, -1, sizeof(mem));

		ll dp[160] = {};
		for (int r = 1; r <= L; ++r) 
		{
			dp[r] = dp[r - 1];
			for (int l = 0; l < r; ++l) 
				dp[r] = max(dp[r], dp[l] + find(l, r, 0));
		}
		cout << dp[L] << endl;
	}

	return 0;
}