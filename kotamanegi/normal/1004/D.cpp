#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <assert.h>
using namespace std;
#define eps 0.000000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define seg_size 65536*4
#define REP(i,n) for(long long i = 0;i < n;++i)
int cnt[2000000] = {};
int grid[2000000] = {};
int pre_cnt[2000000] = {};
queue<int> gogo[2];
int main() {
	int t;
	scanf("%d", &t);
	int now_max = 0;
	REP(i, t) {
		int a;
		scanf("%d", &a);
		now_max = max(now_max, a);
		cnt[a]++;
	}
	if (cnt[0] != 1) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 1; i <= sqrt(t); ++i) {
		if (t % i == 0) {
			int h = i;
			int w = t / i;
			vector<int> swappings;
			swappings.push_back(h*w - 1);
			swappings.push_back(w*(h - 1));
			swappings.push_back(w - 1);
			sort(swappings.begin(), swappings.end());
			do {
				int failed = 0;
				for (int q = 0; q < 2; ++q) {
					while (gogo[q].empty() == false) gogo[q].pop();
				}
				for (int q = 0; q < t; ++q) {
					grid[q] = -1;
					pre_cnt[q] = 0;
				}
				vector<int> taking;
				int now_itr = 0;
				taking.push_back(0);
				taking.push_back(swappings[0]);
				taking.push_back(swappings[1]);
				taking.push_back(swappings[2]);
				for (int q = now_max; q >= 0; --q) {
					int now_moving = q % 2;
					while (gogo[now_moving].empty() == false) {
						int now = gogo[now_moving].front();
						gogo[now_moving].pop();
						int now_x = now / w;
						int now_y = now % w;
						if (now_x >= 1) {
							if (grid[(now_x - 1)*w + now_y] == -1) {
								grid[(now_x - 1) * w + now_y] = q;
								gogo[(now_moving + 1) % 2].push((now_x - 1) * w + now_y);
								pre_cnt[q]++;
							}
							else if (grid[(now_x - 1)*w + now_y] != q && grid[(now_x - 1)*w + now_y] != q + 2) {
								failed = 1;
								break;
							}
						}
						if (now_y >= 1) {
							if (grid[now_x * w + (now_y - 1)] == -1) {
								grid[now_x * w + (now_y - 1)] = q;
								gogo[(now_moving + 1) % 2].push(now_x * w + now_y - 1);
								pre_cnt[q]++;
							}
							else if (grid[now_x * w + (now_y - 1)] != q && grid[now_x * w + (now_y - 1)] != q + 2) {
								failed = 1;
								break;
							}
						}
						if (now_x + 1 < h) {
							if (grid[(now_x + 1) * w + now_y] == -1) {
								grid[(now_x + 1) * w + now_y] = q;
								gogo[(now_moving + 1) % 2].push((now_x + 1) * w + now_y);
								pre_cnt[q]++;
							}
							else if (grid[(now_x + 1) * w + now_y] != q && grid[(now_x + 1) * w + now_y] != q + 2) {
								failed = 1;
								break;
							}
						}
						if (now_y + 1 < w) {
							if (grid[now_x * w + now_y + 1] == -1) {
								grid[now_x * w + now_y + 1] = q;
								gogo[(now_moving + 1) % 2].push(now_x * w + now_y + 1);
								pre_cnt[q]++;
							}
							else if (grid[now_x * w + now_y + 1] != q && grid[now_x * w + now_y + 1] != q + 2) {
								failed = 1;
								break;
							}
						}
					}
					if (failed == 1) break;
					while (now_itr != 4 && pre_cnt[q] != cnt[q]) {
						if (grid[taking[now_itr]] == -1) {
							grid[taking[now_itr]] = q;
							pre_cnt[q]++;
							gogo[(now_moving + 1) % 2].push(taking[now_itr]);
						}
						now_itr++;
					}
					if (now_itr == 4&&pre_cnt[q] != cnt[q]) {
						failed = 1;
						break;
					}
				}
				if (failed == 0) {
					cout << h << " " << w << endl;
					for (int q = 0; q >= 0; ++q) {
						if (grid[q] == 0) {
							cout << q / w + 1 << " " << q % w + 1 << endl;
							return 0;
						}
					}
					return 0;
				}
			} while (next_permutation(swappings.begin(), swappings.end()));
		}
	}
	cout << -1 << endl;
	return 0;
}