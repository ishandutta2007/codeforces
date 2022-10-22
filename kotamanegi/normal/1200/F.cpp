
/*

This Submission is to determine how many 120/240 min const. delivery point there are.

*/
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
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 2520
#define MOD 2520
#define seg_size 262144
#define REP(a,b) for(long long a = 0;a < b;++a)
unsigned long xor128() {
	static unsigned long x = time(NULL), y = 362436069, z = 521288629, w = 88675123;
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
long long cnt[2001][2531] = {};
long long visited[2001][2531] = {};
vector<long long> vertexs[2001];
long long written[2001];

long long done[2001];
vector<long long> now_going;
// BASE SHOULD BE 2520

long long deter_dfs(long long now, long long num) {
	if (done[now] == false) {
		now_going.push_back(now);
		done[now] = true;
	}
	visited[now][num] = 2;
	long long next_go = vertexs[now][num % vertexs[now].size()];
	long long next_num = (num + written[next_go]) % MOD;
	if (visited[next_go][next_num] == 2) {
		cnt[now][num] = now_going.size();
		return cnt[now][num];
	}
	return cnt[now][num] = deter_dfs(next_go, next_num);
}
long long base_dfs(long long now, long long num) {
	if (visited[now][num] == 2) return cnt[now][num];
	if (visited[now][num] == 1) return deter_dfs(now, num);
	visited[now][num] = 1;
	long long next_go = vertexs[now][num % vertexs[now].size()];
	long long next_num = (num + written[next_go]) % MOD;
	long long geko = base_dfs(next_go, next_num);
	visited[now][num] = 2;
	return cnt[now][num] = geko;
}
vector<pair<int, int>> next_visit;
int main() {
#define int long long
	iostream::sync_with_stdio(false);
	int n;
	cin >> n;
	REP(i, n) {
		cin >> written[i];
		written[i] %= MOD;
		written[i] += 2 * MOD;
		written[i] %= MOD;
	}
	REP(i, n) {
		long long a;
		cin >> a;
		REP(q, a) {
			long long b;
			cin >> b;
			b--;
			vertexs[i].push_back(b);
		}
	}
	int query;
	cin >> query;
	REP(i, query) {
		long long a, b;
		cin >> a >> b;
		a--;
		b += written[a];
		b %= MOD;
		b += MOD * 2;
		b %= MOD;
		next_visit.push_back(make_pair(a, b));
		long long now_ans = 0;
		while (true) {
			pair<int, int> now = next_visit[next_visit.size() - 1];
			if (visited[now.first][now.second] == 2) {
				now_ans = cnt[now.first][now.second];
				break;
			}
			else if (visited[now.first][now.second] == 1) {
				if (done[now.first] == false) {
					now_going.push_back(now.first);
					done[now.first] = true;
				}
				visited[now.first][now.second] = 2;
				long long next_go = vertexs[now.first][now.second % vertexs[now.first].size()];
				long long next_num = (now.second + written[next_go]) % MOD;
				if (visited[next_go][next_num] == 2) {
					now_ans = now_going.size();
					break;
				}
				else {
					next_visit.push_back(make_pair(next_go, next_num));
				}
			}
			else {
				visited[now.first][now.second] = 1;
				long long next_go = vertexs[now.first][now.second % vertexs[now.first].size()];
				long long next_num = (now.second + written[next_go]) % MOD;
				next_visit.push_back(make_pair(next_go, next_num));
			}
		}
		while (next_visit.empty() == false) {
			pair<int, int> now = next_visit[next_visit.size() - 1];
			visited[now.first][now.second] = 2;
			cnt[now.first][now.second] = now_ans;
			next_visit.pop_back();
		}
		cout << cnt[a][b] << endl;
		while (now_going.empty() == false) {
			done[now_going[now_going.size() - 1]] = 0;
			now_going.pop_back();
		}
	}
}