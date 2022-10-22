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
#define LONG_INF 1000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144*4
#define REP(a,b) for(long long a = 0;a < b;++a)
vector<pair<long long, long long>> vertexs[1000000];
int n, k;
pair<long long, long long> dfs(int now,int back){
	vector<pair<long long, long long>> go;
	long long basing = 0;
	REP(i, vertexs[now].size()) {
		int next = vertexs[now][i].first;
		if (next == back) continue;
		go.push_back(dfs(next, now));
		go.back().first += vertexs[now][i].second;
		basing += go.back().second;
	}
	vector<long long> changing;
	REP(i, go.size()) {
		if (go[i].first > go[i].second) {
			changing.push_back(go[i].first - go[i].second);
		}
	}
	sort(changing.begin(), changing.end());
	reverse(changing.begin(), changing.end());
	pair<long long, long long> ans = make_pair(basing, basing);
	for (int i = 0; i < k && i < changing.size(); ++i) {
		basing += changing[i];
		ans.second = max(ans.second, basing);
		if (i + 1 < k) {
			ans.first = max(ans.first, basing);
		}
	}
	return ans;
}
int main() {
#define int long long
	iostream::sync_with_stdio(false);
	int query;
	cin >> query;
	REP(tea, query) {
		cin >> n >> k;
		REP(i, n) {
			vertexs[i].clear();
		}
		REP(i, n - 1) {
			long long a, b, c;
			cin >> a >> b >> c;
			a--; b--;
			vertexs[a].push_back(make_pair(b,c));
			vertexs[b].push_back(make_pair(a, c));
		}
		cout << dfs(0, -1).second << endl;
	}
}