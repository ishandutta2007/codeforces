#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <functional>
#include <sstream>
#include <fstream>
#include <valarray>
#include <complex>
#include <queue>
#include <cassert>
#include <bitset>

#include <unordered_map>

using namespace std;

#ifdef LOCAL
#define debug_flag 1
#else
#define debug_flag 0
#endif

template <class T1, class T2 >
std::ostream& operator << (std::ostream& os, const pair<T1, T2> &p)
{
	os << "[" << p.first << ", " << p.second << "]";
	return os;
}

template <class T >
std::ostream& operator << (std::ostream& os, const std::vector<T>& v)
{
	os << "[";
	bool first = true;
	for (typename std::vector<T>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		if (!first)
			os << ", ";
		first = false;
		os << *it;
	}
	os << "]";
	return os;
}

template <class T >
std::ostream& operator << (std::ostream& os, const std::vector<vector<T>>& v)
{

	os << "[" << endl;
	bool first = true;
	for (typename std::vector<vector<T>>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		os << *it << endl;
	}
	os << "]" << endl;
	return os;
}

typedef long long int int64;

const int N = 105;
const int INF = (int)1e9;

int n;
int a_list[N], b_list[N];
int dp[N][N * N];

void relax_max(int &a, int b)
{
	a = max(a, b);
}

void solve()
{
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
		scanf("%d", &a_list[i]);

	for (int i = 0; i < n; i++)
		scanf("%d", &b_list[i]);

	int soda_amount = 0;
	for (int i = 0; i < n; i++)
		soda_amount += a_list[i];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N * N; j++)
		{
			dp[i][j] = -1;
		}
	}

	dp[0][0] = 0;
	for (int it = 0; it < n; it++)
	{
		for (int cnt = N - 1; cnt >= 0; cnt--)
		{
			for (int inner_soda = N * N - 1; inner_soda >= 0; inner_soda--)
			{
				int cur_dp = dp[cnt][inner_soda];
				if (cur_dp == -1)
					continue;

				relax_max(dp[cnt + 1][inner_soda + a_list[it]], cur_dp + b_list[it]);
			}
		}
	}

	pair<int, int> ans = make_pair(INF, INF);

	for (int cnt = 0; cnt < N; cnt++)
	{
		for (int inner_soda = 0; inner_soda < N * N; inner_soda++)
		{
			int cur_dp = dp[cnt][inner_soda];
			if (cur_dp == -1)
				continue;
			if (cur_dp >= soda_amount)
			{
				pair<int, int> cur_ans = make_pair(cnt, soda_amount - inner_soda);
				ans = min(ans, cur_ans);
			}
		}
	}

	printf("%d %d\n", ans.first, ans.second);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

	solve();

	return 0;
}