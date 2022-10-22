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
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
int deleted[2000000] = {};
int to_front[2000000] = {};
int to_back[2000000] = {};
int nexting(int now) {
	if (deleted[to_front[now]] == 0) return to_front[now];
	return to_front[now] = nexting(to_front[now]);
}
int backing(int now) {
	if (to_back[now] == -1|| deleted[to_back[now]] == 0) return to_back[now];
	return to_back[now] = backing(to_back[now]);
}
int main() {
	iostream::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	for (int i = 0;i < s.length();++i) {
		to_back[i] = i - 1;
		to_front[i] = i + 1;
	}
	queue<pair<int,int>> to_erase;
	for (int i = 0;i < s.length()-1;++i) {
		if (s[i] != s[i + 1]) {
			to_erase.push(make_pair(i, i + 1));
		}
	}
	int ans = 0;
	for (ans = 0;to_erase.empty() == false;++ans) {
		queue<int> to_search;
		while (to_erase.empty() == false) {
			pair<int, int> now = to_erase.front();
			to_erase.pop();
			if (deleted[now.first] == 0 || deleted[now.second] == 0) {
				to_search.push(now.first);
			}
			deleted[now.first] = 1;
			deleted[now.second] = 1;
		}
		while (to_search.empty() == false) {
			int now = to_search.front();
			to_search.pop();
			int ba = backing(now), go = nexting(now);
			if (ba != -1 && go != s.length()) {
				if (s[ba] != s[go]) {
					to_erase.push(make_pair(ba, go));
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}