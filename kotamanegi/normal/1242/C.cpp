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
#define eps 1e-5
#define LONG_INF 2000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144
#define REP(a,b) for(long long a = 0;a < b;++a)
#define int long long
vector<long long> inputs[15];
long long sum[15] = {};
int k;
vector<pair<int, vector<pair<int, int>>>> finding_ans[15];
map<long long, long long> where_is;
long long target = 0;
void searching(int now_itr) {
	//first -> jump itr
	//second -> ans
	if (sum[now_itr] == target) {
		vector<pair<int, int>> now_stock;
		now_stock.push_back(make_pair(inputs[now_itr][0], now_itr));
		finding_ans[now_itr].push_back(make_pair(1, now_stock));
		return;
	}
	REP(q, inputs[now_itr].size()) {
		long long now = target - (sum[now_itr] - inputs[now_itr][q]);
		long long gone = 0;
		int now_place = now_itr;
		vector<pair<int, int>> now_stock;
		while (now_place != now_itr || now_stock.empty() == true) {
			if (where_is.find(now) == where_is.end()) {
				gone = 0;
				break;
			}
			int next_go = where_is[now];
			if (next_go < now_itr) {
				gone = 0;
				break;
			}
			if ((gone & (1 << (next_go - now_itr))) != 0) {
				gone = 0;
				break;
			}
			gone += (1 << (next_go - now_itr));
			now_stock.push_back(make_pair(now, now_place));
			now = target - (sum[next_go] - now);
			now_place = next_go;
		}
		if (gone == 0) continue;
		if (now != target - (sum[now_itr] - inputs[now_itr][q])) continue;
		finding_ans[now_itr].push_back(make_pair(gone, now_stock));
	}
	return;
}

tuple<int,int,int> back_dp[120000];
#undef int
pair<int,int> ans[15] = {};
int main(){
#define int long long
	iostream::sync_with_stdio(false);
	cin >> k;
	REP(i, k) {
		long long n;
		cin >> n;
		REP(q, n) {
			long long a;
			cin >> a;
			where_is[a] = i;
			target += a;
			sum[i] += a;
			inputs[i].push_back(a);
		}
	}
	if (llabs(target) % k != 0) {
		cout << "No" << endl;
		return 0;
	}
	target /= k;
	REP(i, k) {
		searching(i);
		REP(q, finding_ans[i].size()) {
			finding_ans[i][q].first <<= i;
		}
	}
	REP(i, 120000) {
		back_dp[i] = make_tuple(-1,-1,-1);
	}
	back_dp[0] = make_tuple(0,-1, -1);
	REP(i, k) {
		REP(q, 1 << (k - i - 1)) {
			int hoge = (q << (1+i));
			hoge += (1 << i);
			hoge--;
			if (get<0>(back_dp[hoge]) == -1) continue;
			for (int j = 0; j < finding_ans[i].size(); ++j) {
				if ((hoge & finding_ans[i][j].first) == 0) {
					back_dp[hoge | finding_ans[i][j].first] = make_tuple(hoge, i, j);
				}
			}
		}
	}
	int going = (1 << k) - 1;
	if (get<0>(back_dp[going]) == -1) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	while (going != 0) {
		int next_go = get<0>(back_dp[going]);
		vector<pair<int, int>> tmp = finding_ans[get<1>(back_dp[going])][get<2>(back_dp[going])].second;
		REP(q, tmp.size()) {
			ans[where_is[tmp[q].first]] = make_pair(tmp[q].first,tmp[q].second);
		}
		going = next_go;
	}
	REP(i, k) {
		cout << ans[i].first << " " << ans[i].second+1 << endl;
	}
}