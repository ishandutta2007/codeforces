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
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
vector<int> vertexs[300000];
long long neko[300000];
vector<pair<long long, long long>> nexting[300000];
long long move(long long now, long long back) {
	long long cnt = 1;
	REP(i, vertexs[now].size()) {
		if (vertexs[now][i] != back) {
			long long geko = move(vertexs[now][i], now);
			cnt += geko;
			nexting[now].push_back(make_pair(vertexs[now][i], geko));
		}
	}
	return neko[now] = cnt;
}
long long n;
long long tree_dp(long long now, long long back, long long now_ans) {
	long long final_ans = now_ans;
	for (int q = 0; q < nexting[now].size(); ++q) {
		if (nexting[now][q].first != back) {
			long long pre_ans = now_ans - neko[nexting[now][q].first];
			pre_ans += n - nexting[now][q].second;
			final_ans = max(final_ans, tree_dp(nexting[now][q].first, now, pre_ans));
		}
	}
	return final_ans;
}
int main(){
#define int long long
	iostream::sync_with_stdio(false);
	cin >> n;
	REP(i, n - 1) {
		int a, b;
		cin >> a >> b;
		vertexs[a].push_back(b);
		vertexs[b].push_back(a);
	}
	move(1, -1);
	long long ans = 0;
	REP(i, n) {
		ans += neko[i + 1];
	}
	ans -= n;
	cout << tree_dp(1, -1, ans)+n << endl;
}