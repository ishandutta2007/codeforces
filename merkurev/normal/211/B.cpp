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

const int INF = (int)1e9;
const int N = (int)2e6 + 100;
const int ALP = 26;
const int M = (1 << ALP);

int len;
char str[N];
int q_cnt;
int q_list[N];

short mx[M];

int ans[N];
int prev_pos[ALP];

int pos_cnt;
pair<int, int> pos_list[2 * ALP];

int read_mask()
{
	char buf[100];
	scanf(" %s", buf);
	int cnt = strlen(buf);
	int mask = 0;
	for (int i = 0; i < cnt; i++)
		mask |= (1 << (buf[i] - 'a'));
	return mask;
}

bool bit(int mask, int pos)
{
	return (mask & (1 << pos)) != 0;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	scanf("%s", str);
	len = strlen(str);
	scanf("%d", &q_cnt);
	for (int i = 0; i < q_cnt; i++)
		q_list[i] = read_mask();

	int ptr = 0;
	for (int i = 0; i < q_cnt; i++)
	{
		int mask = q_list[i];
		if (mx[mask] == 0)
			mx[mask] = ++ptr;
	}

	for (int i = 0; i < ALP; i++)
		prev_pos[i] = INF;
	
	for (int l = len - 1; l >= 0; l--)
	{
		prev_pos[(int)(str[l] - 'a')] = l;
		pos_cnt = 0;
		for (int i = 0; i < ALP; i++)	
		{
			if (prev_pos[i] == INF)
				continue;
			pos_list[pos_cnt++] = make_pair(prev_pos[i], i);
		}

		sort(pos_list, pos_list + pos_cnt);
		int cur_mask = 0;
		for (int i = 0; i < pos_cnt; i++)
		{
			cur_mask |= (1 << pos_list[i].second);
			bool good = true;
			if (l != 0 && bit(cur_mask, (int)(str[l - 1] - 'a')))
				good = false;
			int ans_ind = mx[cur_mask];

			if (good)
				ans[ans_ind]++;
		}
	}

	for (int i = 0; i < q_cnt; i++)
		printf("%d\n", ans[mx[q_list[i]]]);

	return 0;
}