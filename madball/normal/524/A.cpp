#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<queue>
#include<math.h>
#include<deque>

#define ll long long
#define ld long double

using namespace std;

const int maxn = 205;
bool matrix[maxn][maxn];
int cnt = 0;
map<int, int> ids;
int num_to_id[maxn];
int percent;

int get_man_num(int id) {
	if (ids.count(id))
		return ids[id];
	num_to_id[cnt] = id;
	ids[id] = cnt++;
	return cnt - 1;
}

bool is_potential_friend(int a, int b) {
	int result_count = 0;
	int friends_count = 0;
	for (int i = 0; i < cnt; i++) {
		if (i == a || i == b)
			continue;
		if (matrix[a][i]) {
			friends_count++;
			if (matrix[i][b])
				result_count++;
		}
	}
	return friends_count * percent <= result_count * 100;
}

void solve() {
	int m;
	scanf("%d%d", &m, &percent);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		int a_num = get_man_num(a);
		int b_num = get_man_num(b);
		matrix[b_num][a_num] = matrix[a_num][b_num] = true;
	}
	for (auto id : ids) {
		int man_num = id.second;
		vector<int> result_ids;
		for (int i = 0; i < cnt; i++) {
			if (man_num == i || matrix[man_num][i])
				continue;
			if (is_potential_friend(man_num, i))
				result_ids.push_back(num_to_id[i]);
		}
		sort(result_ids.begin(), result_ids.end());
		printf("%d: %d ", id.first, (int)result_ids.size());
		for (int i = 0; i < (int)result_ids.size(); i++)
			printf("%d ", result_ids[i]);
		printf("\n");
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	solve();
}