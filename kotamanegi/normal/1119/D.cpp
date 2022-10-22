#define _CRT_SECUintRE_NO_WARNINGS
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
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
#include <map>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <assert.h>
#include <complex>
using namespace std;
#define eps 0.000000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define seg_size 65536*2
#define REP(i,n) for(long long i = 0;i < n;++i)
unsigned long xor128(void)
{
	static unsigned long x = time(NULL), y = 362436069, z = 521288629, w = 88675123;
	unsigned long t;
	t = (x ^ (x << 11)); x = y; y = z; z = w; return(w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
long long query_ans[400000];
int main() {
#define int long long
	int n;
	cin >> n;
	vector<long long> input;
	REP(i, n) {
		long long tmp;
		cin >> tmp;
		input.push_back(tmp);
	}
	sort(input.begin(), input.end());
	int query;
	cin >> query;
	vector<long long> nya;
	for (int i = 1; i < input.size(); ++i) {
		nya.push_back(input[i] - input[i - 1]);
	}
	if(nya.size() != 0)
	sort(nya.begin(), nya.end());
	long long ans = 0;
	REP(i, nya.size()) {
		ans += nya[i];
	}
	vector<pair<long long, long long>> que;
	for (long long qu = 0; qu < query;++qu){
		long long a, b;
		cin >> a >> b;
		long long c = b - a + 1;
		que.push_back(make_pair(c,qu));
	}
	sort(que.begin(), que.end());
	long long now_itr = (long long)nya.size() - 1;
	for (long long i = que.size()-1; i >= 0; --i) {
		while (now_itr != -1 && nya[now_itr] >= que[i].first) {
			ans -= nya[now_itr];
			now_itr--;
		}
		query_ans[que[i].second] = ans + (long long)((long long)nya.size() - now_itr) * que[i].first;
	}
	REP(i, que.size()) {
		cout << query_ans[i] << " ";
	}
	cout << endl;
}