#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int N = 5e4 + 100;
const int K = 102;
const int A = 26;

int n;
char str[N];
int dp[N][K];
int ans_par[N][K];
pair<int, int> dp_par[N][K];
int first_to_l[N][A], first_to_r[N][A];

void relax_dp(int i, int len, int new_val, int ap, pair<int, int> dpp)
{
	if (len > 100)
		return;

	if (dp[i][len] < new_val)
	{
		dp[i][len] = new_val;
		ans_par[i][len] = ap;
		dp_par[i][len] = dpp;
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	scanf("%s", str);
	n = strlen(str);

	for (char c = 'a'; c <= 'z'; c++)
	{
		int prev = -1;
		for (int i = 0; i < n; i++)
		{
			if (str[i] == c)
				prev = i;
			first_to_l[i][(int)(c - 'a')] = prev;
		}

		prev = n;
		for (int i = n - 1; i >= 0; i--)
		{
			if (str[i] == c)
				prev = i;
			first_to_r[i][(int)(c - 'a')] = prev;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			dp[i][j] = -1;
			ans_par[i][j] = -1;
			dp_par[i][j] = make_pair(-1, -1);
		}
	}

	for (int c = 0; c < A; c++)
	{
		int l = first_to_r[0][c];
		int r = first_to_l[n - 1][c];
		eprintf("c = %d l = %d r = %d\n", c, l, r);
		if (l < r)
			relax_dp(l, 2, r, c, make_pair(-1, -1));
		else
			relax_dp(l, 1, r, c, make_pair(-1, -1));
	}

	for (int len = 1; len < 100; len++)
	{
		for (int i = 0; i < n; i++)
		{
			int r = dp[i][len];
			if (r == -1)
				continue;
			
			if (i == r)
				continue;

			for (int c = 0; c < A; c++)
			{
				int p1 = first_to_r[i + 1][c];
				int p2 = first_to_l[r - 1][c];
				
				if (p2 <= i || p1 >= r)
					continue;

				if (p1 < p2)
					relax_dp(p1, len + 2, p2, c, make_pair(i, len));
				else
					relax_dp(p1, len + 1, p2, c, make_pair(i, len));
			}
		}
	}

	int best_ans = -1;
	pair<int, int> best_dp = make_pair(-1, -1);
	for (int i = 0; i < n; i++)
	{
		for (int len = 0; len <= 100; len++)
		{
			if (dp[i][len] == -1 || len < best_ans)
				continue;
			best_ans = len;
			best_dp = make_pair(i, len);
		}
	}

	eprintf("best_ans = %d\n", best_ans);
	eprintf("best_dp = {%d, %d}\n", best_dp.first, best_dp.second);

	string rs;
	while (best_dp.first != -1)
	{
		rs.push_back((char)('a' + ans_par[best_dp.first][best_dp.second]));
		best_dp = dp_par[best_dp.first][best_dp.second];
	}

	string ls = rs;
	reverse(ls.begin(), ls.end());
	if (best_ans % 2 == 1)
		ls.pop_back();

	string ans = ls + rs;

	cout << ans << endl;

	return 0;
}